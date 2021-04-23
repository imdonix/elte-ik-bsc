package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.utils.IGetterB;
import hu.elte.madtycoon.utils.ISetterB;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class ToggleComponent extends PreviewActionComponent
{

    private final IGetterB getter;
    private final ISetterB setter;
    private final BufferedImage image;

    public ToggleComponent(BufferedImage image, IGetterB getter, ISetterB setter)
    {
        super(image);
        this.image = image;
        this.getter = getter;
        this.setter = setter;
    }

    public ToggleComponent(IGetterB getter, ISetterB setter)
    {
        super(Resources.Instance.closeButton);
        this.image = null;
        this.getter = getter;
        this.setter = setter;
    }

    @Override
    public void action()
    {
        setter.set(!getter.get());
        panel.render();
    }

    @Override
    public Component createComponent()
    {
        JButton delete = new JButton();
        delete.setOpaque(false);
        delete.setContentAreaFilled(false);
        delete.setBorderPainted(false);
        if(image != null)
            delete.setIcon(new ImageIcon(image));
        else
            delete.setIcon(getter.get() ? new ImageIcon(Resources.Instance.closeButton) : new ImageIcon(Resources.Instance.openButton) );
        delete.addActionListener((e) -> action());
        return delete;
    }



}
