package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.core.Resources;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.util.Random;

class ShowPanel extends JPanel
{

    public ShowPanel()
    {
        super(new BorderLayout());
        setOpaque(false);
        setBorder(new EmptyBorder(120,75,75,75));


        showTitle("Hello");
        showContent();
        showActionButtons();

    }


    private void showTitle(String title)
    {
        JLabel titleLabel = new JLabel(title);
        titleLabel.setHorizontalAlignment(0);
        titleLabel.setForeground(Color.decode("#1c1710"));
        titleLabel.setFont(Resources.Instance.chBell);
        add(titleLabel, BorderLayout.NORTH);
    }

    private void showContent()
    {
        JPanel contentPanel = new JPanel();
        contentPanel.setBorder(new EmptyBorder(40,20,40,20));
        contentPanel.setOpaque(false);
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));


        Random rand = new Random();
        for(int i = 0; i < 10; i++)
        {
            JPanel p = new JPanel();
            p.setLayout(new FlowLayout());
            p.setBackground(new Color(rand.nextInt(0xFFFFFF)));

            for (int j = 0; j < 20; j++)
            {
                JLabel text = new JLabel(new Integer(j).toString());
                text.setForeground(Color.decode("#1c1710"));
                text.setFont(Resources.Instance.chBell);

                p.add(text, j);
            }


            contentPanel.add(p, Component.LEFT_ALIGNMENT);

        }

        add(contentPanel, BorderLayout.LINE_START);
    }

    private void showActionButtons()
    {
        JPanel actionPanel = new JPanel(new FlowLayout());
        actionPanel.setOpaque(false);

        for(int i = 0; i < 5; i++)
        {
            JButton action = new JButton();
            action.setOpaque(false);
            action.setContentAreaFilled(false);
            action.setBorderPainted(false);
            action.setIcon(new ImageIcon(Resources.Instance.destroyButton));
            actionPanel.add(action);
        }

        add(actionPanel, BorderLayout.PAGE_END);
    }


    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.shopBackGroundImage, 0, 0, this);
    }
}