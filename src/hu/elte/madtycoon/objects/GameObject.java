package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.LayeredSprite;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.task.ITargetable;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class GameObject implements ITargetable
{
    protected AnimatedSprite sprite;
    protected Vector2F position;
    protected World world;

    private boolean startFrame;
    private boolean active;

    public GameObject(World world, AnimatedSprite sprite, Vector2F position)
    {
        this.world = world;
        this.sprite = sprite;
        this.position = position;
        this.startFrame = false;
        this.active = true;
    }

    public void update(float dt)
    {
        if(active) {
            if (!startFrame) {
                start();
                startFrame = true;
            }

            sprite.update(dt);
        }
    }

    public void setActive(boolean active)
    {
        this.active = active;
    }

    public void render(SpriteRenderBuffer buffer)
    {
        if(active)
            buffer.add(new LayeredSprite(sprite.getSprite(), getRenderLayer(), position));
    }

    public Vector2F getPosition()
    {
        return position;
    }

    public AnimatedSprite getSprite()
    {
        return sprite;
    }

    public Vector2F getTargetPosition()
    {
        return getPosition();
    }

    protected abstract void start();

    protected abstract int getRenderLayer();
}
