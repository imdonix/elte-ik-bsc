package main;

import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class GUI 
{

    private JFrame frame;
    private BoardGUI boardGUI;
    private final int[][] sizes = {{5,8}, {6,10}, {7,12}};
    
    public GUI() 
    {
        frame = new JFrame("Amőba");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JMenuBar menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);
        
        JMenu gameMenu = new JMenu("Game");
        menuBar.add(gameMenu);
        
        JMenu newMenu = new JMenu("New");
        gameMenu.add(newMenu);
        
        for(int i = 0; i < sizes.length; i++) 
        {
        	int x = sizes[i][0];
        	int y = sizes[i][1];
        	
            JMenuItem sizeMenuItem = new JMenuItem( y + "x" + x );
            newMenu.add(sizeMenuItem);
            
            sizeMenuItem.addActionListener(event ->
            {
                    frame.getContentPane().remove(boardGUI.getBoardPanel());
                    frame.getContentPane().remove(boardGUI.getMassageLabel());
                   
                    boardGUI = new BoardGUI(sizeMenuItem, x, y);
                    
                    frame.getContentPane().add(boardGUI.getBoardPanel(),BorderLayout.CENTER);
                    frame.getContentPane().add(boardGUI.getMassageLabel(), BorderLayout.SOUTH);
                    frame.pack();
            });
        }
        
        boardGUI = new BoardGUI(newMenu.getItem(0), sizes[0][0],sizes[0][1]);
        frame.getContentPane().add(boardGUI.getBoardPanel(), BorderLayout.CENTER);
        frame.getContentPane().add(boardGUI.getMassageLabel(), BorderLayout.SOUTH);
        
        JMenuItem exitMenuItem = new JMenuItem("Exit");
        exitMenuItem.addActionListener((y) -> System.exit(0));
        gameMenu.add(exitMenuItem);

        frame.pack();
        frame.setVisible(true);
    }
}