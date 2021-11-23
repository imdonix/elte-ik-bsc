package hu.elte.madtycoon.ui.components.employement;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Worker;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.image.BufferedImage;

public abstract class WorkerActionComponent extends WorkerDisplayComponent
{
    private boolean done;

    public WorkerActionComponent(Worker worker)
    {
        super(worker);
        done = false;
    }

    @Override
    public Component createComponent()
    {
        JPanel panel = new JPanel(new FlowLayout());
        panel.setOpaque(false);
        panel.add(super.createComponent());

        if(!done)
        {
            JButton action = new JButton();
            action.setOpaque(false);
            action.setContentAreaFilled(false);
            action.setBorderPainted(false);
            action.setIcon(new ImageIcon(getImage()));
            action.addActionListener(this::doIt);
            panel.add(action);
        }

        return panel;
    }

    private void doIt(ActionEvent e)
    {
        action();
        done = true;
        panel.render();
    }

    protected abstract void action();

    protected abstract BufferedImage getImage();
}
