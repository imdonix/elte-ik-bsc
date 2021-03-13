package hu.elte.madtycoon;

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

        try {
            play.setIcon(new ImageIcon(ImageIO.read(new File("res/menu_play_button.png"))));
            settings.setIcon(new ImageIcon(ImageIO.read(new File("res/menu_settings_button.png"))));
            credits.setIcon(new ImageIcon(ImageIO.read(new File("res/menu_credits_button.png"))));
            exit.setIcon(new ImageIcon(ImageIO.read(new File("res/menu_exit_button.png"))));
        } catch (IOException e) {
            e.printStackTrace();
        }

        this.setPreferredSize(screenSize);
            Image img = Toolkit.getDefaultToolkit().getImage("res/menu_bg.jpg");
            this.setContentPane(new JPanel() {
                @Override
                public void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    g.drawImage(img, 0, 0, this);
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
