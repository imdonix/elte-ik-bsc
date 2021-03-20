package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.List;

public abstract class Entity extends GameObject {

    public static final Vector2F SIZE = new Vector2F(.5F, 1F);

    private static int idCounter = 0;

    protected final int id;
    protected final String name;
    protected float interest;
    protected float food;
    protected int money;
    protected Task task;

    protected Entity(World world, AnimatedSprite sprite, Vector2F position) {
        super(world, sprite, position);
        this.name = getRandomName();
        this.task = null;
        this.id = Entity.idCounter++;
    }

    public void addInterest(float interest)
    {
        //TODO pop happy | sad emote (if amount large enough)
        this.interest += interest;
    }

    public void addFood(float food)
    {
        //TODO pop happy | sad emote (if amount large enough)
        this.food += food;
    }

    @Override
    public void update(float dt)
    {
        super.update(dt);

        if(task == null || task.isDone())
            task = getNewTask();

        task.update(dt);
    }

    public float getHappiness()
    {
        return (interest + food) / 2;
    }

    public String getName()
    {
        return name;
    }


    public boolean pay(int money)
    {
        if(this.money < money)
            return false;

        //TODO pop pay emote
        this.money -= money;
        world.earn(money);
        return true;
    }

    public void earn(int money)
    {
        this.money += money;
        world.pay(money);
    }

    public void move(Vector2F dir, float dt)
    {
        Vector2F force = dir.normalized().mul(dt * getMovementSpeed());
        if(force.length() > dir.length()) force = dir;
        position = position.add(force);
    }

    @Override
    public Vector2F getRenderPosition()
    {
        return getPosition().add(SIZE.mul(0.5F));
    }

    @Override
    protected int getRenderLayer()
    {
        return 1;
    }

    @Override
    public String toString()
    {
        return String.format("[%d] %s (I: %f, F: %f, M: %d)", id, name, interest, food, money);
    }

    protected abstract void start();

    protected abstract Task getNewTask();

    protected abstract float getMovementSpeed();



    private static String getRandomName()
    {
        final List<String> names = Resources.Instance.entityNames;
        return names.get(Random.getRandomInt(0, names.size()));
    }
}
