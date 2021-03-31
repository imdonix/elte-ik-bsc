package hu.elte.madtycoon.ui.core;

import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.ui.components.PreviewActionComponent;
import hu.elte.madtycoon.utils.Utils;
import javafx.scene.shape.Box;

import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.swing.*;
import javax.swing.border.EmptyBorder;


public class PreviewFrame extends JFrame
{

    private final ShowPanel panel;

    public PreviewFrame(Preview preview) {

        this.panel = new ShowPanel(this, preview);
        this.setContentPane(panel);
        this.setAlwaysOnTop(true);

        this.setPreferredSize(new Dimension(1220, 773));
        this.setUndecorated(true);
        this.pack();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public void update()
    {
        panel.render();
    }

}
