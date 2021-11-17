package hu.elte.madtycoon.core;

import hu.elte.madtycoon.ui.components.ToggleComponent;
import hu.elte.madtycoon.ui.components.options.ToggleMusicComponent;
import hu.elte.madtycoon.ui.components.options.ToggleSoundComponent;
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
        preview.addContent(new ToggleSoundComponent());
        preview.addContent(new ToggleMusicComponent());
        return preview;
    }

}
