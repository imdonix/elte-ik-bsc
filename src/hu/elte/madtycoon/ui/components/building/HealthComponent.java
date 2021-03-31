package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.DisplayComponent;

public class HealthComponent extends DisplayComponent
{
    public HealthComponent(Building building)
    {
        super("Health", () -> floatToPercent(building.getHealth()).toString());
    }
}
