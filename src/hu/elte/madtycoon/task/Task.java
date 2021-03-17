package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Task <T extends ITargetable>
{
    public final Entity entity;
    public final IInteract<T> interaction;

    protected boolean reach;
    protected boolean done;

    public Task(Entity entity, IInteract<T> interaction)
    {
        this.entity = entity;
        this.interaction = interaction;
        done = false;
        reach = false;
    }

    public final void update(float dt)
    {
        if(reach)
        {
            if(!done) interact();
            done = true;
        }
        else
            doPre(dt);
    }

    public boolean isDone()
    {
        return done;
    }

    protected abstract void interact();

    protected abstract void doPre(float dt);
}
