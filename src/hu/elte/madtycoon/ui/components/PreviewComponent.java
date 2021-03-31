package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.ui.core.PreviewFrame;
import hu.elte.madtycoon.ui.core.ShowPanel;

import java.awt.*;

public abstract class PreviewComponent
{
    protected ShowPanel panel;

    public final Component build(ShowPanel panel)
    {
        this.panel = panel;
        return createComponent();
    }

    protected void dispose()
    {
        panel.dispose();
    }

    protected void render()
    {
        panel.render();
    }

    public abstract Component createComponent();

    public static String floatToPercent(float health)
    {
        return String.format("%d%%", (int) (health * 100));
    }

    public static String floatToDecoration(float decoration)
    {
        return String.format("%.1f (", decoration);
    }

    public static String intToDollar(int money)
    {
        return String.format("%d $", money);
    }

}
