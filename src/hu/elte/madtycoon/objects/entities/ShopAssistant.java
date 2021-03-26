package hu.elte.madtycoon.objects.entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.task.employee.Work;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;
import java.util.LinkedList;
import java.util.List;

public class ShopAssistant extends Entity {

    public static int START_MONEY_MIN = 500;
    public static int START_MONEY_MAX = 500;
    public static float START_FOOD_MIN = 0.65f;
    public static float START_FOOD_MAX = 0.8f;
    public static float START_INT_MIN = 0.2f;
    public static float START_INT_MAX = 0.5f;
    public static float MIN_MS_SPEED = 1F;
    public static float MAX_MS_SPEED = 2F;

    private final float movementSpeed;
    private final List<Game> visited;

    private ShopAssistant(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
        this.money = 500;
        this.food = 500;
        this.interest = 500;
        this.movementSpeed = Random.getRandomFloat(MIN_MS_SPEED, MAX_MS_SPEED);
        this.visited = new LinkedList<>();
    }

    public void addVisited(Game game)
    {
        visited.add(game);
    }

    @Override
    protected void start()
    {
        if(world.getEntranceCost() > money / 2)
            task = new LeavePark(this);
        else
            pay(world.getEntranceCost());
    }

    @Override
    public float getMovementSpeed()
    {
        return movementSpeed;
    }

    @Override
    protected Task getNewTask()
    {
        if(getShop().size()>0) {
            return new Work(this, getShop().get(0));
        }else{
            return new LeavePark(this);
        }
    }

    @Override
    public void onDestroy() { }


    private List<Shop> getShop()
    {
        List<Shop> tmp = new LinkedList<>(world.getShops());
        return tmp;
    }


    public static ShopAssistant Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("assistant_idle");
        BufferedImage[] walk = AnimationResource.Instance.get("assistant_walk");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.25f);
        anim.addState(AnimatedSprite.WALK, walk);
        return new ShopAssistant(world, anim, position);
    }
}
