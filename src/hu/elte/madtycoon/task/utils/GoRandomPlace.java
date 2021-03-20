package hu.elte.madtycoon.task.utils;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.task.GoTask;
import hu.elte.madtycoon.task.ITargetable;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

public class GoRandomPlace extends GoTask
{
    public GoRandomPlace(Entity entity) {
        super(entity, new ITargetable() {

            Vector2F r = new Vector2F(Random.getRandomFloat(-3, 3), Random.getRandomFloat(-3, 3));
            Vector2F d = entity.getPosition().add(r);

            @Override
            public Vector2F getTargetPosition() {
                return d;
            }
        });
    }

    @Override
    protected void start() {}

    @Override
    protected void interact()
    {
        System.out.println(String.format("%s has reached the random position", entity.getName()));
    }
}
