package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

public class TextComponent extends PreviewComponent
{
    private final String text;

    public TextComponent(String text)
    {
        this.text = text;
    }

    @Override
    public Component createComponent()
    {
        JTextPane t = new JTextPane();
        t.setOpaque(false);
        t.setEditable(false);
        t.setText(text);
        t.setForeground(Color.decode("#1c1710"));
        t.setFont(Resources.Instance.chBell);
        t.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        return t;
    }
}
