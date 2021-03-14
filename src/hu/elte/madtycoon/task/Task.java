package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Task
{
    public final Entity entity;
    public final ITargetable target;

    private boolean reach;
    private boolean done;

    public Task(Entity entity, ITargetable target)
    {
        this.entity = entity;
        this.target = target;
        done = false;
        reach = false;
    }

    public void update(float dt)
    {
        if(reach)
        {
            if(!done) interact();
            done = true;
        }
        else
            moveToTarget(dt);
    }

    private void moveToTarget(float dt)
    {
        if(entity.getPosition().distance(target.getPosition()) < Vector2F.E)
            reach = true;
        else
        {
            entity.getSprite().setState("walk");
            Vector2F dir = target.getPosition().min(entity.getPosition());
            entity.move(dir, dt);
        }
    }

    public boolean isDone()
    {
        return done;
    }

    private void interact()
    {
        //TODO as interface
        System.out.println("Interacted.");
    }
}
