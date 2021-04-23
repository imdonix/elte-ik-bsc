package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.ColoredDisplayComponent;
import hu.elte.madtycoon.ui.components.DisplayComponent;

import java.awt.*;

public class OpenComponent extends ColoredDisplayComponent
{
    public OpenComponent(Building building) {
        super("Opened", () -> building.isOpened() ? "Yes" : "No",  () ->  building.isOpened() ? Color.GREEN : Color.RED);
    }
}
