package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.ui.components.DisplayComponent;

public class InGameComponent extends DisplayComponent
{
    public InGameComponent(Game game)
    {
        super("Visitors", () -> new Integer(game.getVisitorsCount()).toString());
    }

}
