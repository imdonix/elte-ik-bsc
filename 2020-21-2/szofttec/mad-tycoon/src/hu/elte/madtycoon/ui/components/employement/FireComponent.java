package hu.elte.madtycoon.ui.components.employement;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Worker;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class FireComponent extends WorkerActionComponent
{

    public FireComponent(Worker worker) {
        super(worker);
    }

    @Override
    protected void action()
    {
        worker.fire();
    }

    @Override
    protected BufferedImage getImage()
    {
        return Resources.Instance.minusButton;
    }
}
