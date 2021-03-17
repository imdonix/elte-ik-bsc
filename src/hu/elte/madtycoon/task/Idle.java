package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;

public class Idle extends WaitTask
{
    public static final float IDLE_TIME = 1.5F;

    public Idle(Entity entity) {
        super(entity, IDLE_TIME, (e) -> System.out.println(e.getName()));
    }
}
