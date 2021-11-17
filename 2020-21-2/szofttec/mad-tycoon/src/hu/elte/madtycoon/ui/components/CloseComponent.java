package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;

import java.awt.image.BufferedImage;

public class CloseComponent extends PreviewActionComponent
{
    public CloseComponent() {
        super(Resources.Instance.gameExitButton);
    }

    @Override
    public void action()
    {
        panel.dispose();
    }
}
