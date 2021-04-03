package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.utils.IGetterB;
import hu.elte.madtycoon.utils.ISetterB;

public class ToggleComponent extends PreviewActionComponent
{

    private final IGetterB getter;
    private final ISetterB setter;

    public ToggleComponent(IGetterB getter, ISetterB setter)
    {
        super(Resources.Instance.openCloseButton);
        this.getter = getter;
        this.setter = setter;
    }

    @Override
    public void action()
    {
        setter.set(!getter.get());
        panel.render();
    }
}
