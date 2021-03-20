package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;

import javax.swing.*;
import java.awt.*;

public class HUD extends JPanel
{

    private IEngine engine;
    private final JButton buildingMenu;
    private final JButton decorationMenu;
    private final JButton roadMenu;
    private final JButton stats;
    private final JButton employeeMenu;
    private final JButton moneyIcon;
    private JLabel moneyLabel;
    private JLabel happinessLabel;
    private JLabel timeLabel;
    private final JButton happiness;
    private final JButton time;
    private final JButton playPause;
    private final JButton fast;
    private final JButton exit;
    private final JButton options;

    public HUD(IEngine engine)
    {
        super();
        setPreferredSize(new Dimension(1920,110));

        this.engine = engine;

        buildingMenu = new JButton();
        buildingMenu.setOpaque(false);
        buildingMenu.setContentAreaFilled(false);
        buildingMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        buildingMenu.setMargin(new Insets(25, 60, 0, 0));
        buildingMenu.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        decorationMenu = new JButton();
        decorationMenu.setOpaque(false);
        decorationMenu.setContentAreaFilled(false);
        decorationMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        decorationMenu.setMargin(new Insets(25, 25, 0, 0));
        decorationMenu.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        roadMenu = new JButton();
        roadMenu.setOpaque(false);
        roadMenu.setContentAreaFilled(false);
        roadMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        roadMenu.setMargin(new Insets(25, 25, 0, 0));
        roadMenu.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        stats = new JButton();
        stats.setOpaque(false);
        stats.setContentAreaFilled(false);
        stats.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        stats.setMargin(new Insets(25, 25, 0, 0));
        stats.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        employeeMenu = new JButton();
        employeeMenu.setOpaque(false);
        employeeMenu.setContentAreaFilled(false);
        employeeMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        employeeMenu.setMargin(new Insets(25, 25, 0, 0));
        employeeMenu.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        moneyIcon = new JButton();
        moneyIcon.setOpaque(false);
        moneyIcon.setContentAreaFilled(false);
        moneyIcon.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        moneyIcon.setMargin(new Insets(25, 125, 0, 0));
        moneyIcon.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        moneyLabel = new JLabel();
        moneyLabel.setText("Ez az");

        happiness = new JButton();
        happiness.setOpaque(false);
        happiness.setContentAreaFilled(false);
        happiness.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        happiness.setMargin(new Insets(25, 275, 0, 0));
        happiness.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        happinessLabel = new JLabel();
        happinessLabel.setText("Boldog");

        time = new JButton();
        time.setOpaque(false);
        time.setContentAreaFilled(false);
        time.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        time.setMargin(new Insets(25, 150, 0, 0));
        time.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        timeLabel = new JLabel();
        timeLabel.setText("12:30");

        playPause = new JButton();
        playPause.setOpaque(false);
        playPause.setContentAreaFilled(false);
        playPause.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        playPause.setMargin(new Insets(25, 175, 0, 0));
        playPause.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        fast = new JButton();
        fast.setOpaque(false);
        fast.setContentAreaFilled(false);
        fast.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        fast.setMargin(new Insets(25, 0, 0, 0));
        fast.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        options = new JButton();
        options.setOpaque(false);
        options.setContentAreaFilled(false);
        options.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        options.setMargin(new Insets(25, 0, 0, 0));
        options.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        exit = new JButton();
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> System.exit(0));
        exit.setMargin(new Insets(25, 0, 0, 0));
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        add(buildingMenu);
        add(decorationMenu);
        add(roadMenu);
        add(stats);
        add(employeeMenu);
        add(moneyIcon);
        add(moneyLabel);
        add(happiness);
        add(happinessLabel);
        add(time);
        add(timeLabel);
        add(playPause);
        add(fast);
        add(options);
        add(exit);
    }

    public void updateGUI()
    {
        //TODO draw game status via IEngine

        Building b = engine.getSelectedBuilding();
        if(b!=null)
            System.out.println(b.getSize());
        
    }

    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.gameHudImage, 0, 0, this);
    }
}
