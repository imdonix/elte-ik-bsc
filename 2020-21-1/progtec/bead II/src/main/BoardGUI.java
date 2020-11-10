package main;


import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import exception.GameOver;
import exception.OutOfRangeException;


public class BoardGUI 
{

    private JButton[][] buttons;
    private Board board;
    private JPanel boardPanel;
    private JLabel massageLabel;
    private boolean end;
    private JMenuItem restart;

    public BoardGUI(JMenuItem restart, int x, int y) 
    {
    	this.restart = restart;
        board = new Board(x,y);
        boardPanel = new JPanel();
        boardPanel.setLayout(new GridLayout(board.getBoardSizeX(), board.getBoardSizeY()));
        buttons = new JButton[board.getBoardSizeX()][board.getBoardSizeY()];

        for (int i = 0; i < board.getBoardSizeX(); ++i) 
            for (int j = 0; j < board.getBoardSizeY(); ++j) 
            {
                JButton button = new JButton();
                button.addActionListener(new ButtonListener(j));
                button.setPreferredSize(new Dimension(50, 50));
                button.setBackground(Color.WHITE);
                
                buttons[i][j] = button;
                boardPanel.add(button);
            }
        
        massageLabel = new JLabel();
        massageLabel.setHorizontalAlignment(JLabel.CENTER);
        massageLabel.setText(" ");
    }


    public void refresh(Point p) throws GameOver 
    {
        JButton button = buttons[p.x][p.y];
        Field field = board.get(p.x, p.y);
        button.setText( Check.ToString(field.getState()));
        
        Check winner = board.getWinner();
        if(!winner.equals(Check.None))
        	throw new GameOver(winner);
        
        if(board.isOver())
        	throw new GameOver(Check.None);
        
        massageLabel.setText("The next player is " + board.getCurrentPlayer());
    }

    
    public JPanel getBoardPanel() 
    {
        return boardPanel;
    }

    public JLabel getMassageLabel() 
    {
        return massageLabel;
    }
    
    
    class ButtonListener implements ActionListener 
    {

        private final int y;

        public ButtonListener(int y) { this.y = y; }

        @Override
        public void actionPerformed(ActionEvent e) 
        { 
        	if(!end)
	        	try 
	        	{
	        		refresh(board.push(y)); 
	        	}
	        	catch(OutOfRangeException ex)
	        	{
	        		massageLabel.setText("The colum is full");
	        	}
	        	catch(GameOver ex)
	        	{
	        		end = true;
	        		
	        		StringBuilder str = new StringBuilder("Game over | ");
	        		if(ex.getWinner().equals(Check.None))
	        			str.append("Draw");
	        		else
	        			str.append( ex.getWinner().toString() + " won");
	        		
	        		
	        		JOptionPane.showMessageDialog(boardPanel, str.toString());
	        		restart.doClick();
	        	}
       	
        }
    }

}
