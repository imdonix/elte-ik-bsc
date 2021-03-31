package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewComponent;

import javax.swing.*;
import java.awt.*;

abstract class DisplayComponent extends PreviewComponent
{
    private final String property;
    private final String value;

    public DisplayComponent(String property, String value)
    {
        this.property = property;
        this.value = value;
    }

    @Override
    public Component createComponent()
    {
        JTextPane text = new JTextPane();
        text.setOpaque(false);
        text.setEditable(false);
        text.setText(String.format("%s :  %s", property, value));
        text.setForeground(Color.decode("#1c1710"));
        text.setFont(Resources.Instance.chBell);
        text.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        return text;
    }
}
