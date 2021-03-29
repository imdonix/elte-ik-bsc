package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.objects.entities.Cleaner;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.WaitTask;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public class FindRoad extends SmartGoTask<Cleaner, Road> {
    public FindRoad(Cleaner entity, Road target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
            entity.setTask(new WaitTask(entity,5F) {
                @Override
                protected void start() {

                }

                @Override
                protected void interact() {

                }
            });
            target.repair(entity);
        }
        catch (JobAlreadyTaken jobAlreadyTaken)
        {
            System.out.println(String.format("%s job is no longer available!", entity));
        }
    }

    @Override
    protected void fail()
    {
        System.out.println(String.format("%s cant reach the road!", entity));
        //TODO pop emote for building cant be reach
    }
}
