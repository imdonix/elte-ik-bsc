package hu.elte.madtycoon.core;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Resources
{
    public static Resources Instance = new Resources();

    public BufferedImage menuBackGroundImage;
    public BufferedImage menuPlayButton;
    public BufferedImage menuSettingsButton;
    public BufferedImage menuCreditsButton;
    public BufferedImage menuExitButton;

    public BufferedImage gameBackGroundImage;
    public BufferedImage gameHudImage;
    public BufferedImage gameExitButton;
    public BufferedImage gameHouseBuildButton;
    public BufferedImage gameDecorBuildButton;
    public BufferedImage gameRoadBuildButton;
    public BufferedImage gameStatisticsButton;
    public BufferedImage gameEmployeeButton;
    public BufferedImage gameMoneyIcon;
    public BufferedImage gameSanityIcon;
    public BufferedImage gameTimeIcon;
    public BufferedImage gamePlayButton;
    public BufferedImage gameSpeedButton;
    public BufferedImage gameSpeedButton2X;
    public BufferedImage gameSpeedButton5X;
    public BufferedImage gameSettingsButton;
    public BufferedImage gamePauseButton;
    public BufferedImage gameHappyArrowUp;
    public BufferedImage gameHappyArrowDown;
    public BufferedImage gameHappyArrowEmpty;

    public BufferedImage shopBackGroundImage;
    public BufferedImage shopCoinFlipBuyButton;
    public BufferedImage shopBackButton;
    public BufferedImage sthBuyButton;
    public BufferedImage bushBuyButton;
    public BufferedImage flowerBuyButton;
    public BufferedImage stickBuyButton;
    public BufferedImage firePitBuyButton;

    public List<String> entityNames;

    private Resources() {}

    public void load() throws IOException
    {
        loadMenu();
        loadGame();
        loadShop();
    }

    private void loadMenu() throws IOException
    {
        menuBackGroundImage = ImageIO.read(new File("res/menu/bg.jpg"));
        menuPlayButton = ImageIO.read(new File("res/menu/play_button.png"));
        menuSettingsButton = ImageIO.read(new File("res/menu/settings_button.png"));
        menuCreditsButton = ImageIO.read(new File("res/menu/credits_button.png"));
        menuExitButton = ImageIO.read(new File("res/menu/exit_button.png"));
    }

    private void loadGame() throws IOException
    {
        gameBackGroundImage = ImageIO.read(new File("res/main_window_bg.jpg"));
        gameHudImage = ImageIO.read(new File("res/main_window_hud.jpg"));
        gameExitButton = ImageIO.read(new File("res/main_window_exit.png"));
        gameHouseBuildButton = ImageIO.read(new File("res/menu/house_build_button.png"));
        gameDecorBuildButton = ImageIO.read(new File("res/menu/decor_build_button.png"));
        gameRoadBuildButton = ImageIO.read(new File("res/menu/road_build_button.png"));
        gameStatisticsButton = ImageIO.read(new File("res/menu/stats_button.png"));
        gameEmployeeButton = ImageIO.read(new File("res/menu/employee_button.png"));
        gameMoneyIcon = ImageIO.read(new File("res/menu/money_icon.png"));
        gameSanityIcon = ImageIO.read(new File("res/menu/sanity_icon.png"));
        gameTimeIcon = ImageIO.read(new File("res/menu/time_icon.png"));
        gamePlayButton = ImageIO.read(new File("res/menu/start_pause_button.png"));
        gamePauseButton = ImageIO.read(new File("res/menu/pause_button.png"));
        gameSpeedButton = ImageIO.read(new File("res/menu/speed_up_button.png"));
        gameSpeedButton2X = ImageIO.read(new File("res/menu/speed_up_button_2x.png"));
        gameSpeedButton5X = ImageIO.read(new File("res/menu/speed_up_button_5x.png"));
        gameSettingsButton = ImageIO.read(new File("res/menu/game_settings_button.png"));
        gameHappyArrowUp = ImageIO.read(new File("res/menu/happy_up.png"));
        gameHappyArrowDown = ImageIO.read(new File("res/menu/happy_down.png"));
        gameHappyArrowEmpty = ImageIO.read(new File("res/menu/happy_empty.png"));
        entityNames = Files.readAllLines(Paths.get("res/names.txt"));
    }

    private void loadShop() throws IOException
    {
        shopBackGroundImage = ImageIO.read(new File("res/menu/shop/shop_bg.png"));

        shopCoinFlipBuyButton = ImageIO.read(new File("res/menu/coin_flip_buy.png"));
        shopBackButton = ImageIO.read(new File("res/menu/shop_back.png"));
        sthBuyButton = ImageIO.read(new File("res/menu/sth_buy.png"));
        bushBuyButton = ImageIO.read(new File("res/menu/bush_buy.png"));
        flowerBuyButton = ImageIO.read(new File("res/menu/flower_buy.png"));
        stickBuyButton = ImageIO.read(new File("res/menu/stick_buy.png"));
        firePitBuyButton = ImageIO.read(new File("res/menu/firepit_buy.png"));
    }
}
