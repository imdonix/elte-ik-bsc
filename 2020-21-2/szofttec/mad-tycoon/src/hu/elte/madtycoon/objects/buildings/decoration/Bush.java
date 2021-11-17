package hu.elte.madtycoon.objects.buildings.decoration;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Decoration;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Bush extends Decoration
{
    public final static String ID = "bush";
    public final static Vector2I SIZE = new Vector2I(2,2);
    public final static int PRICE = 75;

    private Bush(World world, AnimatedSprite sprite, Vector2F position, Vector2I size)
    {
        super(world, sprite, position, size);
    }

    @Override
    public float getDecorationValue() {
        return .15F;
    }

    @Override
    public String getName() { return "Bush"; }

    public static Bush Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("bush_idle");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        return new Bush(world, anim, position, SIZE);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, Bush::Create));
    }

}
