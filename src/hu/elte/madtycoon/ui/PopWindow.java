package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import javax.swing.*;


public class PopWindow extends JFrame{
    private final JButton exit;

    public PopWindow(){

        this.setUndecorated(true);

        exit = new JButton();
        exit.setMargin(new Insets(25, 1100, 0, 0));
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> this.dispose());
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        this.setPreferredSize(new Dimension(1220,773));
        this.setResizable(false);
        this.pack();
        this.setContentPane(new JPanel() {
            @Override
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(Resources.Instance.shopBackGroundImage, 0, 0, this);
            }
        });
        this.setLocationRelativeTo(null);
        this.add(exit);
        this.setVisible(true);
    }
}
