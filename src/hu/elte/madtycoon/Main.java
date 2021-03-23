package hu.elte.madtycoon;

import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.ui.Menu;

import java.awt.*;
import java.io.IOException;

public class Main
{

    public static boolean DEBUG = false;

    public static void main(String[] args)
    {
        try
        {
            Resources.Instance.load();
            AnimationResource.Instance.load();
        }
        catch (IOException exception)
        {
            System.out.println("IO:" + exception.getMessage());
            return;
        }
        catch (IllegalStateException exception)
        {
            System.out.println(exception.getMessage());
            return;
        }
        catch (FontFormatException e)
        {
            System.out.println(e.getMessage());
            return;
        }

        if(DEBUG)
            new Engine();
        else
            new Menu();
    }
}
