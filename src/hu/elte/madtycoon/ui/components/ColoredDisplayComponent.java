package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

public class ColoredDisplayComponent extends PreviewComponent
{
    private final String property;
    private final String value;
    private final Color color;

    public ColoredDisplayComponent(String property, String value, Color color)
    {
        this.property = property;
        this.value = value;
        this.color = color;
    }

    @Override
    public Component createComponent()
    {
        JPanel p = new JPanel();
        p.setLayout(new FlowLayout(FlowLayout.LEFT));

        JTextPane prop = new JTextPane();
        JTextPane text = new JTextPane();

        prop.setOpaque(false);

        prop.setEditable(false);
        text.setEditable(false);

        prop.setText(String.format("%s :  ", property));
        text.setText(String.format("%s", value));
        text.setBackground(color);

        text.setForeground(Color.decode("#1c1710"));
        prop.setForeground(Color.decode("#1c1710"));
        prop.setFont(Resources.Instance.chBell);
        text.setFont(Resources.Instance.chBell);
        text.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        prop.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));

        p.setOpaque(false);
        p.add(prop);
        p.add(text);

        return p;
    }
}
