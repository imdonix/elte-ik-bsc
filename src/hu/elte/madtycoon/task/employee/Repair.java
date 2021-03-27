package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.RepairMan;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public class Repair extends SmartGoTask<RepairMan, Building> {

    public Repair(RepairMan entity, Building target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
            target.repair(entity);
            entity.earn((int) entity.getSalary());
        }
        catch (JobAlreadyTaken jobAlreadyTaken)
        {
            System.out.println(String.format("%s job is no longer available!", entity));
        }
    }

    @Override
    protected void fail()
    {
        System.out.println(String.format("%s cant reach the shop!", entity));
        //TODO pop emote for building cant be reach
    }
}
