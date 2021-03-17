package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

public class GoRandomPlace extends GoTask
{
    public GoRandomPlace(Entity entity) {
        super(entity, new ITargetable() {

            Vector2F v = new Vector2F(Random.getRandomFloat(2, 40), Random.getRandomFloat(2, 15));

            @Override
            public Vector2F getTargetPosition() {
                return v;
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
