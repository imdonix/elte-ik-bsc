/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arkanoid;

import java.awt.Graphics;
import java.awt.Image;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import javax.swing.ImageIcon;

/**
 *
 * @author bli
 */
public class Level {

    // each brick is 40x20, so there can be at most 20 bricks side by side
    // the last 10 rows will be empty, so there can be at most 20 rows of bricks
    private final int BRICK_WIDTH = 40;
    private final int BRICK_HEIGHT = 20;
    ArrayList<Brick> bricks;

    public Level(String levelPath) throws IOException {
        loadLevel(levelPath);
    }

    public void loadLevel(String levelPath) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader(levelPath));
        bricks = new ArrayList<>();
        int y = 0;
        String line;
        while ((line = br.readLine()) != null) {
            int x = 0;
            for (char blockType : line.toCharArray()) {
                if (Character.isDigit(blockType)) {
                    Image image = new ImageIcon("data/images/brick0" + blockType + ".png").getImage();
                    bricks.add(new Brick(x * BRICK_WIDTH, y * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT, image));
                }
                x++;
            }
            y++;
        }
    }

    public boolean collides(Ball ball) {
        Brick collidedWith = null;
        for (Brick brick : bricks) {
            if (ball.collides(brick)) {
                collidedWith = brick;
                break;
            }
        }
        if (collidedWith != null) {
            bricks.remove(collidedWith);
            return true;
        } else {
            return false;
        }
    }
    
    public boolean isOver() {
        return bricks.isEmpty();
    }

    public void draw(Graphics g) {
        for (Brick brick : bricks) {
            brick.draw(g);
        }
    }

}
