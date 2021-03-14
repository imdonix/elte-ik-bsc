package hu.elte.madtycoon.core;

import hu.elte.madtycoon.Main;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Vector2I;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

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

    private Vector2I selectedBlock;
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
                    g.drawImage(Resources.Instance.gameHudImage, 0, 0, this);
                }
        };
        this.hud.setPreferredSize(new Dimension(1920,110));

        JButton exit = new JButton();
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> System.exit(0));
        exit.setMargin(new Insets(25, 0, 0, 0));


        this.hud.add(exit);


        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));


        this.canvas.addMouseListener(new ClickListener());
        this.tickTimer = new Timer(1000/144, this::loop);
        this.world = new World();
        this.renderBuffer = new SpriteRenderBuffer(RENDER_BASE_CAPACITY);
        this.lastTick = System.currentTimeMillis();
        this.setLayout(new BorderLayout());
        this.time = 0;
        this.selectedBlock = null;

        add(canvas,BorderLayout.NORTH);
        add(hud,BorderLayout.EAST);
        canvas.setPreferredSize(new Dimension(1920, 970));
        this.setUndecorated(true); // if exit btn added
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

    private void debugDrawGrid(Graphics g)
    {
        g.setColor(Color.blue);
        for (int i = 0; i < GAME_SIZE_X; i++)
            for (int j = 0; j < GAME_SIZE_Y; j++)
                g.drawRect(i*BLOCK_SIZE, j*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

        if(selectedBlock != null)
        {
            g.setColor(Color.red);
            g.drawRect(selectedBlock.x*BLOCK_SIZE, selectedBlock.y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        }
    }

    private void debugDrawSelected(Graphics g)
    {
        g.setColor(Color.red);
        if(selectedBlock != null)
            g.drawRect(selectedBlock.x*BLOCK_SIZE, selectedBlock.y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    }



    class GamePanel extends JPanel
    {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.drawImage(Resources.Instance.gameBackGroundImage, 0, 0, this);
            if(Main.DEBUG) debugDrawGrid(g);
            if(Main.DEBUG) debugDrawSelected(g);
            renderBuffer.draw(g);
        }


    }

    class ClickListener implements MouseListener
    {
        @Override
        public void mouseClicked(MouseEvent e) {
            int x=e.getX();
            int y=e.getY();
            System.out.println(x+","+y);//these co-ords are relative to the component
        }

        @Override
        public void mousePressed(MouseEvent e)
        {
            int x = e.getX() / BLOCK_SIZE;
            int y = e.getY() / BLOCK_SIZE;

            selectedBlock = new Vector2I(x,y);
        }

        @Override
        public void mouseReleased(MouseEvent e) { }

        @Override
        public void mouseEntered(MouseEvent e) { }

        @Override
        public void mouseExited(MouseEvent e)
        {
            selectedBlock = null;
        }
    }
}
