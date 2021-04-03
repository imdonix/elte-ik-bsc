package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.WaitTask;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public class CleanRoad  extends WaitTask {

    public final static float CLEAN_TIME = 1.75F;

    private Road target;

    public CleanRoad(Worker entity, Road target)
    {
        super(entity, CLEAN_TIME);
        this.target = target;
    }

    @Override
    protected void start()
    {
        entity.getSprite().setState(AnimatedSprite.CLEAN);
    }

    @Override
    protected void interact()
    {
        target.repair((Worker) entity);
    }
}
