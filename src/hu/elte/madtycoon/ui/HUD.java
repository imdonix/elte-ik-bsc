package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.Building;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

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
        buildingMenu.setIcon(new ImageIcon(Resources.Instance.gameHouseBuildButton));

        decorationMenu = new JButton();
        decorationMenu.setOpaque(false);
        decorationMenu.setContentAreaFilled(false);
        decorationMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        decorationMenu.setMargin(new Insets(25, 25, 0, 0));
        decorationMenu.setIcon(new ImageIcon(Resources.Instance.gameDecorBuildButton));

        roadMenu = new JButton();
        roadMenu.setOpaque(false);
        roadMenu.setContentAreaFilled(false);
        roadMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        roadMenu.setMargin(new Insets(25, 25, 0, 0));
        roadMenu.setIcon(new ImageIcon(Resources.Instance.gameRoadBuildButton));

        stats = new JButton();
        stats.setOpaque(false);
        stats.setContentAreaFilled(false);
        stats.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        stats.setMargin(new Insets(25, 25, 0, 0));
        stats.setIcon(new ImageIcon(Resources.Instance.gameStatisticsButton));

        employeeMenu = new JButton();
        employeeMenu.setOpaque(false);
        employeeMenu.setContentAreaFilled(false);
        employeeMenu.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        employeeMenu.setMargin(new Insets(25, 25, 0, 0));
        employeeMenu.setIcon(new ImageIcon(Resources.Instance.gameEmployeeButton));

        moneyIcon = new JButton();
        moneyIcon.setOpaque(false);
        moneyIcon.setContentAreaFilled(false);
        moneyIcon.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        moneyIcon.setMargin(new Insets(25, 90, 0, 0));
        moneyIcon.setIcon(new ImageIcon(Resources.Instance.gameMoneyIcon));

        moneyLabel = new JLabel();
        moneyLabel.setBorder(new EmptyBorder(30,0,0,0));
        moneyLabel.setForeground(Color.decode("#475425"));

        happiness = new JButton();
        happiness.setOpaque(false);
        happiness.setContentAreaFilled(false);
        happiness.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        happiness.setMargin(new Insets(25, 280, 0, 0));
        happiness.setIcon(new ImageIcon(Resources.Instance.gameSanityIcon));

        happinessLabel = new JLabel();
        happinessLabel.setBorder(new EmptyBorder(30,0,0,0));
        happinessLabel.setForeground(Color.decode("#475425"));

        time = new JButton();
        time.setOpaque(false);
        time.setContentAreaFilled(false);
        time.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        time.setMargin(new Insets(25, 150, 0, 0));
        time.setIcon(new ImageIcon(Resources.Instance.gameTimeIcon));

        timeLabel = new JLabel();
        timeLabel.setBorder(new EmptyBorder(30,0,0,0));
        timeLabel.setForeground(Color.decode("#475425"));

        playPause = new JButton();
        playPause.setOpaque(false);
        playPause.setContentAreaFilled(false);
        playPause.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        playPause.setMargin(new Insets(25, 200, 0, 0));
        playPause.setIcon(new ImageIcon(Resources.Instance.gamePauseButton));

        fast = new JButton();
        fast.setOpaque(false);
        fast.setContentAreaFilled(false);
        fast.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        fast.setMargin(new Insets(25, 0, 0, 0));
        fast.setIcon(new ImageIcon(Resources.Instance.gameSpeedButton));

        options = new JButton();
        options.setOpaque(false);
        options.setContentAreaFilled(false);
        options.setBorderPainted(false);
        //exit.addActionListener(e -> System.exit(0));
        options.setMargin(new Insets(25, 0, 0, 0));
        options.setIcon(new ImageIcon(Resources.Instance.gameSettingsButton));

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

        try {
            Font ch_bell = Font.createFont(Font.TRUETYPE_FONT, new File("res/font/christmas_bell.otf")).deriveFont(46f);
            GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
            ge.registerFont(ch_bell);
            moneyLabel.setFont(ch_bell);
            happinessLabel.setFont(ch_bell);
            timeLabel.setFont(ch_bell);
        } catch (IOException e) {
            e.printStackTrace();
        } catch(FontFormatException e) {
            e.printStackTrace();
        }
    }

    public void updateGUI()
    {
        //TODO draw game status via IEngine

        Building b = engine.getSelectedBuilding();
        if(b!=null)
            System.out.println(b.getSize());

        int money = engine.getMoney();
        moneyLabel.setText(String.valueOf(money));

        float happinessValue = engine.getOverallHappiness();
        happinessLabel.setText(String.valueOf(happinessValue));

        int gameTime = engine.getTime();
        timeLabel.setText(String.valueOf(gameTime));



        fast.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                if(engine.getTimeScale() == 1) {
                    engine.setTimeScale(2.5F);
                } else if(engine.getTimeScale() == 2.5F) {
                    engine.setTimeScale(5);
                } else if(engine.getTimeScale() == 5) {
                    engine.setTimeScale(1);
                }
            }
        });

        playPause.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                if(engine.getTimeScale() == 0) {
                    engine.setTimeScale(1);
                } else {
                    engine.setTimeScale(0);
                }
            }
        });
    }

    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.gameHudImage, 0, 0, this);
    }
}
