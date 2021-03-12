package hu.elte.madtycoon;

import javax.swing.*;
import java.awt.*;

public class MainWindow {
    private JFrame frame;
    private JPanel panel;
    private JButton play;
    private JButton settings;
    private JButton credits;

    public MainWindow() {
        frame = new JFrame("Mad Tycoon - Menu");
        panel = new JPanel();

        play = new JButton();
        play.setAlignmentX(Component.CENTER_ALIGNMENT);
        play.setText("Play");

        settings = new JButton();
        settings.setAlignmentX(Component.CENTER_ALIGNMENT);
        settings.setText("Settings");

        credits = new JButton();
        credits.setAlignmentX(Component.CENTER_ALIGNMENT);
        credits.setText("Credits");

        panel.setLayout(new BoxLayout(panel,BoxLayout.Y_AXIS));
        panel.add(play);
        panel.add(settings);
        panel.add(credits);

        frame.add(panel, BorderLayout.SOUTH);

        frame.setPreferredSize(new Dimension(500, 500));
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
