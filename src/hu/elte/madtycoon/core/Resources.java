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
    public static Resources Instace = new Resources();

    public BufferedImage menuBackGroundImage;
    public BufferedImage menuPlayButton;
    public BufferedImage menuSettingsButton;
    public BufferedImage menuCreditsButton;
    public BufferedImage menuExitButton;

    public BufferedImage gameBackGroundImage;
    public BufferedImage gameHudImage;
    public BufferedImage gameExitButton;

    public List<String> entityNames;

    private Resources() {}

    public void load() throws IOException
    {
        loadMenu();
        loadGame();
    }

    private void loadMenu() throws IOException
    {
        menuBackGroundImage = ImageIO.read(new File("res/menu_bg.jpg"));
        menuPlayButton = ImageIO.read(new File("res/menu_play_button.png"));
        menuSettingsButton = ImageIO.read(new File("res/menu_settings_button.png"));
        menuCreditsButton = ImageIO.read(new File("res/menu_credits_button.png"));
        menuExitButton = ImageIO.read(new File("res/menu_exit_button.png"));
    }

    private void loadGame() throws IOException
    {
        gameBackGroundImage = ImageIO.read(new File("res/main_window_bg.jpg"));
        gameHudImage = ImageIO.read(new File("res/main_window_hud.jpg"));
        gameExitButton = ImageIO.read(new File("res/main_window_exit.png"));
        entityNames = Files.readAllLines(Paths.get("res/names.txt"));
    }
}
