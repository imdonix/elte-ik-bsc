package hu.elte.madtycoon.render;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;

public class AnimationResource
{
    public static AnimationResource Instance = new AnimationResource();

    private final HashMap<String, BufferedImage[]> resources;
    private int loadedCount;
    private int animsCount;

    private AnimationResource()
    {
        loadedCount = 0;
        animsCount = 0;
        resources = new HashMap<String, BufferedImage[]>();
    }

    public boolean isLoaded() {return loadedCount > 0;}

    public void load() throws RuntimeException
    {
        final File root = new File("res/game");
        if(!root.isDirectory())
            throw new RuntimeException("Cant read game files.");

        for(final File object : root.listFiles())
        {
            if(!object.isDirectory())
                throw new IllegalStateException(String.format("Cant read object files (%s)", object.getName()));
            loadObject(object);
        }
        System.out.println(String.format("[Resources] %o sprite loaded into %o animation", loadedCount ,animsCount));
    }

    private void loadObject(File object)
    {
        for(final File anim : object.listFiles())
        {
            if(!anim.isDirectory())
                throw new IllegalStateException(String.format("Cant read animation files (%s)", anim.getName()));
            loadAnim(anim, object);
            animsCount++;
        }
    }

    private void loadAnim(File anim, File object)
    {
        File[] frameFiles = anim.listFiles();
        BufferedImage[] frames = new BufferedImage[frameFiles.length];
        int i = 0;
        for(final File frame : frameFiles)
        {
            if(!frame.isFile())
                throw new IllegalStateException(String.format("Cant open anim frame (%s)", frame.getName()));
            try
            {
                frames[i++] = ImageIO.read(frame);
                loadedCount++;
            }
            catch (IOException exception)
            {
                throw new IllegalStateException(String.format("Anim frame is corrupted (%s)", frame.getName()));
            }
        }
        resources.put(String.format("%s_%s", object.getName(), anim.getName()), frames);
    }
}
