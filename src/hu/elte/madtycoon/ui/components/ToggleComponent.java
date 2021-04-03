package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.utils.IGetterB;
import hu.elte.madtycoon.utils.ISetterB;

import java.awt.image.BufferedImage;

public class ToggleComponent extends PreviewActionComponent
{

    private final IGetterB getter;
    private final ISetterB setter;

    public ToggleComponent(BufferedImage image, IGetterB getter, ISetterB setter)
    {
        super(image);
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
