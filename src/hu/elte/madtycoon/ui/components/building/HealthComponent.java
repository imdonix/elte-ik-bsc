package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.objects.Building;

public class HealthComponent extends DisplayComponent
{
    public HealthComponent(Building building)
    {
        super("Health", floatToPercent(building.getHealth()).toString());
    }
}
