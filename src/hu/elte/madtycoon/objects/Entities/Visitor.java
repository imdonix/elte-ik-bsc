package hu.elte.madtycoon.objects.Entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;

public class Visitor extends Entity
{

    private Visitor(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
    }

    public static Visitor CreateNewVisitor()
    {
        return null;
    }
}
