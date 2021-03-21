package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;

import javax.swing.ImageIcon;

public class Menu extends JFrame {
    private final JButton play;
    private final JButton exit;
    private final JButton settings;
    private final JButton credits;
    private final JPanel panel;
    private final Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

    private Engine engine;

    public Menu() {
        this.setTitle("Mad Tycoon - Menu");
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);
        this.setUndecorated(true);
        panel= new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        play = new JButton();
        play.setMargin(new Insets(350, 200, 0, 0));
        play.setOpaque(false);
        play.setContentAreaFilled(false);
        play.setBorderPainted(false);
        play.addActionListener(a -> {
            engine = new Engine();
            this.setVisible(false);
        });

        settings = new JButton();
        settings.setMargin(new Insets(50, 0, 0, 0));
        settings.setOpaque(false);
        settings.setContentAreaFilled(false);
        settings.setBorderPainted(false);

        credits = new JButton();
        credits.setMargin(new Insets(50, 50, 0, 0));
        credits.setOpaque(false);
        credits.setContentAreaFilled(false);
        credits.setBorderPainted(false);

        exit = new JButton();
        exit.setMargin(new Insets(50, 175, 0, 0));
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> System.exit(0));

        play.setIcon(new ImageIcon(Resources.Instance.menuPlayButton));
        settings.setIcon(new ImageIcon(Resources.Instance.menuSettingsButton));
        credits.setIcon(new ImageIcon(Resources.Instance.menuCreditsButton));
        exit.setIcon(new ImageIcon(Resources.Instance.menuExitButton));

        this.setPreferredSize(screenSize);
            this.setContentPane(new JPanel() {
                @Override
                public void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    g.drawImage(Resources.Instance.menuBackGroundImage, 0, 0, this);
                }
            });
        panel.add(play);
        panel.add(settings);
        panel.add(credits);
        panel.add(exit);
        panel.setOpaque(false);
        this.add(panel, BorderLayout.PAGE_END);
        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
