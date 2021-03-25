package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.Engine;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Road extends Building
{

    public static final String ID = "road";
    public static final int PRICE = 25;

    private Road(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position, Vector2I.ONE);
    }

    @Override
    protected int getRenderLayer() { return 0;}

    @Override
    public float getDecorationValue()
    {
        return 0;
    }

    @Override
    public void onDestroy() {}

    @Override
    protected void start() {}

    public boolean isInside()
    {
        int x = (int) position.x;
        int y = (int) position.y;

        return x >=0 && x < Engine.GAME_SIZE_X && y >= 0 && y < Engine.GAME_SIZE_Y;
    }


    public static Road Create(World world, Vector2F pos)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("road_idle");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 1f);
        return new Road(world, anim, pos);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(Vector2I.ONE, PRICE, Road::Create));
    }
}
