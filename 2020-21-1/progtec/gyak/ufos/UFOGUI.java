/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ufos;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

/**
 *
 * @author bli
 */
public class UFOGUI {

    private JFrame frame;
    private DrawArea drawArea;
    private ArrayList<UFO> ufos;
    private final Timer timer;
    private final Timer colorTimer;

    public UFOGUI(int numUFOs) {
        frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ufos = new ArrayList<>();
        for (int i = 0; i < numUFOs; i++) {
            ufos.add(new UFO());
        }
        drawArea = new DrawArea(ufos);
        drawArea.setPreferredSize(new Dimension(400, 400));
        frame.getContentPane().add(BorderLayout.CENTER, drawArea);
        JPanel buttonPanel = new JPanel();
        JButton backgroundButton = new JButton("Change background");
        backgroundButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                drawArea.updateBackground();
            }
        });
        buttonPanel.add(backgroundButton);
        for (int amount : new Integer[]{-1000, -100, -10, -1, 1, 10, 100, 1000}) {
            JButton button = new JButton(String.valueOf(amount));
            button.addActionListener(new UFOAdder(amount));
            buttonPanel.add(button);
        }
        frame.getContentPane().add(BorderLayout.SOUTH, buttonPanel);
        timer = new Timer(30, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                Dimension d = drawArea.getSize();
                for (UFO ufo : ufos) {
                    ufo.move(d.width, d.height);
                }
                frame.repaint();
            }
        });
        colorTimer = new Timer(10, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                for (UFO ufo : ufos) {
                    if (Math.random() < 1e-3) {
                        ufo.updateColor();
                    }
                }
            }
        });
        colorTimer.start();
        timer.start();
        frame.setSize(500, 500);
        frame.pack();
        frame.setVisible(true);
    }

    class UFOAdder implements ActionListener {

        private final int amount;

        public UFOAdder(int amount) {
            this.amount = amount;
        }

        @Override
        public void actionPerformed(ActionEvent ae) {
            if (amount > 0) {
                for (int i = 0; i < amount; i++) {
                    ufos.add(new UFO());
                }
            } else {
                for (int i = 0; i < -amount; i++) {
                    if (!ufos.isEmpty()) {
                        ufos.remove(0);
                    }
                }
            }
        }
    }

}