package hu.elte.madtycoon.task.utils;

import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.task.SmartGoTask;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.exception.*;

public class GoShop extends SmartGoTask<Entity, Shop>
{
    public GoShop(Entity entity, Shop target) {
        super(entity, target);
    }

    @Override
    protected void interact()
    {
        try
        {
            target.eat(entity);
        }
        catch (NoCoverageException e)
        {
            System.out.println(String.format("%s has no money to eat", entity));
            entity.setTask(new LeavePark(entity));
        } catch (GameUnderConstruction e){
            System.out.println("This shop is under construction");
        } catch (NoWorkerInDuty e){
            System.out.println("No worker in duty");
            entity.setTask(new LeavePark(entity));
        } catch (BuildingDestroyed buildingDestroyed) {
            System.out.println("Building no longer exits");
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
