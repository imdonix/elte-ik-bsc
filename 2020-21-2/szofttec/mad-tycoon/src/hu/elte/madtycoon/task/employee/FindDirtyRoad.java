package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.objects.entities.Cleaner;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.WaitTask;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public class FindDirtyRoad extends SmartGoTask<Cleaner, Road> {
    public FindDirtyRoad(Cleaner entity, Road target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
            target.clean(entity);
            entity.setTask(new CleanRoad(entity, target));
        }
        catch (JobAlreadyTaken jobAlreadyTaken)
        {
            System.out.println("This road is already in cleaning");
        }
    }

    @Override
    protected void fail()
    {
        System.out.println(String.format("%s cant reach the road!", entity));
        //TODO pop emote for building cant be reach
    }
}
