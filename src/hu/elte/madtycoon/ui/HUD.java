package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

public class HUD extends JPanel
{

    private IEngine engine;
    private final JButton exit;

    public HUD(IEngine engine)
    {
        super();
        setPreferredSize(new Dimension(1920,110));

        this.engine = engine;

        exit = new JButton();
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> System.exit(0));
        exit.setMargin(new Insets(25, 0, 0, 0));
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        add(exit);
    }

    public void updateGUI()
    {
        //TODO draw game status via IEngine
    }

    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.gameHudImage, 0, 0, this);
    }
}
