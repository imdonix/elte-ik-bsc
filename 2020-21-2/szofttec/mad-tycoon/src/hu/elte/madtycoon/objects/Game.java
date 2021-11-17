package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.Sounds;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.ui.components.ToggleComponent;
import hu.elte.madtycoon.ui.components.building.*;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.*;

import java.net.URL;
import java.util.ArrayDeque;
import java.util.Queue;

public abstract class Game extends Building
{
    public static final float DESTROY_RELEASE_PENALTY = -.3f;
    public static final float DMG_MAX = .1F;
    public static final float DMG_MIN = .05F;

    private final Queue <Visitor> queue;
    private final int max;
    private float timer;
    private boolean playing;
    protected int useCost;

    public Game(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max, int useCost) {
        super(world, sprite, position, size);
        this.queue = new ArrayDeque<Visitor>();
        this.max = max;
        this.useCost = useCost;
        this.playing = false;
    }

    public void setUseCost(int useCost)
    {
        this.useCost = Utils.clamp(20, 200, useCost);
    }

    public int getUseCost()
    {
        return useCost;
    }

    public int getSlots(){ return max; }

    public int getVisitorsCount()
    {
        return queue.size();
    }

    protected Visitor[] getPlayers()
    {
        return queue.toArray(new Visitor[max]);
    }

    public void enter(Visitor visitor) throws GameFullException, NoCoverageException, GameUnderConstruction, BuildingDestroyed {
        if(queue.size() >= max) throw new GameFullException();
        if(!visitor.pay(getUseCost())) throw new NoCoverageException();
        if(!isWorking()) throw new GameUnderConstruction();
        if(!getActive()) throw new BuildingDestroyed();
        world.getEmotes().pop(this, AnimatedSprite.PARK_EARN);
        queue.add(visitor);
        visitor.setActive(false);
    }

    @Override
    public void update(float dt)
    {
        super.update(dt);
        timer += dt;

        if(playing)
        {
            if(timer > getPlayPeriod())
            {
                reward();
                reset();
                damage(Random.getRandomFloat(DMG_MIN, DMG_MAX));
            }
        }
        else
        {
            if (queue.size() == max)
                gameStart();
        }
    }

    @Override
    public void onDestroy()
    {
        releaseVisitors(true);
    }

    @Override
    public boolean isWorking() {
        return super.isWorking() && !playing;
    }

    @Override
    public Preview getPreview() {
        Preview preview = super.getPreview();
        preview.addContent(new SetComponent("Use cost", this::getUseCost, this::setUseCost));
        preview.addContent(new OpenComponent(this));
        preview.addContent(new WorkingComponent(this));
        preview.addContent(new InGameComponent(this));
        preview.addAction(new ToggleComponent(this::isOpened, this::setOpened));
        return preview;
    }

    private void reset()
    {
        this.sprite.setState(AnimatedSprite.IDLE);
        this.playing = false;
        releaseVisitors(false);
    }

    private void gameStart()
    {
        this.sprite.setState(AnimatedSprite.GAME_PLAY);
        this.playing = true;
        this.timer = 0F;
        Sounds.play(getGameAudioClip());
    }

    private void releaseVisitors(boolean forced)
    {
        for(Visitor visitor : queue)
        {
            visitor.addVisited(this);
            visitor.setActive(true);
            if(forced) visitor.addInterest(DESTROY_RELEASE_PENALTY);
        }
        queue.clear();
    }

    protected abstract void reward();

    protected abstract float getPlayPeriod();

    protected abstract URL getGameAudioClip();

}
