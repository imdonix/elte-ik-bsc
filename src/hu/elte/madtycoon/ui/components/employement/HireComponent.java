package hu.elte.madtycoon.ui.components.employement;

import hu.elte.madtycoon.core.Employment;
import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Worker;

import java.awt.image.BufferedImage;

public class HireComponent extends WorkerActionComponent
{
    private final Employment employment;

    public HireComponent(Worker worker, Employment employment)
    {
        super(worker);
        this.employment = employment;
    }

    @Override
    protected void action()
    {
        employment.hire(worker);
    }

    @Override
    protected BufferedImage getImage()
    {
        return Resources.Instance.plusButton;
    }
}
