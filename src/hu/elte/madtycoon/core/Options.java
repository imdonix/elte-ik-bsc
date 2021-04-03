package hu.elte.madtycoon.core;

import hu.elte.madtycoon.ui.core.Preview;

public class Options
{
    private final Engine engine;

    public Options(Engine engine)
    {
        this.engine = engine;
    }

    public Preview getPreview()
    {
        Preview preview = new Preview("Options");
        return preview;
    }

    //TODO ???
}
