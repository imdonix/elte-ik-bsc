package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;

public abstract class WaitTask extends Task
{
    private float execute;

    public WaitTask(Entity entity, float time)
    {
        super(entity);
        execute = time;
    }

    @Override
    protected final void doPre(float dt)
    {
        execute-=dt;
        if(execute <= 0) reach = true;
    }

}
