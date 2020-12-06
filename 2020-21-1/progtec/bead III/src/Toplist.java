package tron;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Toplist extends JFrame
{
	
	private final JPanel panel;
	private final JList<String> toplist; 
	
	public Toplist(List<String> list)
	{
	   super("Toplist");
	   this.panel = new JPanel();
	   this.panel.setLayout( new GridBagLayout() );
	   this.toplist = new JList<String>(list.toArray(new String[10]));
	   this.panel.add(toplist);
	   this.panel.setBackground(Color.white);
	   this.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
	   this.setContentPane(panel);
       this.setPreferredSize(new Dimension(300, 600));
       this.setResizable(false);
       this.pack();
	   this.setVisible( true );
	}	
}
