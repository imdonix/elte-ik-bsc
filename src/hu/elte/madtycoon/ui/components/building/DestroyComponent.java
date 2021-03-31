package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;

import java.awt.event.ActionListener;

public class DestroyComponent extends PreviewActionComponent
{
    private final Building building;

    public DestroyComponent(Building building)
    {
        super(Resources.Instance.destroyButton);
        this.building = building;
    }

    @Override
    public void action()
    {
        panel.dispose();
        building.destroy();
    }
}
