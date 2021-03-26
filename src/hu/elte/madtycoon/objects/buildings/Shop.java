package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class Shop extends Game
{

    public final static String ID = "shop";
    public final static Vector2I SIZE = new Vector2I(4,3);
    public final static Vector2I ENTRANCE = new Vector2I(-1,1);
    public final static int PRICE = 100;

    public final static int MAX = 1;
    public final static int MIN_USE_COST = 20;
    public final static int MAX_USE_COST = 100;


    private Shop(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max)
    {
        super(world, sprite, position, size, max, MAX_USE_COST);
    }

    @Override
    protected void reward()
    {
        Visitor[] players = getPlayers();
        for (Visitor p: players) {
            p.addFood(0.5F);
        }
    }

    @Override
    protected float getPlayPeriod()
    {
        return 0.2F;
    }

    @Override
    public float getDecorationValue()
    {
        return 0.2F;
    }

    @Override
    public Vector2F getTargetPosition() {
        return super.getTargetPosition().add(new Vector2F(ENTRANCE));
    }

    @Override
    protected void damage(float dmg) { }


    public static Shop Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("shop_idle");
        BufferedImage[] play = AnimationResource.Instance.get("shop_play");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        anim.addState(AnimatedSprite.GAME_PLAY, play);
        return new Shop(world, anim, position, SIZE, MAX);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, Shop::Create));
    }

}
