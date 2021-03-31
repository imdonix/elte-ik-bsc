package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.DisplayComponent;

public class DecorationComponent extends DisplayComponent
{
    public DecorationComponent(Building building)
    {
        super("Decoration", floatToDecoration(building.getDecorationValue()));
    }
}
