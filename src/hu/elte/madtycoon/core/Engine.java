package hu.elte.madtycoon.core;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class Engine extends JFrame
{
    private static final int GAME_SIZE = 16;
    private static final int BLOCK_SIZE = 50;
    private static final int SCREEN_SIZE = GAME_SIZE * BLOCK_SIZE;

    private static Timer tickTimer;

    private float time;
    private long lastTick;

    public Engine()
    {
        super("Mad Tycoon - Game");
        tickTimer = new Timer(1000/144, this::loop);
        lastTick = System.currentTimeMillis();
        time = 0;


        setPreferredSize(new Dimension(SCREEN_SIZE, SCREEN_SIZE));
        //setUndecorated(true);
        setVisible(true);
        setLocationRelativeTo(null);
        pack();
        tickTimer.start();
    }



    private float time()
    {
        long current = System.currentTimeMillis();
        long delta = current - lastTick;
        lastTick = current;
        return delta / 1000F;
    }

    private void update(float dt)
    {
        //TODO
    }

    private void render(float dt)
    {
        //TODO
    }

    private void loop(ActionEvent event)
    {
        float delta = time();
        time += delta;

        update(delta);
        render(delta);

        repaint();
    }

    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        g.setColor(Color.BLUE);
        g.drawRect(50,50,25,45);
    }
}
