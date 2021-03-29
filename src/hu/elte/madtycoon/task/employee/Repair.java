package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.entities.RepairMan;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public class Repair extends SmartGoTask<RepairMan, Game> {

    public Repair(RepairMan entity, Game target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
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
        System.out.println(String.format("%s cant reach the Game!", entity));
        //TODO pop emote for building cant be reach
    }
}
