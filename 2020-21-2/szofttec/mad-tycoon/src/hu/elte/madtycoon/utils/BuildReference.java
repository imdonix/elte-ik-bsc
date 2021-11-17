package hu.elte.madtycoon.utils;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;

public class BuildReference
{
    public final Vector2I size;
    public final int price;
    public final ICreatable createAction;

    public BuildReference(Vector2I size, int price, ICreatable createAction)
    {
        this.size = size;
        this.price = price;
        this.createAction = createAction;
    }

    public Building create(World world, Vector2F position)
    {
        return createAction.Create(world,position);
    }

}
