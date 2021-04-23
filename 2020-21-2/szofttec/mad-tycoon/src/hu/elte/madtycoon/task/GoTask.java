package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class GoTask <G extends Entity, T extends ITargetable> extends Task<G>
{
    protected T target;

    public GoTask(G entity, T target) {
        super(entity);
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
            entity.getSprite().setState(AnimatedSprite.WALK);
            entity.move(dir, dt);
        }
    }

}
