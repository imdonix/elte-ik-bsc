package hu.elte.madtycoon.objects.Entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.task.GoRandomPlace;
import hu.elte.madtycoon.task.Idle;
import hu.elte.madtycoon.task.LeavePark;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;

public class Visitor extends Entity
{

    public static int START_MONEY_MIN = 200;
    public static int START_MONEY_MAX = 500;
    public static float START_FOOD_MIN = 0.65f;
    public static float START_FOOD_MAX = 0.8f;
    public static float START_INT_MIN = 0.2f;
    public static float START_INT_MAX = 0.5f;

    private Visitor(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
        this.money = Random.getRandomInt(START_MONEY_MIN, START_MONEY_MAX);
        this.food = Random.getRandomFloat(START_FOOD_MIN, START_FOOD_MAX);
        this.interest = Random.getRandomFloat(START_INT_MIN, START_INT_MAX);
    }

    @Override
    protected void start()
    {
        if(world.getEntranceCost() > money / 2)
            task = new LeavePark(this, world);
        else
            pay(world.getEntranceCost());

    }

    @Override
    protected Task getNewTask() {
        return Random.getRandomInt(0, 10) > 5 ? new GoRandomPlace(this) : new Idle(this);
    }

    @Override
    public float getMovementSpeed()
    {
        return 2;
    }



    public static Visitor CreateNewVisitor(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("visitor_idle");
        BufferedImage[] walk = AnimationResource.Instance.get("visitor_walk");
        AnimatedSprite anim = new AnimatedSprite("idle", idle, 0.25f);
        anim.addState("walk", walk);
        return new Visitor(world, anim, position);
    }
}
