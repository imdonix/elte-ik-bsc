package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.List;

public abstract class Entity extends GameObject {

    public static final Vector2F SIZE = new Vector2F(.5F, 1F);
    public static final Vector2F FOOD_REQ = new Vector2F(0.002f, 0.005f); // 2-5 per sec
    public static final Vector2F INT_REQ = new Vector2F(0.001f, 0.002f); // 1-2 per sec
    public static final float EMOTE_TH = 0.05F;

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

        if(interest > EMOTE_TH)
            world.getEmotes().pop(this, AnimatedSprite.VISITOR_HAPPY);
        else if(interest < -EMOTE_TH)
            world.getEmotes().pop(this, AnimatedSprite.VISITOR_SAD);

        this.interest += interest;
        this.interest = Utils.clap(0,1,this.interest);
    }

    public void addFood(float food)
    {
        if(food > EMOTE_TH)
            world.getEmotes().pop(this, AnimatedSprite.VISITOR_FOOD);

        this.food += food;
        this.food = Utils.clap(0,1,this.food);
    }

    @Override
    public void update(float dt)
    {
        super.update(dt);

        if(task == null || task.isDone())
            task = getNewTask();

        task.update(dt);
        requirements(dt);
    }

    private void requirements(float dt)
    {
        addFood(-Random.getRandomFloat(FOOD_REQ.x, FOOD_REQ.y) * dt);
        addInterest(-Random.getRandomFloat(INT_REQ.x, INT_REQ.y) * dt);
    }

    public float getHappiness()
    {
        return (interest + food) / 2;
    }

    public String getName()
    {
        return name;
    }

    public World getWorld()
    {
        return world;
    }

    public boolean pay(int money)
    {
        if(this.money < money)
            return false;

        this.money -= money;
        world.earn(money);
        return true;
    }

    public void earn(int money)
    {
        world.getEmotes().pop(this, AnimatedSprite.VISITOR_EARN);
        this.money += money;
        world.pay(money);
    }

    public void move(Vector2F dir, float dt)
    {
        Vector2F force = dir.normalized().mul(dt * getMovementSpeed());
        if(force.length() > dir.length()) force = dir;
        position = position.add(force);
    }

    public void setTask(Task task)
    {
        this.task = task;
    }

    @Override
    public Vector2F getRenderPosition()
    {
        return getPosition().add(SIZE.mul(-.5F));
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
