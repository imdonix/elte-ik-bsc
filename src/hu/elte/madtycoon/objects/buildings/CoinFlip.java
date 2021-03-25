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

public class CoinFlip extends Game
{

    public final static String ID = "coin";
    public final static Vector2I SIZE = new Vector2I(3,4);
    public final static Vector2I ENTRANCE = new Vector2I(-1,1);
    public final static int PRICE = 500;

    public final static int MAX = 2;
    public final static int MIN_USE_COST = 20;
    public final static int MAX_USE_COST = 100;


    private CoinFlip(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max)
    {
        super(world, sprite, position, size, max, MAX_USE_COST);
    }

    @Override
    protected void reward()
    {
        Visitor[] players = getPlayers();
        int reward = (int) (getUseCost() * 2 * 0.8F);
        int winner = Random.getRandomInt(0,10) ;

        players[winner % 2].earn(reward);
        players[winner % 2].addInterest(.3F);
        players[(winner + 1) % 2].addInterest(-.1F);
    }

    @Override
    protected float getPlayPeriod()
    {
        return 5F;
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


    public static CoinFlip Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("coin_idle");
        BufferedImage[] play = AnimationResource.Instance.get("coin_play");
        BufferedImage[] stop = AnimationResource.Instance.get("coin_stop");
        BufferedImage[] underConstruction = AnimationResource.Instance.get("coin_construction");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        anim.addState(AnimatedSprite.GAME_PLAY, play);
        anim.addState(AnimatedSprite.GAME_STOP, stop);
        anim.addState(AnimatedSprite.GAME_UNDER_CONSTRUCTION, underConstruction);
        return new CoinFlip(world, anim, position, SIZE, MAX);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, CoinFlip::Create));
    }

}
