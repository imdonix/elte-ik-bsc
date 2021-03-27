package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.*;

import java.util.ArrayDeque;
import java.util.Queue;

public abstract class Game extends Building
{
    public static final float DESTROY_RELEASE_PENALTY = -.3f;
    public static final float DMG_MAX = 1F;
    public static final float DMG_MIN = .5F;

    private final Queue <Visitor> queue;
    private final int max;
    private float timer;
    private boolean playing;
    private int useCost;

    public Game(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max, int useCost) {
        super(world, sprite, position, size);
        this.queue = new ArrayDeque<Visitor>();
        this.max = max;
        this.useCost = useCost;
        this.playing = false;
    }

    public void setUseCost(int useCost)
    {
        this.useCost = useCost;
    }

    public int getUseCost()
    {
        return useCost;
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

    private void reset()
    {
        this.sprite.setState(AnimatedSprite.IDLE);
        this.setOpened(true);
        this.playing = false;
        releaseVisitors(false);
    }

    private void gameStart()
    {
        this.sprite.setState(AnimatedSprite.GAME_PLAY);
        this.setOpened(false);
        this.playing = true;
        this.timer = 0F;
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

    @Override
    protected void damage(float dmg) {
        super.damage(dmg);
    }
}
