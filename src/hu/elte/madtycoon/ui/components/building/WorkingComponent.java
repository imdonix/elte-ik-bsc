package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.ColoredDisplayComponent;

import java.awt.*;

public class WorkingComponent extends ColoredDisplayComponent
{
    public WorkingComponent(Building building)
    {
        super("Working",  () -> building.isWorking() ? "Yes" : "No",  () -> building.isWorking() ? Color.GREEN : Color.RED );
    }
}
