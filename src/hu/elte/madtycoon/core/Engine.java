package hu.elte.madtycoon.core;

import hu.elte.madtycoon.render.SpriteRenderBuffer;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.File;
import java.io.IOException;

public class Engine extends JFrame
{
    public static final int GAME_SIZE_X = 24;
    public static final int GAME_SIZE_Y = 16;
    public static final int BLOCK_SIZE = 50;
    public static final int SCREEN_SIZE_X = GAME_SIZE_X * BLOCK_SIZE;
    public static final int SCREEN_SIZE_Y = GAME_SIZE_Y * BLOCK_SIZE;
    public static final int RENDER_BASE_CAPACITY = GAME_SIZE_X * GAME_SIZE_Y;

    private final Timer tickTimer;
    private final World world;
    private final JPanel canvas;
    private final JPanel hud;

    private SpriteRenderBuffer renderBuffer;
    private float time;
    private long lastTick;

    public Engine()
    {
        super("Mad Tycoon - Game");
        this.canvas = new GamePanel();

        this.hud = new JPanel(){
                @Override
                public void paintComponent(Graphics g) {
                    super.paintComponent(g);
                    Image img = Toolkit.getDefaultToolkit().getImage("res/main_window_hud.jpg");
                    g.drawImage(img, 0, 0, this);
                }
        };
        this.hud.setPreferredSize(new Dimension(1920,110));
        this.tickTimer = new Timer(1000/144, this::loop);
        this.world = new World();
        this.renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        this.lastTick = System.currentTimeMillis();
        this.setLayout(new BorderLayout());
        this.time = 0;

        add(canvas,BorderLayout.NORTH);
        add(hud,BorderLayout.EAST);
        canvas.setPreferredSize(new Dimension(1920, 970));
        //this.setUndecorated(true); remove // if exit btn added
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        this.setPreferredSize(screenSize);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
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

        canvas.repaint();
    }

    class GamePanel extends JPanel
    {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Image img = Toolkit.getDefaultToolkit().getImage("res/main_window_bg.jpg");
            g.drawImage(img,0, 0, this);
            renderBuffer.draw(g);
        }
    }

}
