package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewComponent;
import hu.elte.madtycoon.utils.IGetterT;

import javax.swing.*;
import java.awt.*;

public class DisplayComponent extends PreviewComponent {
    private final String property;
    private final IGetterT<String> getter;

    public DisplayComponent(String property, IGetterT<String> getter) {
        this.property = property;
        this.getter = getter;
    }

    @Override
    public Component createComponent() {
        JTextPane text = new JTextPane();
        text.setOpaque(false);
        text.setEditable(false);
        text.setText(String.format("%s :  %s", property, getter.get()));
        text.setForeground(Color.decode("#1c1710"));
        text.setFont(getFont());
        text.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        return text;
    }

    public Font getFont()
    {
        return Resources.Instance.chBell;
    }
}
