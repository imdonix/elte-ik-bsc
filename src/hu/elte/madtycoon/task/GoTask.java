package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class GoTask <T extends ITargetable> extends Task<T>
{
    private T target;

    public GoTask(Entity entity, T target, IInteract<T> interaction) {
        super(entity, interaction);
        this.target = target;
    }

    @Override
    protected void doPre(float dt) {
        if(entity.getPosition().distance(target.getTargetPosition()) < Vector2F.E)
            reach = true;
        else
        {
            Vector2F dir = target.getTargetPosition().min(entity.getPosition());
            entity.getSprite().setRotation(dir.getAnimDirection());
            entity.getSprite().setState("walk");
            entity.move(dir, dt);
        }
    }

    @Override
    protected void interact()
    {
        interaction.interact(target);
    }
}
