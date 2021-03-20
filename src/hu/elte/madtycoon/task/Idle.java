package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.render.AnimatedSprite;

public class Idle extends WaitTask
{
    public static final float IDLE_TIME = 1.5F;


    public Idle(Entity entity) {
        this(entity, IDLE_TIME);
    }

    public Idle(Entity entity, float time) { super(entity, time); }

    @Override
    protected void start()
    {
        entity.getSprite().setState(AnimatedSprite.IDLE);
    }

    @Override
    protected void interact()
    {
        System.out.println(String.format("%s idle ended", entity.getName()));
    }
}
