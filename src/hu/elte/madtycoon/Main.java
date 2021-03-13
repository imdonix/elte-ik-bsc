package hu.elte.madtycoon;

import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.render.AnimationResource;

public class Main {

    public static void main(String[] args) {
        try
        { AnimationResource.Instance.load(); }
        catch (IllegalStateException exception)
        {
            System.out.println(exception.getMessage());
            return;
        }
        MainWindow mainWindow = new MainWindow();
        new Engine();
    }
}
