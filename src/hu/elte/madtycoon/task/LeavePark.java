package hu.elte.madtycoon.task;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.utils.Vector2F;

public class LeavePark extends Task
{

    public LeavePark(Entity entity, World world) {
        super(entity, new ITargetable() {
            @Override
            public Vector2F getPosition() {
                return Vector2F.ZERO;
            }
        });
    }
}
