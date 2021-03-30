package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.GameObject;
import javafx.scene.shape.Box;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.swing.*;
import javax.swing.border.EmptyBorder;


public class GamePanel extends JFrame
{
    private final JPanel panel;

    public GamePanel()
    {
        this.setUndecorated(true);
        this.panel = new ShowPanel();

        this.setContentPane(panel);

        this.setPreferredSize(new Dimension(1220, 773));
        this.pack();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }


    private String floatToPercent(float health)
    {
        return String.format("%d%%", (int) (health * 100));
    }

    @Deprecated
    public GamePanel(Building sb, World world){

        this.setUndecorated(true);
        this.setLayout(new BorderLayout());

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

        String text = "\nHealth :      ";

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
        panel.add(objText);
        panel.add(objText);
        panel.add(objText);
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
        this.add(panel,BorderLayout.CENTER);
        this.setVisible(true);
    }

}
