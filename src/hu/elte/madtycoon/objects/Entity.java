package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Entity extends GameObject
{
    protected Entity(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
    }

    @Override
    protected int getRenderLayer() { return 1; }
}
