package hu.elte.madtycoon.task.utils;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.task.GoTask;
import hu.elte.madtycoon.utils.Vector2F;

public class LeavePark extends GoTask
{

    private final World world;

    public LeavePark(Entity entity)
    {
        super(entity, () -> new Vector2F(World.ENTRANCE_POINT));
        this.world = entity.getWorld();
    }

    @Override
    protected void start()
    { }

    @Override
    protected void interact()
    {
        System.out.println(String.format("[TASK] %s left the park", entity.toString()));
        world.destroy(entity);
    }

}
