package hu.elte.madtycoon.ui.components.employement;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.ui.components.PreviewComponent;

import java.awt.*;

public class WorkerDisplayComponent extends DisplayComponent
{
    protected Worker worker;

    public WorkerDisplayComponent(Worker worker)
    {
        super(String.format("[%s] %s", worker.getTypeName() ,worker.getName()), worker::toString);
        this.worker = worker;
    }

    @Override
    public Font getFont()
    {
        return Resources.Instance.sansPro;
    }
}
