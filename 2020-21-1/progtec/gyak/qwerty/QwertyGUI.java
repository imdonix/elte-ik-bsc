package qwerty;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author pinter
 */
public class QwertyGUI {

    private JFrame frame;
    private JPanel displayPanel;
    private JPanel buttonPanel;
    private JTextField display;

    public QwertyGUI() {
        frame = new JFrame("QWERTY");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        displayPanel = new JPanel();
        display = new JTextField(36);
        displayPanel.add(display);
        frame.getContentPane().add(displayPanel, BorderLayout.NORTH);

        buttonPanel = new JPanel();
        String[] buttonTexts = new String[]{"Q", "W", "E", "R", "T", "Y", "Back", "CLR"};
        for (String buttonText : buttonTexts) {
            JButton b = new JButton(buttonText);
            switch (buttonText) {
                case "Back":
                    b.addActionListener(new BackspaceActionListener());
                    break;
                case "CLR":
                    b.addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            display.setText("");
                        }
                    });
                    break;
                default:
                    b.addActionListener(new QwertyListener(buttonText));
                    break;
            }
            buttonPanel.add(b);
        }
        frame.getContentPane().add(buttonPanel, BorderLayout.SOUTH);

        JMenuBar menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);
        JMenu calcMenu = new JMenu("QWERTY");
        menuBar.add(calcMenu);
        JMenuItem exitMenuItem = new JMenuItem("Exit");
        calcMenu.add(exitMenuItem);
        exitMenuItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                System.exit(0);
            }
        });        
        
        frame.pack();
        frame.setVisible(true);
    }

    class QwertyListener implements ActionListener {

        private String button;

        public QwertyListener(String button) {
            this.button = button;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String text = display.getText();
            display.setText(text + button);
        }

    }

    class BackspaceActionListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String text = display.getText();
            if (!text.isEmpty()) {
                display.setText(text.substring(0, text.length() - 1));
            }
        }

    }

}
