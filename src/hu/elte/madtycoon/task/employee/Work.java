package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.exception.*;

public class Work extends SmartGoTask<ShopAssistant, Shop>
{
    public Work(ShopAssistant entity, Shop target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
            target.work(entity);
        }
        catch (JobAlreadyTaken jobAlreadyTaken)
        {
            System.out.println(String.format("%s job is no longer available!", entity));
        }
        catch (GameUnderConstruction gameUnderConstruction)
        {
            System.out.println(String.format("%s building is under construction!", entity));
        }
    }

    @Override
    protected void fail()
    {
        System.out.println(String.format("%s cant reach the shop!", entity));
        //TODO pop emote for building cant be reach
    }
}

