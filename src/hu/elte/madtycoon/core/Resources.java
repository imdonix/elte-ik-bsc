package hu.elte.madtycoon.core;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Resources
{
    public static Resources Instace = new Resources();

    public BufferedImage gameBackGroundImage;
    public BufferedImage gameHudImage;

    private boolean loaded;

    private Resources()
    {
        loaded = false;
    }

    public void load() throws IOException
    {
        gameBackGroundImage = ImageIO.read(new File("res/main_window_bg.jpg"));
        gameHudImage = ImageIO.read(new File("res/main_window_hud.jpg"));

        loaded = true;
    }

}
