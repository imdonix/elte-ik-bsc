package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.objects.Game;
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
            System.out.println("Game is full");
        } catch (NoCoverageException e) {
            System.out.println("No money for this game");
        }
    }
}
