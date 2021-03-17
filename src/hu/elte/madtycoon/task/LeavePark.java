package hu.elte.madtycoon.task;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.utils.Vector2F;

public class LeavePark extends GoTask
{

    public LeavePark(Entity entity, World world)
    {
        super(entity, new ITargetable()
        {
            @Override
            public Vector2F getTargetPosition() {
                return Vector2F.ZERO;
            }
        });

        //TODO add world entry point as exit
    }

    @Override
    protected void start()
    { }

    @Override
    protected void interact()
    {
        // TODO destroy the entity
        System.out.println(String.format("%s left the park", entity.getName()));
    }

}
