package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import javax.swing.*;


public class ShopWindow extends JFrame{
    private final JPanel panel;
    private final JButton exit;
    private final JButton coinFlip;

    public ShopWindow(String type){

        this.setUndecorated(true);

        panel= new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        exit = new JButton();
        exit.setMargin(new Insets(25, 1100, 0, 0));
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> this.dispose());
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        coinFlip = new JButton();
        coinFlip.setMargin(new Insets(25, 0, 0, 0));
        coinFlip.setPreferredSize(new Dimension(1130, 150));
        coinFlip.setOpaque(false);
        coinFlip.setContentAreaFilled(false);
        coinFlip.setBorderPainted(false);
        //exit.addActionListener(e -> this.dispose());
        coinFlip.setIcon(new ImageIcon(Resources.Instance.shopCoinFlipBuyButton));

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
        this.add(coinFlip);
        this.setVisible(true);
    }
}
