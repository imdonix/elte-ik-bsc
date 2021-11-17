package hu.elte.madtycoon.ui.components;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;

public abstract class PreviewActionComponent extends PreviewComponent
{
    private final BufferedImage image;

    public PreviewActionComponent(BufferedImage image)
    {
        this.image = image;
    }

    @Override
    public Component createComponent()
    {
        JButton delete = new JButton();
        delete.setOpaque(false);
        delete.setContentAreaFilled(false);
        delete.setBorderPainted(false);
        delete.setIcon(new ImageIcon(image));
        delete.addActionListener((e) -> action());
        return delete;
    }

    public abstract void action();
}
