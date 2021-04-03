package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.utils.Utils;

import javax.swing.*;

import static java.lang.Math.round;

public class HappinessMeter
{
    public final static int TIMES = Engine.TARGET_FRAME_RATE;

    private static ImageIcon empty = new ImageIcon(Resources.Instance.gameHappyArrowEmpty);
    private static ImageIcon up = new ImageIcon(Resources.Instance.gameHappyArrowUp);
    private static ImageIcon down = new ImageIcon(Resources.Instance.gameHappyArrowDown);


    private int count;
    private float sum;

    private float before;
    private ImageIcon beforeImage;

    public HappinessMeter()
    {
        this.before = 0;
        this.beforeImage = empty;
        reset();
    }

    public void update(float happiness)
    {
        count++;
        sum+=happiness;
        if(count >= TIMES) show();
    }

    private void show()
    {
        float now = sum/count;
        if(Utils.equals(now, before)) beforeImage = empty;
        else beforeImage = (now > before) ? up : down;
        before = now;
        reset();
    }

    private void reset()
    {
        count = 0;
        sum = 0;
    }

    public String getText()
    {
        return String.format("%d", round(before * 100));
    }

    public ImageIcon getImage()
    {
        return beforeImage;
    }
}
