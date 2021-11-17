package hu.elte.madtycoon.render;

import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;

public class LayeredSprite implements Comparable<LayeredSprite>
{
    public final BufferedImage sprite;
    public final int layer;
    public final Vector2F pos;

    public LayeredSprite(BufferedImage sprite, int layer, Vector2F pos)
    {
        this.sprite = sprite;
        this.layer = layer;
        this.pos = pos;
    }


    @Override
    public int compareTo(LayeredSprite object)
    {
        if(layer == object.layer)
            return (int) (Math.floor(pos.y * 10) - Math.floor(object.pos.y * 10));
        else
            return layer - object.layer;
    }
}
