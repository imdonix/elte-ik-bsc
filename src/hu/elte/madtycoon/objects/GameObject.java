package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.LayeredSprite;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class GameObject
{
    protected AnimatedSprite sprite;
    protected Vector2F position;
    protected World world;

    private boolean startFrame;

    public GameObject(World world, AnimatedSprite sprite, Vector2F position)
    {
        this.world = world;
        this.sprite = sprite;
        this.position = position;
        this.startFrame = false;
    }

    public void update(float dt)
    {
        if(!startFrame)
        {
            start();
            startFrame = true;
        }

        sprite.update(dt);
    }

    public void render(SpriteRenderBuffer buffer)
    {
        buffer.add(new LayeredSprite(sprite.getSprite(), getRenderLayer(), position));
    }

    protected abstract void start();

    protected abstract int getRenderLayer();
}
