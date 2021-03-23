package hu.elte.madtycoon.task.visitor;

import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.task.GoTask;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.exception.GameFullException;
import hu.elte.madtycoon.utils.exception.NoCoverageException;

public class Play extends GoTask<Visitor, Game>
{
    public Play(Visitor entity, Game target) {
        super(entity, target);
    }

    @Override
    protected void start(){}

    @Override
    protected void interact()
    {
        try {
            target.enter(entity);
        } catch (GameFullException e) {

        } catch (NoCoverageException e)
        {
            System.out.println(String.format("%s has no money to this game", entity));
            entity.setTask(new LeavePark(entity));
        }
    }
}
