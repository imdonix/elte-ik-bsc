package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.ITargetable;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.List;

public abstract class Entity extends GameObject {
    protected final String name;
    protected float interest;
    protected float food;
    protected int money;
    protected Task task;

    protected Entity(World world, AnimatedSprite sprite, Vector2F position) {
        super(world, sprite, position);
        this.name = getRandomName();
        this.task = null;
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

    public int pay(int money)
    {
        //TODO pop pay emote
        this.money -= money;
        return money;
    }

    public void move(Vector2F dir, float dt)
    {
        position = position.add(dir.normalized().mul(dt * getMovementSpeed()));
    }

    @Override
    protected int getRenderLayer() { return 1; }

    protected abstract void start();

    protected abstract Task getNewTask();

    protected abstract float getMovementSpeed();



    private static String getRandomName()
    {
        final List<String> names = Resources.Instace.entityNames;
        return names.get(Random.getRandomInt(0, names.size()));
    }
}
