package hu.elte.madtycoon.task.employee;

import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.exception.GameFullException;
import hu.elte.madtycoon.utils.exception.GameUnderConstruction;
import hu.elte.madtycoon.utils.exception.NoCoverageException;
import hu.elte.madtycoon.utils.exception.NoWorkerInDuty;

public class Work extends SmartGoTask<ShopAssistant, Shop>
{
    public Work(ShopAssistant entity, Shop target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        target.work(entity);
    }

    @Override
    protected void fail()
    {
        entity.addVisited(target);
        System.out.println(String.format("%s cant reach this game!", entity));
        //TODO pop emote for building cant be reach
    }
}

