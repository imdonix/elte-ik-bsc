package hu.elte.madtycoon.objects.entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.task.employee.FindDirtyRoad;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;
import java.util.LinkedList;
import java.util.List;

public class Cleaner extends Worker {

    public static int START_MONEY = 100;

    public static float START_FOOD = 1f;
    public static float START_INT = 1f;

    public static float MIN_MS_SPEED = 1F;
    public static float MAX_MS_SPEED = 2F;

    public static int MIN_SALARY = 25;
    public static int MAX_SALARY = 50;

    private final float movementSpeed;

    private Cleaner(World world, AnimatedSprite sprite, Vector2F position) {
        super(world, sprite, position, Random.getRandomInt(MIN_SALARY,MAX_SALARY));
        this.money = START_MONEY;
        this.food = START_FOOD;
        this.interest = START_INT;
        this.movementSpeed = Random.getRandomFloat(MIN_MS_SPEED, MAX_MS_SPEED);
    }

    @Override
    public float getMovementSpeed()
    {
        return movementSpeed;
    }

    @Override
    protected void start() {}

    @Override
    public void onDestroy() { }

    @Override
    protected Task getNewTask()
    {
        List<Road> roads = getRoadsWithLowHealth();

        if(roads.size() > 0)
            return new FindDirtyRoad(this, findNearestRoad(roads));
        else
        {
            System.out.println(String.format("%s can't be employed!", this));
            return super.getNewTask();
        }
    }

    @Override
    public String getTypeName()
    {
        return "Cleaner";
    }

    private List<Road> getRoadsWithLowHealth()
    {
        List<Road> tmp = new LinkedList<>();
        for(Road road : world.getRoads())
            if(road.isDirty() && road.getEmployee() == null)
                tmp.add(road);

        return tmp;
    }

    protected Road findNearestRoad(List<Road> roads)
    {
        Road min = roads.get(0);
        for(Road road : roads)
            if(min.getPosition().distance(getPosition()) > road.getPosition().distance(getPosition()))
                min = road;
        return min;
    }

    public static Cleaner Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("cleaner_idle");
        BufferedImage[] walk = AnimationResource.Instance.get("cleaner_walk");
        BufferedImage[] cleaning = AnimationResource.Instance.get("cleaner_clean");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.25f);
        anim.addState(AnimatedSprite.WALK, walk);
        anim.addState(AnimatedSprite.CLEAN, cleaning);
        return new Cleaner(world, anim, position);
    }
}
