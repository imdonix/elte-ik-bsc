package hu.elte.madtycoon.ui;


import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

public class BuildingShop extends ShopWindow{
    private final JPanel panel;
    private final JButton coinFlip;

    public BuildingShop(){
        super();

        panel= new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.setOpaque(false);

        coinFlip = new JButton();
        coinFlip.setMargin(new Insets(25, 0, 0, 0));
        coinFlip.setPreferredSize(new Dimension(1130, 150));
        coinFlip.setOpaque(false);
        coinFlip.setContentAreaFilled(false);
        coinFlip.setBorderPainted(false);
        //exit.addActionListener(e -> this.dispose());  ** IDE KELL A LISTENER A COIN FLIP LERAKÁSÁHOZ **
        coinFlip.setIcon(new ImageIcon(Resources.Instance.shopCoinFlipBuyButton));
        panel.add(coinFlip);
        this.add(panel);
    }
}
