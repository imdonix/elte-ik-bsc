package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.objects.entities.Cleaner;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.*;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

import java.awt.image.BufferedImage;

public class Road extends Building
{
    public static final float MAX_DIRT_PER_STEP = 0.004F; //6% per step
    public static final float MIN_DIRT_PER_STEP = 0.002F;//2% per step
    public static final String ID = "road";
    public static final int PRICE = 25;
    public static final float DIRTY = 0.5F;

    private Road(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position, Vector2I.ONE);
    }

    @Override
    protected int getRenderLayer() { return 0;}

    @Override
    public float getDecorationValue()
    {
        return (1 - health) / -35;
    }

    @Override
    public void onDestroy() {}

    @Override
    protected void start()
    {
        //TODO We want to ignore the construction for now
    }

    @Override
    public String getName() { return "Road"; }

    @Override
    protected void damage(float dmg)
    {
        health = Utils.clamp(0,1, health - dmg);
        if(health < DIRTY)
            getSprite().setState(AnimatedSprite.ROAD_DIRTY);
    }

    @Override
    public void repair(Worker worker)
    {
        System.out.println("Road is cleaned!");
        this.health = 1F;
        this.getEmployee().earn(this.getEmployee().getSalary());
        this.getSprite().setState(AnimatedSprite.IDLE);
        this.setEmployee(null);
    }

    public void clean(Cleaner worker) throws JobAlreadyTaken
    {
        if (this.getEmployee() != null) throw new JobAlreadyTaken();
        if (this.health > DIRTY) throw new JobAlreadyTaken();
        this.setEmployee(worker);
    }

    public boolean isInside()
    {
        int x = (int) position.x;
        int y = (int) position.y;

        return x >=0 && x < Engine.GAME_SIZE_X && y >= 0 && y < Engine.GAME_SIZE_Y;
    }

    public void dirty()
    {
        damage(Random.getRandomFloat(MIN_DIRT_PER_STEP, MAX_DIRT_PER_STEP));
    }

    public boolean isDirty() { return this.health < DIRTY; }



    public static Road Create(World world, Vector2F pos)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("road_idle");
        BufferedImage[] dirty = AnimationResource.Instance.get("road_dirty");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 1f);
        anim.addState(AnimatedSprite.ROAD_DIRTY, dirty);
        return new Road(world, anim, pos);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(Vector2I.ONE, PRICE, Road::Create));
    }
}
