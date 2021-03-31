package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.ui.components.PreviewComponent;
import hu.elte.madtycoon.utils.Utils;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.Random;

public class ShowPanel extends JPanel
{

    private final Preview preview;
    private final JFrame frame;
    private int scrollIndex;

    public ShowPanel(JFrame frame, Preview preview)
    {
        super(new BorderLayout());
        this.preview = preview;
        this.frame = frame;
        this.addMouseWheelListener(new Listener());
        this.setOpaque(false);
        this.setBorder(new EmptyBorder(120,75,75,75));

        render();
    }


    public void render()
    {
        removeAll();
        showTitle();
        showContent();
        showActionButtons();
        revalidate();
        repaint();
    }

    public void dispose()
    {
        frame.dispose();
    }

    private void showTitle()
    {
        JLabel titleLabel = new JLabel(preview.getName());
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

        for(PreviewComponent comp : preview.getContent())
            contentPanel.add(comp.build(this));

        add(contentPanel, BorderLayout.LINE_START);
    }

    private void showActionButtons()
    {
        JPanel actionPanel = new JPanel(new FlowLayout());
        actionPanel.setOpaque(false);

        for(PreviewActionComponent comp : preview.getActions())
            actionPanel.add(comp.build(this));

        add(actionPanel, BorderLayout.PAGE_END);
    }


    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(Resources.Instance.shopBackGroundImage, 0, 0, this);
    }

    class Listener implements MouseWheelListener
    {

        @Override
        public void mouseWheelMoved(MouseWheelEvent e)
        {
            scrollIndex += e.getWheelRotation();
            scrollIndex = Utils.clamp(0,50,scrollIndex);
            render();
        }
    }
}