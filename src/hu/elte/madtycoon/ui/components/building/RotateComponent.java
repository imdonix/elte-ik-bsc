package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.ToggleComponent;
import hu.elte.madtycoon.utils.IGetterB;
import hu.elte.madtycoon.utils.ISetterB;

public class RotateComponent extends ToggleComponent
{

    public RotateComponent(Building building)
    {
        super(
                Resources.Instance.rotate,
                () -> building.getSprite().getRotation(),
                (rotation) -> building.getSprite().setRotation(rotation)
        );
    }
}
