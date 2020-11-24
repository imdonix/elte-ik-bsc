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
public class Paddle extends Sprite {

    private double velx;

    public Paddle(int x, int y, int width, int height, Image image) {
        super(x, y, width, height, image);
    }

    public void move() {
        if ((velx < 0 && x > 0) || (velx > 0 && x + width <= 800)) {
            x += velx;
        }
    }

    public double getVelx() {
        return velx;
    }

    public void setVelx(double velx) {
        this.velx = velx;
    }
}
