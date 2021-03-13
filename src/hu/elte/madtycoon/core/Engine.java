package hu.elte.madtycoon.core;

import hu.elte.madtycoon.render.SpriteRenderBuffer;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class Engine extends JFrame
{
    public static final int GAME_SIZE = 16;
    public static final int BLOCK_SIZE = 50;
    public static final int SCREEN_SIZE = GAME_SIZE * BLOCK_SIZE;
    public static final int RENDER_BASE_CAPACITY = GAME_SIZE * GAME_SIZE;

    private final Timer tickTimer;
    private final World world;

    private SpriteRenderBuffer renderBuffer;
    private float time;
    private long lastTick;

    public Engine()
    {
        super("Mad Tycoon - Game");
        this.tickTimer = new Timer(1000/144, this::loop);
        this.world = new World();
        this.renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        this.lastTick = System.currentTimeMillis();
        this.time = 0;

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

    private void loop(ActionEvent event)
    {
        renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        float delta = time();
        time += delta;

        world.update(delta);
        world.render(renderBuffer);

        repaint();
    }

    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        renderBuffer.draw(g);
    }
}
