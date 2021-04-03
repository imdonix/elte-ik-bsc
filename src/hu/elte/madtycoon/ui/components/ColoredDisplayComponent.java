package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.utils.IGetterT;

import javax.swing.*;
import java.awt.*;

public class ColoredDisplayComponent extends PreviewComponent
{
    private final String property;
    private final IGetterT<String> valueGetter;
    private final IGetterT<Color> colorGetter;

    public ColoredDisplayComponent(String property, IGetterT<String> valueGetter, IGetterT<Color> colorGetter)
    {
        this.property = property;
        this.valueGetter = valueGetter;
        this.colorGetter = colorGetter;
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
        text.setText(String.format("%s", valueGetter.get()));
        text.setBackground(colorGetter.get());

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
