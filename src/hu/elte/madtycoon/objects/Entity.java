package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.List;

public abstract class Entity extends GameObject
{
    protected final String name;
    protected float interest;
    protected float food;
    protected int money;


    protected Entity(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
        this.name = getRandomName();
    }

    private static String getRandomName()
    {
        final List<String> names = Resources.Instace.entityNames;
        return names.get(Random.getRandomInt(0, names.size()));
    }

    public float getHappiness()
    {
        return (interest + food) / 2;
    }

    @Override
    protected int getRenderLayer() { return 1; }

    protected abstract void start();
}
