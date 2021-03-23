package hu.elte.madtycoon.objects.Buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class RoundAbout extends Game {

    public final static String ID = "round";
    public final static Vector2I SIZE = new Vector2I(4,4);
    public final static Vector2I ENTRANCE = new Vector2I(0,1);
    public final static int PRICE = 1000;

    public final static int MAX = 3;
    public final static int MIN_USE_COST = 50;
    public final static int MAX_USE_COST = 150;

    private RoundAbout(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max)
    {
        super(world, sprite, position, size, max, MAX_USE_COST);
    }

    public static RoundAbout Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("round_idle");
        BufferedImage[] play = AnimationResource.Instance.get("round_play");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        anim.addState(AnimatedSprite.GAME_PLAY, play);
        return new RoundAbout(world, anim, position, SIZE, MAX);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, RoundAbout::Create));
    }

    @Override
    protected float getPlayPeriod()
    {
        return 10F;
    }

    @Override
    public float getDecorationValue()
    {
        return 0.3F;
    }

    @Override
    public Vector2F getTargetPosition() {
        return super.getTargetPosition().add(new Vector2F(ENTRANCE));
    }


    @Override
    protected void reward()
    {
        Visitor[] players = getPlayers();
        for (Visitor player : players) {
            player.addInterest(.4F);
        }
    }
}
