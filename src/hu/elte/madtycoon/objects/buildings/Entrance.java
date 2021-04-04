package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.ui.components.building.DecorationComponent;
import hu.elte.madtycoon.ui.components.building.OpenComponent;
import hu.elte.madtycoon.ui.components.building.SetComponent;
import hu.elte.madtycoon.ui.components.ToggleComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Entrance extends Building
{
    public static final Vector2I SIZE = new Vector2I(6,7);
    public static final Vector2I ENTRANCE = new Vector2I(-1,1);
    public static final int MAX_VISITOR_IN_PARK = 500; //Max visitor at decoration level 5
    public static final float SPAWN_TIME_AT_MAX = 7.5F;

    public static int DEFAULT_ENTRANCE_COST = 50;
    public static int MIN_ENTRANCE_COST = 0;
    public static int MAX_ENTRANCE_COST = 200;

    private float timer;
    private int entranceCost;


    private Entrance(World world, AnimatedSprite sprite)
    {
        super(world, sprite, new Vector2F(World.ENTRANCE_POINT).add(new Vector2F(SIZE).mul(1/2F).mul(-1)), SIZE);
        this.timer = 0;
        this.entranceCost = DEFAULT_ENTRANCE_COST;
        this.constructed = true;
    }

    public int getEntranceCost()
    {
        return entranceCost;
    }

    public void setEntranceCost(int entranceCost)
    {
        this.entranceCost = Utils.clamp(MIN_ENTRANCE_COST, MAX_ENTRANCE_COST, entranceCost);
    }

    @Override
    protected void start()
    {
        //Coroutines needed to spawn coz we cant update the buildings list while inside the loop
        world.getCoroutines().schedule(0, () -> world.instantiate(Road.Create(world, getTargetPosition())));
    }

    @Override
    public float getDecorationValue() { return .5F; }


    @Override
    public void update(float dt)
    {
        super.update(dt);
        timer+=dt;
        spawn();
    }

    @Override
    public Vector2F getTargetPosition()
    {
        return super.getTargetPosition().add(new Vector2F(ENTRANCE));
    }

    @Override
    public void onDestroy()
    {
        //TODO add prevent destroy
    }

    @Override
    public String getName() { return "Entrance"; }


    @Override
    public Preview getPreview() {
        Preview preview = new Preview(getName());
        preview.addContent(new OpenComponent(this));
        preview.addContent(new DecorationComponent(this));
        preview.addContent(new SetComponent("Entrance cost", this::getEntranceCost, this::setEntranceCost));
        preview.addAction(new ToggleComponent(Resources.Instance.openCloseButton, this::isOpened, this::setOpened));
        return preview;
    }

    private void spawn()
    {
        float decor = world.getDecoration();
        float happiness = Utils.clamp(1.5F, 3F, world.getHappiness() * 3F);
        int max = Utils.clamp(0, MAX_VISITOR_IN_PARK , (int) (((float) countAvailableGameSlots())*happiness));

        System.out.println(countAvailableGameSlots()*happiness);

        if(timer > SPAWN_TIME_AT_MAX / decor)
            if(isOpened())
                if(max > world.getVisitors().size())
                {
                    world.instantiate(Visitor.Create(world, getTargetPosition()));
                    timer = 0;
                }
    }


    private int countAvailableGameSlots()
    {
        int c = 0;
        for(Game game : world.getGames())
            c += game.getSlots();
        return c;
    }

    public static Entrance Create(World world)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("gate_idle");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 99f);
        return new Entrance(world, anim);
    }
}
