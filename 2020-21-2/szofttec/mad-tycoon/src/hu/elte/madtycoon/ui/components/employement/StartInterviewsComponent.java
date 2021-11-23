package hu.elte.madtycoon.ui.components.employement;

import hu.elte.madtycoon.core.Employment;
import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;

import java.awt.image.BufferedImage;

public class StartInterviewsComponent extends PreviewActionComponent
{
    private final Employment employment;

    public StartInterviewsComponent(Employment employment)
    {
        super(Resources.Instance.interviews);
        this.employment = employment;
    }

    @Override
    public void action()
    {
        employment.schedule();
        panel.dispose();
    }
}
