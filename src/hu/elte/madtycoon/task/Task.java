package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Task
{
    public final Entity entity;

    protected boolean reach;
    protected boolean done;
    private boolean startFrame;

    public Task(Entity entity)
    {
        this.entity = entity;
        done = false;
        reach = false;
        startFrame = true;
    }

    public final void update(float dt)
    {
        if(startFrame)
        {
            startFrame = false;
            start();
        }
        else
        {
            if(reach)
            {
                if(!done) interact();
                done = true;
            }
            else
                doPre(dt);
        }
    }

    public boolean isDone()
    {
        return done;
    }

    protected abstract void doPre(float dt);

    protected abstract void start();

    protected abstract void interact();

}
