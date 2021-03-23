package hu.elte.madtycoon.ui;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.GameObject;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import javax.swing.*;
import javax.swing.border.EmptyBorder;


public class PopWindow extends JFrame{
    private final JButton exit;
    private JPanel panel;
    private World world;

    public PopWindow(){

        this.setUndecorated(true);

        exit = new JButton();
        exit.setMargin(new Insets(25, 1100, 0, 0));
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> this.dispose());
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        this.setPreferredSize(new Dimension(1220,773));
        this.setResizable(false);
        this.pack();
        this.setContentPane(new JPanel() {
            @Override
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(Resources.Instance.shopBackGroundImage, 0, 0, this);
            }
        });
        this.setLocationRelativeTo(null);
        this.add(exit);
        this.setVisible(true);
    }

    public PopWindow(Building sb, World world){

        this.setUndecorated(true);
        this.setLayout(new BorderLayout());
        exit = new JButton();
        exit.setMargin(new Insets(25, 1100, 0, 0));
        exit.setOpaque(false);
        exit.setContentAreaFilled(false);
        exit.setBorderPainted(false);
        exit.addActionListener(e -> this.dispose());
        exit.setIcon(new ImageIcon(Resources.Instance.gameExitButton));

        panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.setOpaque(false);
        panel.setBorder(new EmptyBorder(20,0,0,0));

        JLabel objName = new JLabel(sb.getClass().getSimpleName());
        objName.setForeground(Color.decode("#1c1710"));
        objName.setFont(Resources.Instance.chBell);

        JTextPane objText = new JTextPane();
        objText.setPreferredSize(new Dimension(900,450));
        objText.setOpaque(false);
        objText.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
        objText.setEditable(false);

        String text = "\nHealth :      " + sb.getHealth();

        objText.setText(text);
        objText.setForeground(Color.decode("#1c1710"));
        objText.setFont(Resources.Instance.chBell);

        JButton delete = new JButton();
        delete.setOpaque(false);
        delete.setContentAreaFilled(false);
        delete.setBorderPainted(false);
        delete.setIcon(new ImageIcon(Resources.Instance.destroyButton));
        delete.addActionListener(e -> {
            world.destroy(sb);
            this.dispose();
        });
        panel.add(delete,BorderLayout.PAGE_END);
        panel.add(objText, BorderLayout.CENTER);
        panel.add(objName, BorderLayout.NORTH);

        this.setPreferredSize(new Dimension(1220,773));
        this.setResizable(false);
        this.pack();
        this.setContentPane(new JPanel() {
            @Override
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawImage(Resources.Instance.shopBackGroundImage, 0, 0, this);
            }
        });
        this.setLocationRelativeTo(null);
        this.add(exit,BorderLayout.PAGE_START);
        this.add(panel,BorderLayout.CENTER);
        this.setVisible(true);
    }
}
