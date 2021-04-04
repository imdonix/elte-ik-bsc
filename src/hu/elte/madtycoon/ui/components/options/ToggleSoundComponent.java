package hu.elte.madtycoon.ui.components.options;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.Sounds;
import hu.elte.madtycoon.ui.components.ToggleComponent;
import hu.elte.madtycoon.utils.IGetterB;
import hu.elte.madtycoon.utils.ISetterB;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class ToggleSoundComponent extends ToggleComponent
{
    public ToggleSoundComponent()
    {
        super(Resources.Instance.openCloseButton, Sounds::getAudio, Sounds::setAudio);
    }

    @Override
    public Component createComponent()
    {
        JPanel panel = new JPanel(new FlowLayout());
        panel.setOpaque(false);

        JTextPane t = new JTextPane();
        t.setOpaque(false);
        t.setEditable(false);
        t.setText(String.format("Sound : %s", Sounds.getAudio() ? "On" : "Off"));
        t.setForeground(Color.decode("#1c1710"));
        t.setFont(Resources.Instance.sansPro);
        t.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));

        panel.add(t);
        panel.add(super.createComponent());

        return panel;
    }
}
