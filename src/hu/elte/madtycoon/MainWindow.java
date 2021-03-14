package hu.elte.madtycoon;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

public class MainWindow extends JFrame {
    private JButton play;
    private JButton exit;
    private JButton settings;
    private JButton credits;
    private JPanel panel;
    private Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

    public MainWindow() {
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

        play.setIcon(new ImageIcon(Resources.Instace.menuPlayButton));
        settings.setIcon(new ImageIcon(Resources.Instace.menuSettingsButton));
        credits.setIcon(new ImageIcon(Resources.Instace.menuCreditsButton));
        exit.setIcon(new ImageIcon(Resources.Instace.menuExitButton));

        this.setPreferredSize(screenSize);
            this.setContentPane(new JPanel() {
                @Override
                public void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    g.drawImage(Resources.Instace.menuBackGroundImage, 0, 0, this);
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
