package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.ui.components.building.DecorationComponent;
import hu.elte.madtycoon.ui.components.building.DestroyComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

public abstract class Decoration extends Building
{
    public Decoration(World world, AnimatedSprite sprite, Vector2F position, Vector2I size) {
        super(world, sprite, position, size);
    }

    @Override
    protected void start() { }

    @Override
    public void onDestroy() { }

    @Override
    public Preview getPreview()
    {
        Preview preview = new Preview(getName());
        preview.addAction(new DestroyComponent(this));
        preview.addContent(new DecorationComponent(this));

        return preview;
    }
}
