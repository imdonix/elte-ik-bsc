package hu.elte.madtycoon.core;

import hu.elte.madtycoon.Main;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Buildings.CoinFlip;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.ui.HUD;
import hu.elte.madtycoon.ui.IEngine;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.NoCoverageException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Engine extends JFrame implements IEngine
{
    public static final int GAME_SIZE_X = 38;
    public static final int GAME_SIZE_Y = 18;
    public static final int BLOCK_SIZE = 50;
    public static final int RENDER_BASE_CAPACITY = GAME_SIZE_X * GAME_SIZE_Y;

    private final Timer tickTimer;
    private final World world;
    private final Builder builder;

    private final JPanel canvas;
    private final HUD hud;


    private SpriteRenderBuffer renderBuffer;
    private FPSDisplay fpsDisplay;
    private float time;
    private float timeScale;
    private long lastTick;


    public Engine()
    {
        //HUD
        super("Mad Tycoon - Game");
        this.canvas = new GamePanel();
        this.hud = new HUD(this);

        MouseHandler list = new MouseHandler();
        this.canvas.addMouseListener(list);
        this.canvas.addMouseMotionListener(list);
        this.canvas.setPreferredSize(new Dimension(1920, 970));
        this.setLayout(new BorderLayout());
        this.fpsDisplay = new FPSDisplay(30);
        this.setUndecorated(true);
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);
        this.setPreferredSize(Toolkit.getDefaultToolkit().getScreenSize());
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        add(canvas,BorderLayout.NORTH);
        add(hud,BorderLayout.EAST);


        //Engine
        this.tickTimer = new Timer(1000/144, this::loop);
        this.world = new World();
        this.builder = new Builder(world);
        this.renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        this.lastTick = System.currentTimeMillis();
        this.time = 0;
        this.timeScale = 1;

        //Finalize
        pack();
        setVisible(true);
        tickTimer.start();
    }

    private float time()
    {
        long current = System.currentTimeMillis();
        long delta = current - lastTick;
        float deltaTime = delta / 1000F;
        lastTick = current;
        fpsDisplay.record((int) (1F / deltaTime));
        return deltaTime;
    }

    private void loop(ActionEvent event)
    {
        renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        float delta = time() * timeScale;
        time += delta;

        world.update(delta);
        world.render(renderBuffer);

        hud.updateGUI();

        canvas.repaint();
    }

    private void debugDrawGrid(Graphics g)
    {
        g.setColor(Color.blue);
        for (int i = 0; i < GAME_SIZE_X; i++)
            for (int j = 0; j < GAME_SIZE_Y; j++)
                g.drawRect(i*BLOCK_SIZE, j*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    }

    private void debugFPS(Graphics g)
    {
        g.setColor(Color.orange);
        g.drawString(String.format("%o", fpsDisplay.get()),15,15);
    }

    @Override
    public int getMoney()
    {
        return world.getMoney();
    }

    @Override
    public float getOverallHappiness()
    {
        return world.getHappiness();
    }

    @Override
    public int getTime() {
        return (int) time;
    }

    @Override
    public void setTimeScale(float scale)
    {
        timeScale = Utils.clap(0,5, scale);
    }

    @Override
    public Building getSelectedBuilding()
    {
        return world.collisionCheck(builder.getSelected(), Vector2I.ONE);
    }

    @Override
    public float getTimeScale() { return timeScale; }


    class GamePanel extends JPanel
    {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawImage(Resources.Instance.gameBackGroundImage, 0, 0, this);
            if(Main.DEBUG) debugDrawGrid(g);
            if(Main.DEBUG) debugFPS(g);
            renderBuffer.draw(g);
            builder.showMarker(g);
        }
    }

    class MouseHandler implements MouseListener, MouseMotionListener
    {
        @Override
        public void mouseClicked(MouseEvent e) { }

        @Override
        public void mousePressed(MouseEvent e) { }

        @Override
        public void mouseReleased(MouseEvent e)
        {
            try {
                builder.interact();
            } catch (NoCoverageException noCoverageException) {
                //TODO pop no money emote
            }
        }

        @Override
        public void mouseEntered(MouseEvent e) { }

        @Override
        public void mouseExited(MouseEvent e)
        {
            builder.setSelected(null);
        }

        @Override
        public void mouseDragged(MouseEvent e) { }

        @Override
        public void mouseMoved(MouseEvent e) {

            int x = e.getX() / BLOCK_SIZE;
            int y = e.getY() / BLOCK_SIZE;

            builder.setSelected(new Vector2I(x,y));
        }
    }

    class FPSDisplay
    {
        private int counter;
        private int sum;
        private int recorded;
        private int last;

        public FPSDisplay(int recorded)
        {
            this.recorded = recorded;
            this.last = this.counter = this.sum = 0;
        }

        public void record(int fps)
        {
            sum+=fps;
            counter++;

            if(counter >= recorded)
            {
                last = sum/counter;
                counter = sum = 0;
            }
        }

        public int get()
        {
            return last;
        }
    }
}
