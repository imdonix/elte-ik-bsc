/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arkanoid;

import java.awt.Dimension;
import javax.swing.JFrame;

/**
 *
 * @author bli
 */
public class ArkanoidGUI {
    private JFrame frame;
    private GameEngine gameArea;

    public ArkanoidGUI() {
        frame = new JFrame("Arkanoid");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        gameArea = new GameEngine();
        frame.getContentPane().add(gameArea);
        
        frame.setPreferredSize(new Dimension(800, 600));
        frame.setResizable(false);
        frame.pack();
        frame.setVisible(true);
    }
    
    
}
