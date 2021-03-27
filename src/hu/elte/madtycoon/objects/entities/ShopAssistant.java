package hu.elte.madtycoon.objects.entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.Worker;
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

public class ShopAssistant extends Worker {

    public static int START_MONEY = 250;
    public static float START_FOOD = 1f;
    public static float START_INT = 1f;
    public static float MIN_MS_SPEED = 1.5F;
    public static float MAX_MS_SPEED = 3F;
    public static float SALARY = 0.6F;

    private final float movementSpeed;
    private final List<Game> visited;

    private ShopAssistant(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position, SALARY);
        this.money = START_MONEY;
        this.food = START_FOOD;
        this.interest = START_INT;
        this.movementSpeed = Random.getRandomFloat(MIN_MS_SPEED, MAX_MS_SPEED);
        this.visited = new LinkedList<>();
    }

    public void addVisited(Game game)
    {
        visited.add(game);
    }

    @Override
    protected void start() {}

    @Override
    public float getMovementSpeed()
    {
        return movementSpeed;
    }

    @Override
    protected Task getNewTask()
    {
        List<Shop> shops = getShopsWithJob();

        System.out.println(shops.size());

        if(shops.size() > 0)
        {
            return new Work(this, findNearestShop(shops));
        }
        else
        {
            System.out.println(String.format("%s can't be employed!", this));
            return new LeavePark(this);
        }
    }

    @Override
    public void onDestroy() { }

    private List<Shop> getShopsWithJob()
    {
        List<Shop> tmp = new LinkedList<>();
        for(Shop shop : world.getShops())
            if(shop.getEmployee() == null)
                tmp.add(shop);
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
