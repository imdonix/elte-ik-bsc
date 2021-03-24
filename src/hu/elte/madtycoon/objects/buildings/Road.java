package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Road extends Building
{

    private Road(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position, Vector2I.ONE);
    }

    @Override
    public float getDecorationValue()
    {
        return 1;
    }

    @Override
    public void onDestroy() {}

    @Override
    protected void start() {}

    public static Road Create(World world, Vector2F pos)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("road");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        return new Road(world, anim, pos);
    }
}
