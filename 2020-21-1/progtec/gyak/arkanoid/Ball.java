/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arkanoid;

import java.awt.Image;

/**
 *
 * @author bli
 */
public class Ball extends Sprite {

    private double velx;
    private double vely;

    public Ball(int x, int y, int width, int height, Image image) {
        super(x, y, width, height, image);
        velx = 1;
        vely = 1;
    }

    public void moveX() {
        x += velx;
        if (x + width >= 800 || x <= 0) {
            invertVelX();
        }
    }

    public boolean moveY() {
        y += vely;
        if (y <= 0) {
            invertVelY();
        }
        if (y >= 600) {
            return false;
        }
        return true;
    }

    public void invertVelX() {
        velx = -velx;
    }

    public void invertVelY() {
        vely = -vely;

    }

}
