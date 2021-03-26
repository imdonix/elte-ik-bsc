package hu.elte.madtycoon.task.visitor;

import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.exception.GameFullException;
import hu.elte.madtycoon.utils.exception.GameUnderConstruction;
import hu.elte.madtycoon.utils.exception.NoCoverageException;
import hu.elte.madtycoon.utils.exception.NoWorkerInDuty;

public class GoShop extends SmartGoTask<Visitor, Shop>
{
    public GoShop(Visitor entity, Shop target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try {
            target.enter(entity);
        } catch (GameFullException e) {

        } catch (NoCoverageException e)
        {
            System.out.println(String.format("%s has no money to eat", entity));
            entity.setTask(new LeavePark(entity));
        } catch (GameUnderConstruction e){
            System.out.println("This shop is under construction");
        } catch (NoWorkerInDuty e){
            System.out.println("No worker in duty");
            entity.setTask(new LeavePark(entity));
        }
    }

    @Override
    protected void fail()
    {
        //entity.addVisited(target);
        System.out.println(String.format("%s cant reach this game!", entity));
        //TODO pop emote for building cant be reach
    }
}
