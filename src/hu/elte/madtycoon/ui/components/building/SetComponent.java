package hu.elte.madtycoon.ui.components.building;

import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.ui.components.PlusMinusComponent;
import hu.elte.madtycoon.utils.IGetter;
import hu.elte.madtycoon.utils.ISetter;

import javax.swing.*;
import java.awt.*;

public class SetComponent extends PlusMinusComponent
{
    public static final int DELTA = 10;

    private final IGetter getter;
    private final ISetter setter;
    private final String property;

    public SetComponent(String property, IGetter getter, ISetter setter)
    {
        this.property = property;
        this.getter = getter;
        this.setter = setter;
    }

    @Override
    protected void plus() { setter.set(getter.get() + DELTA); }

    @Override
    protected void minus() { setter.set(getter.get() - DELTA); }

    @Override
    public Component createComponent() {
        JPanel p = new JPanel();
        DisplayComponent d = new DisplayComponent(property, () -> intToDollar(getter.get()));
        p.setLayout(new FlowLayout());
        p.setOpaque(false);

        p.add(d.build(panel));
        p.add(super.createComponent());

        return p;
    }
}
