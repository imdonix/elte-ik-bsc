package hu.elte.madtycoon.ui.core;

import java.awt.*;
import javax.swing.*;


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
