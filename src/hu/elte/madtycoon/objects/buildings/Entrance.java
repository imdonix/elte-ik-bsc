package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Entrance extends Building
{
    public static final Vector2I SIZE = new Vector2I(6,7);
    public static final Vector2I ENTRANCE = new Vector2I(-1,1);
    public static final int MVPD = 500;//Max visitor at decoration level 5
    public static final int MVSPM = 25; // Max visitor spawn per minute at decoration level 5
    public static final float SPAWN_TIME = 60/10F;

    private float timer;



    private Entrance(World world, AnimatedSprite sprite)
    {
        super(world, sprite, new Vector2F(World.ENTRANCE_POINT).add(new Vector2F(SIZE).mul(1/2F).mul(-1)), SIZE);
        this.timer = 0;
    }

    @Override
    protected void start()
    {
        //Coroutines needed to spawn coz we cant update the entities list while inside the loop
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

    private void spawn()
    {
        if(timer >  SPAWN_TIME)
        {
            float decor = world.getDecoration() / 5F;
            int max = (int) (MVPD  * decor);
            int visitorToSpawn = (int) (MVSPM * decor);
            int visitorCount = world.getVisitors().size();

            if(visitorToSpawn + visitorCount > max)
                visitorToSpawn = max - visitorCount;

            for (int i = 0; i < visitorToSpawn; i++)
                world.instantiate(Visitor.Create(world, getTargetPosition()));

            timer = 0;
        }
    }


    public static Entrance Create(World world)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("gate_idle");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 99f);
        return new Entrance(world, anim);
    }
}
