package hu.elte.madtycoon.ui.components;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

public abstract class PlusMinusComponent extends PreviewComponent
{
    @Override
    public Component createComponent() {
        JPanel p = new JPanel();
        p.setLayout(new FlowLayout());
        p.setOpaque(false);

        JButton add = new JButton();
        add.setOpaque(false);
        add.setContentAreaFilled(false);
        add.setBorderPainted(false);
        add.setIcon(new ImageIcon(Resources.Instance.plusButton));
        add.addActionListener((e) -> {
            plus();
            panel.render();
        });

        JButton rem = new JButton();
        rem.setOpaque(false);
        rem.setContentAreaFilled(false);
        rem.setBorderPainted(false);
        rem.setIcon(new ImageIcon(Resources.Instance.minusButton));
        rem.addActionListener((e) -> {
            minus();
            panel.render();

        });

        p.add(rem);
        p.add(add);

        return p;
    }

    protected abstract void plus();

    protected abstract void minus();
}
