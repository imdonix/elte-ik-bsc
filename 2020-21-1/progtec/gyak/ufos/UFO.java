/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ufos;

import java.awt.Color;
import java.awt.Graphics2D;

/**
 *
 * @author bli
 */
public class UFO {
    
    private double x;
    private double y;
    private final double velx;
    private final double vely;
    
    private Color color;

    public UFO() {
        x = Math.random()*2000;
        y = Math.random()*2000;
        velx = Math.random()*4 - 2;
        vely = Math.random()*4 - 2;
        updateColor();
    }
    
    public void draw(Graphics2D g2) {
        g2.setColor(color);
        g2.fillOval((int)x + 75, (int) y-25, 50, 50);
        g2.setColor(color.darker());
        g2.fillOval((int)x, (int)y, 200, 30);
    }
    
    public void move(int width, int height) {
        x += velx;
        if (x > width) {
            x = 0;
        }
        if (x < 0) {
            x = width;
        }
        y += vely;
        if (y > height) {
            y = 0;
        }
        if (y < 0) {
            y = height;
        }
    }
    
    public void movePosition(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public final void updateColor() {
        color = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
    }
    
}