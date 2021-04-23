package hu.elte.madtycoon.ui.components.options;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.Sounds;
import hu.elte.madtycoon.ui.components.ToggleComponent;

import javax.swing.*;
import java.awt.*;

public class ToggleMusicComponent extends ToggleComponent
{
    public ToggleMusicComponent()
    {
        super(Sounds::getMusic, Sounds::setMusic);
    }

    @Override
    public Component createComponent()
    {
        JPanel panel = new JPanel(new FlowLayout());
        panel.setOpaque(false);

        JTextPane t = new JTextPane();
        t.setOpaque(false);
        t.setEditable(false);
        t.setText(String.format("Music : %s", Sounds.getMusic() ? "On" : "Off"));
        t.setForeground(Color.decode("#1c1710"));
        t.setFont(Resources.Instance.sansPro);
        t.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));

        panel.add(t);
        panel.add(super.createComponent());

        return panel;
    }
}
