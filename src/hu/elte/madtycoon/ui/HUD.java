package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.objects.buildings.*;
import hu.elte.madtycoon.objects.buildings.decoration.Bush;
import hu.elte.madtycoon.objects.buildings.decoration.FirePit;
import hu.elte.madtycoon.objects.buildings.decoration.Flower;
import hu.elte.madtycoon.objects.buildings.decoration.Stick;
import hu.elte.madtycoon.objects.buildings.games.CoinFlip;
import hu.elte.madtycoon.objects.buildings.games.GhostCastle;
import hu.elte.madtycoon.objects.buildings.games.RoundAbout;
import hu.elte.madtycoon.ui.core.PreviewFrame;
import hu.elte.madtycoon.utils.BuilderState;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionListener;

import static java.lang.Math.round;

public class HUD extends JPanel
{

    private final IEngine engine;
    private final HappinessMeter meter;


    private final JButton buildingMenu;
    private final JButton decorationMenu;
    private final JButton roadMenu;
    private final JButton stats;
    private final JButton employeeMenu;
    private final JButton moneyIcon;
    private final JButton happiness;
    private final JButton time;
    private final JButton playPause;
    private final JButton fast;
    private final JButton exit;
    private final JButton options;
    private final JButton happinessArrow;

    private JLabel moneyLabel;
    private JLabel happinessLabel;
    private JLabel timeLabel;

    private int i,j;
    private final float[] timeScaleVariations = new float[]{1,2.5F,5F};
    private final ImageIcon[] timeImageVariations = new ImageIcon[]
            {
                new ImageIcon(Resources.Instance.gameSpeedButton),
                new ImageIcon(Resources.Instance.gameSpeedButton2X),
                new ImageIcon(Resources.Instance.gameSpeedButton5X)
            };

    private boolean roadBuilding = false;

    public HUD(IEngine engine)
    {
        super();
        setPreferredSize(new Dimension(1920,110));

        this.engine = engine;
        this.meter = new HappinessMeter();
        i = 0;
        j = 0;


        buildingMenu = new JButton();
        buildingMenu.setOpaque(false);
        buildingMenu.setContentAreaFilled(false);
        buildingMenu.setBorderPainted(false);
        buildingMenu.setMargin(new Insets(25, 60, 0, 0));

        decorationMenu = new JButton();
        decorationMenu.setOpaque(false);
        decorationMenu.setContentAreaFilled(false);
        decorationMenu.setBorderPainted(false);
        decorationMenu.setMargin(new Insets(25, 25, 0, 0));

        roadMenu = new JButton();
        roadMenu.setOpaque(false);
        roadMenu.setContentAreaFilled(false);
        roadMenu.setBorderPainted(false);
        roadMenu.setMargin(new Insets(25, 25, 0, 0));

        stats = new JButton();
        stats.setOpaque(false);
        stats.setContentAreaFilled(false);
        stats.setBorderPainted(false);
        stats.setMargin(new Insets(25, 25, 0, 0));

        employeeMenu = new JButton();
        employeeMenu.setOpaque(false);
        employeeMenu.setContentAreaFilled(false);
        employeeMenu.setBorderPainted(false);
        employeeMenu.setMargin(new Insets(25, 25, 0, 0));

        moneyIcon = new JButton();
        moneyIcon.setOpaque(false);
        moneyIcon.setContentAreaFilled(false);
        moneyIcon.setBorderPainted(false);
        moneyIcon.setMargin(new Insets(25, 90, 0, 0));
        moneyIcon.setIcon(new ImageIcon(Resources.Instance.gameMoneyIcon));
        moneyIcon.addActionListener(e -> engine.getWorldBuilder().setGUI(new PreviewFrame(engine.getLoans().getPreview())));

        moneyLabel = new JLabel();
        moneyLabel.setBorder(new EmptyBorder(30,0,0,0));
        moneyLabel.setForeground(Color.decode("#475425"));
        moneyLabel.setMaximumSize(new Dimension(100,50));
        moneyLabel.setPreferredSize(new Dimension(100,50));
        moneyLabel.setFont(Resources.Instance.chBell);

        happiness = new JButton();
        happiness.setOpaque(false);
        happiness.setContentAreaFilled(false);
        happiness.setBorderPainted(false);
        happiness.setMargin(new Insets(25, 200, 0, 0));
        happiness.setIcon(new ImageIcon(Resources.Instance.gameSanityIcon));

        happinessLabel = new JLabel();
        happinessLabel.setBorder(new EmptyBorder(30,0,0,0));
        happinessLabel.setForeground(Color.decode("#475425"));
        happinessLabel.setMaximumSize(new Dimension(50,50));
        happinessLabel.setPreferredSize(new Dimension(50,50));
        happinessLabel.setFont(Resources.Instance.chBell);

        happinessArrow = new JButton();
        happinessArrow.setOpaque(false);
        happinessArrow.setContentAreaFilled(false);
        happinessArrow.setBorderPainted(false);
        happinessArrow.setMargin(new Insets(25, 0, 0, 0));
        happinessArrow.setIcon(new ImageIcon(Resources.Instance.gameHappyArrowEmpty));


        time = new JButton();
        time.setOpaque(false);
        time.setContentAreaFilled(false);
        time.setBorderPainted(false);
        time.setMargin(new Insets(25, 100 , 0, 0));
        time.setIcon(new ImageIcon(Resources.Instance.gameTimeIcon));

        timeLabel = new JLabel();
        timeLabel.setBorder(new EmptyBorder(30,0,0,0));
        timeLabel.setForeground(Color.decode("#475425"));
        timeLabel.setMaximumSize(new Dimension(110,50));
        timeLabel.setPreferredSize(new Dimension(110,50));
        timeLabel.setFont(Resources.Instance.chBell);

        playPause = new JButton();
        playPause.setOpaque(false);
        playPause.setContentAreaFilled(false);
        playPause.setBorderPainted(false);
        playPause.addActionListener(e -> j++);
        playPause.setMargin(new Insets(25, 100, 0, 0));
        playPause.setIcon(new ImageIcon(Resources.Instance.gamePauseButton));

        fast = new JButton();
        fast.setOpaque(false);
        fast.setContentAreaFilled(false);
        fast.setBorderPainted(false);
        fast.addActionListener(e -> i++);
        fast.setMargin(new Insets(25, 0, 0, 0));
        fast.setIcon(new ImageIcon(Resources.Instance.gameSpeedButton));

        options = new JButton();
        options.setOpaque(false);
        options.setContentAreaFilled(false);
        options.setBorderPainted(false);
        options.setMargin(new Insets(25, 0, 0, 0));
        options.setIcon(new ImageIcon(Resources.Instance.gameSettingsButton));
        options.addActionListener(e -> engine.getWorldBuilder().setGUI(new PreviewFrame(engine.getOptions().getPreview())));

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
        add(happinessArrow);
        add(time);
        add(timeLabel);
        add(playPause);
        add(fast);
        add(options);
        add(exit);
    }

    public void updateGUI()
    {

        int money = engine.getMoney();
        moneyLabel.setText(String.valueOf(money));

        meter.update(engine.getOverallHappiness());
        happinessLabel.setText(meter.getText());
        happinessArrow.setIcon(meter.getImage());

        timeLabel.setText(getNiceTime(engine.getTime()));

        engine.setTimeScale(timeScaleVariations[i%3]);
        fast.setIcon(timeImageVariations[i%3]);


        if(j % 2 == 0) {
            engine.setTimeScale(timeScaleVariations[i%3]);
            playPause.setIcon(new ImageIcon(Resources.Instance.gamePlayButton));
        } else if(j % 2 == 1) {
            engine.setTimeScale(0);
            playPause.setIcon(new ImageIcon(Resources.Instance.gamePauseButton));
        }
    }


    public void homeButtons(){

        removeActionListeners();
        engine.getWorldBuilder().setState(BuilderState.SELECT);

        buildingMenu.setIcon(new ImageIcon(Resources.Instance.gameHouseBuildButton));
        buildingMenu.addActionListener(e -> buildButtons());

        decorationMenu.setIcon(new ImageIcon(Resources.Instance.gameDecorBuildButton));
        decorationMenu.addActionListener(e-> decorButtons());

        roadMenu.setIcon(new ImageIcon(Resources.Instance.gameRoadBuildButton));
        roadMenu.addActionListener(e ->
        {
            roadBuilding = !roadBuilding;
            if(roadBuilding)
                engine.getWorldBuilder().setState(BuilderState.ROAD);
            else
                engine.getWorldBuilder().setState(BuilderState.SELECT);
        });

        stats.setIcon(new ImageIcon(Resources.Instance.gameStatisticsButton));
        stats.addActionListener(e -> engine.getWorldBuilder().setGUI(new PreviewFrame(engine.getStatistics().getPreview())));

        employeeMenu.setIcon(new ImageIcon(Resources.Instance.gameEmployeeButton));
        employeeMenu.addActionListener(e -> engine.getWorldBuilder().setGUI(new PreviewFrame(engine.getEmployment().getPreview())));
    }

    private void buildButtons(){

        removeActionListeners();
        engine.getWorldBuilder().setState(BuilderState.NONE);

        buildingMenu.setIcon(new ImageIcon(Resources.Instance.shopCoinFlipBuyButton));
        buildingMenu.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, CoinFlip.ID));

        decorationMenu.setIcon(new ImageIcon(Resources.Instance.shopRoundBuyButton));
        decorationMenu.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, RoundAbout.ID));

        roadMenu.setIcon(new ImageIcon(Resources.Instance.shopCastleBuyButton));
        roadMenu.addActionListener(e-> engine.getWorldBuilder().setState(BuilderState.BUILD, GhostCastle.ID));

        stats.setIcon(new ImageIcon(Resources.Instance.shopShopBuyButton));
        stats.addActionListener(e-> engine.getWorldBuilder().setState(BuilderState.BUILD, Shop.ID));

        employeeMenu.setIcon(new ImageIcon(Resources.Instance.shopBackButton));
        employeeMenu.addActionListener(e -> homeButtons());
    }


    private void decorButtons()
    {
        removeActionListeners();
        engine.getWorldBuilder().setState(BuilderState.NONE);

        buildingMenu.setIcon(new ImageIcon(Resources.Instance.bushBuyButton));
        buildingMenu.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, Bush.ID));

        decorationMenu.setIcon(new ImageIcon(Resources.Instance.flowerBuyButton));
        decorationMenu.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, Flower.ID));

        roadMenu.setIcon(new ImageIcon(Resources.Instance.stickBuyButton));
        roadMenu.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, Stick.ID));

        stats.setIcon(new ImageIcon(Resources.Instance.firePitBuyButton));
        stats.addActionListener(e -> engine.getWorldBuilder().setState(BuilderState.BUILD, FirePit.ID));

        employeeMenu.setIcon(new ImageIcon(Resources.Instance.shopBackButton));
        employeeMenu.addActionListener(e -> homeButtons());
    }

    private void removeActionListeners()
    {
        for(ActionListener a : buildingMenu.getActionListeners()) buildingMenu.removeActionListener(a);
        for(ActionListener a : decorationMenu.getActionListeners()) decorationMenu.removeActionListener(a);
        for(ActionListener a : roadMenu.getActionListeners()) roadMenu.removeActionListener(a);
        for(ActionListener a : stats.getActionListeners()) stats.removeActionListener(a);
        for(ActionListener a : employeeMenu.getActionListeners()) employeeMenu.removeActionListener(a);
    }

    private String getNiceTime(int sec)
    {
        int dayTime = sec % (24*60*60);
        int hours = dayTime / 60;
        int minutes = dayTime % 60;
        if(hours < 10 && minutes < 10) {
            return "0" + hours + ":" + "0" + minutes;
        } else if(hours < 10 && minutes >= 10) {
            return "0" + hours + ":" + minutes;
        } else if(hours >= 10 && minutes < 10) {
            return hours + ":" + "0" + minutes;
        } else {
            return hours + ":" + minutes;
        }
    }


    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.gameHudImage, 0, 0, this);
    }

}
