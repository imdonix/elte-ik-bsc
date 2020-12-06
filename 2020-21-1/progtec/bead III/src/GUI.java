package tron;

import java.awt.Dimension;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

public class GUI 
{
    private final JFrame frame;
    private final GameEngine game;
    private final Database db;

    public GUI() throws SQLException
    {
    	game = new GameEngine((w,t) -> onEnd(w,t));
    	db = new Database();
        frame = new JFrame("Tron");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(game);
        frame.setPreferredSize(new Dimension(617, 640));
        frame.setResizable(false);
        SetUpMenuBar();
        frame.pack();
        frame.setVisible(true);        
    }
    
    private void SetUpMenuBar()
    {
        JMenuBar menuBar = new JMenuBar();
        JMenuItem  start = new JMenuItem("New");
        JMenuItem  toplist = new JMenuItem("Toplist");
        frame.setJMenuBar(menuBar);
        menuBar.add(start);
        menuBar.add(toplist);
        
        start.addActionListener(e -> Start());
        toplist.addActionListener(e -> new Toplist(RequestToplist()));
    }
    
    private void Start()
    {
    	Player p1 = createNewPlayer(1);
    	Player p2 = createNewPlayer(2);
    	if(p1.valid() && p2.valid())
    		game.startNew(p1, p2);
    	else
    		JOptionPane.showMessageDialog(frame, "Please give valid values.");
    }
    
    private void onEnd(Player winner, int time)
    {
    	int wins = saveDatabase(winner);
    	JOptionPane.showMessageDialog(frame, winner.getName() + " win! (Wins: " + wins +  ")\nThe game was "  + time + "sec long.");
    }
    
    private Player createNewPlayer(int i)
    {   
    	
    	String name = (String)JOptionPane.showInputDialog(
                frame,
                "Give player name (" + i + ")",
                "Name select",
                JOptionPane.PLAIN_MESSAGE);
    	
    	ColorName color = (ColorName)JOptionPane.showInputDialog(
    	                    frame,
    	                    "Select color for (" + i + ")",
    	                    "Color select",
    	                    1, null, ColorName.getList(),
    	                    JOptionPane.PLAIN_MESSAGE);
    	
    	if(name == null || color == null)
    		return new Player(null, Point.down, null);
    	else
    		return new Player(name, i == 1 ? new Point(4,8) : new Point(24,8), color.color);
    }
    
    private int saveDatabase(Player winner)
    {
    	try 
    	{
			db.insertWin(winner.getName());
	    	return db.getWins(winner.getName());
		} 
    	catch (SQLException e) 
    	{
    		return 0;
		}
    }
    
    private List<String> RequestToplist()
    {
    	try 
    	{return db.getToplist();} 
    	catch (SQLException e) 
    	{return new ArrayList<String>();}
    	
    }
}
