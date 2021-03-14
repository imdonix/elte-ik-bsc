package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Task <T extends ITargetable>
{
    public final Entity entity;
    public final T target;
    public final IInteract<T> interaction;

    private boolean reach;
    private boolean done;

    public Task(Entity entity, T target, IInteract<T> interaction)
    {
        this.entity = entity;
        this.target = target;
        this.interaction = interaction;
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
        interaction.interact(target);
    }
}
