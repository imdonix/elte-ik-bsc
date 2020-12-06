package tron;

import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.AbstractAction;
import javax.swing.JPanel;
import javax.swing.KeyStroke;
import javax.swing.Timer;


@SuppressWarnings("serial")
public class GameEngine extends JPanel 
{
    private final int HEAD = 20;
    private final int GRID = 30;
    private final Player[] players;
    private final Timer timer;
    private final IWin onWin;
    private boolean paused;
    private boolean end;
    private int time;

    public GameEngine(IWin onWin) 
    {
        super();
        this.onWin = onWin;
        paused = false;
        end = true;
        registerKeyStrokes();    
        players = new Player[2];
        timer = new Timer(1000, new NewFrameListener());
        timer.start();
    }
    
    public void startNew(Player p1, Player p2)
    {
    	players[0] = p1;
    	players[1] = p2;
    	end = false;
    	paused = false;
    	time = 0;
    }
    
    private void registerKeyStrokes()
    {
    	RegisterKeyStroke("LEFT", 0, Point.left);
    	RegisterKeyStroke("RIGHT", 0, Point.right);
    	RegisterKeyStroke("UP", 0, Point.up);
    	RegisterKeyStroke("DOWN", 0, Point.down);
    	RegisterKeyStroke("A", 1, Point.left);
    	RegisterKeyStroke("D", 1, Point.right);
    	RegisterKeyStroke("W", 1, Point.up);
    	RegisterKeyStroke("S", 1, Point.down);
    	RegisterPause();
    }
    
    private void RegisterPause()
    {
        this.getInputMap().put(KeyStroke.getKeyStroke("ESCAPE"), "escape");
        this.getActionMap().put("escape", new AbstractAction() {
            @Override public void actionPerformed(ActionEvent ae) {paused = !paused;}
        });
    }
    
	private void RegisterKeyStroke(String key, int id, Point dir)
    {
    	String keyID = "pressed " + key;
    	this.getInputMap().put(KeyStroke.getKeyStroke(key), keyID);
        this.getActionMap().put(keyID, new AbstractAction() 
        {
            @Override
            public void actionPerformed(ActionEvent e) 
            {
            	final int i = id;
            	players[i].setDirection(dir);
            }
        });
    }
    
    private void nextFrame()
    {
    	for(Player p : players) 
    		p.move();
    }
    
    private boolean isOver()
    {
    	return getWinner() != null;
    }
        
    private Player getWinner()
    {
    	if(players[0].contain(players[1].getPosition()) || !isIn(players[1].getPosition()))
    		return players[0];
    	if(players[1].contain(players[0].getPosition()) || !isIn(players[0].getPosition()))
    		return players[1];
    	return null;    	
    }
    
    private boolean isIn(Point p)
    {
    	return p.x >= 0 && p.x < GRID && p.y >= 0 && p.y < GRID;
    }    
    
    private void PopWinner()
    {
    	end = true;
    	onWin.Win(getWinner(), time);
    }
    
    @Override
    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        g.clearRect(0, 0, GRID*HEAD, GRID*HEAD);
        g.drawRect(0, 0, GRID*HEAD, GRID*HEAD);
        for(Player p : players)
        	if(p != null)
        		p.draw(g);
    }

    class NewFrameListener implements ActionListener 
    {

        @Override
        public void actionPerformed(ActionEvent e) 
        {
        	if(end) return;
        	
            if(!paused) nextFrame();       	
            if(isOver()) PopWinner();
            time++;
            
            repaint();
        }

    }
}