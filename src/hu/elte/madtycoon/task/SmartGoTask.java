package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.pathfind.PathFindRequest;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

public abstract class SmartGoTask <G extends Entity, T extends ITargetable> extends Task<G>
{
    protected T target;
    private boolean failInteract;
    private PathFindRequest request;


    public SmartGoTask(G entity, T target) {
        super(entity);
        this.target = target;
        this.failInteract = true;
    }

    @Override
    protected void start()
    {
        entity.getSprite().setState(AnimatedSprite.IDLE);
        request = entity.getWorld().getRoadSystem().pathFind(new Vector2I(entity.getPosition()), new Vector2I(target.getTargetPosition()));
    }

    @Override
    protected void doPre(float dt)
    {
        if(request.isDone())
        {
            if(request.isSuccessful())
            {
                if(request.getPath().hasNext())
                {
                    Road target = request.getPath().current();
                    if(target == null || !target.getActive())
                        failIt();
                    else
                    {
                        if(entity.getPosition().distance(target.getTargetPosition()) < Vector2F.E)
                            request.getPath().next();
                        else
                        {
                            Vector2F dir = target.getTargetPosition().min(entity.getPosition());
                            entity.getSprite().setRotation(dir.getAnimDirection());
                            entity.getSprite().setState(AnimatedSprite.WALK);
                            entity.move(dir, dt);
                        }
                    }
                }
                else
                    reach = true;
            }
            else
                failIt();
        }
    }

    private void failIt()
    {
        if(failInteract)
        {
            fail();
            done = true;
            failInteract = false;
        }
    }

    protected abstract void fail();

}
