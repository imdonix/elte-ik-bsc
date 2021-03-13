package hu.elte.madtycoon.objects.Entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;

public class Visitor extends Entity
{

    private Visitor(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
    }

    @Override
    public void update(float dt) {
        super.update(dt);

        sprite.setState("walk");
        position = position.add(Vector2F.DOWN.mul(dt));
    }

    public static Visitor CreateNewVisitor(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("visitor_idle");
        BufferedImage[] walk = AnimationResource.Instance.get("visitor_walk");
        AnimatedSprite anim = new AnimatedSprite("idle", idle, 0.25f);
        anim.addState("walk", walk);
        return new Visitor(world, anim, position);
    }
}
