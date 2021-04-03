package hu.elte.madtycoon.core;

import hu.elte.madtycoon.ui.components.TextComponent;
import hu.elte.madtycoon.ui.core.Preview;

public class Employment
{
    private final World world;

    public Employment(World world)
    {
        this.world = world;
    }



    public Preview getPreview()
    {
        Preview preview = new Preview("Employment");
        preview.addContent(new TextComponent("Test"));
        return preview;
    }
}
