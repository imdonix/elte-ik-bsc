/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package databases;

import java.sql.SQLException;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author bli
 */
public class Databases {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String[] names = new String[] {"Peter", "Adrienne", "Ethan", "Jane", "Paul", "Geoffrey", "Joe", "Laura"};                
        try 
	{
            Random random = new Random();
            HighScores highScores = new HighScores(3);
            System.out.println(highScores.getHighScores());
            highScores.putHighScore(names[random.nextInt(names.length)], random.nextInt(100));
            System.out.println(highScores.getHighScores());
        } catch (SQLException ex) 
	{
            Logger.getLogger(Databases.class.getName()).log(Level.SEVERE, null, ex);
        }
    }    
}
