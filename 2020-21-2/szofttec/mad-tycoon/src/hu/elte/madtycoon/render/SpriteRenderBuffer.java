package hu.elte.madtycoon.render;


import hu.elte.madtycoon.Main;
import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.utils.MinHeap;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.*;

public class SpriteRenderBuffer extends MinHeap<LayeredSprite>
{
    public SpriteRenderBuffer(int capacity) {
        super(capacity);
    }

    public void draw(Graphics g)
    {
        while(!isEmpty())
        {
            LayeredSprite next = rem();
            Vector2I pixelPos = VectorToScreenPosition(next.pos);
            g.drawImage(next.sprite, pixelPos.x, pixelPos.y, null);
        }
    }

    private Vector2I VectorToScreenPosition(Vector2F v)
    {
        int baseX = (int) Math.floor(v.x);
        int baseY = (int) Math.floor(v.y);
        int inX = (int) ((v.x - baseX) * Engine.BLOCK_SIZE);
        int inY = (int) ((v.y - baseY) * Engine.BLOCK_SIZE);
        return new Vector2I(baseX * Engine.BLOCK_SIZE + inX, baseY * Engine.BLOCK_SIZE + inY);
    }
}
