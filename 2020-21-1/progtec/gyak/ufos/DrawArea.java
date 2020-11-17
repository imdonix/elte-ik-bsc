/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ufos;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 *
 * @author bli
 */
class DrawArea extends JPanel {

    private ArrayList<UFO> ufos;
    private Color background = Color.WHITE;

    public DrawArea(ArrayList<UFO> UFOs) {
        this.ufos = UFOs;
        this.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent me) {
                for (UFO ufo : ufos) {
                    ufo.movePosition(me.getX()-100, me.getY());
                }                
            }

            @Override
            public void mouseMoved(MouseEvent me) {
            }
        });
    }

    @Override
    protected void paintComponent(Graphics grphcs) {
        super.paintComponent(grphcs);
        Graphics2D g2 = (Graphics2D) grphcs;
        setBackground(background);
        for (UFO ufo : ufos) {
            ufo.draw(g2);
        }
    }

    public void updateBackground() {
        background = new Color((float)Math.random(), (float)Math.random(), (float)Math.random());
    }
}