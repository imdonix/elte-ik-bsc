package hu.elte.madtycoon.objects.buildings.games;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.ui.components.building.SetComponent;
import hu.elte.madtycoon.ui.components.building.SetPercentComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.*;

import javax.rmi.CORBA.Util;
import java.awt.image.BufferedImage;

public class CoinFlip extends Game
{

    public final static String ID = "coin";
    public final static Vector2I SIZE = new Vector2I(3,4);
    public final static Vector2I ENTRANCE = new Vector2I(-1,1);
    public final static int PRICE = 500;

    public final static int MAX = 2;
    public final static int MIN_USE_COST = 20;
    public final static int MAX_USE_COST = 60;

    public final static int EDGE = 0;

    private int edge;

    private CoinFlip(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max)
    {
        super(world, sprite, position, size, max, MAX_USE_COST / 2);
        this.edge = EDGE;
    }

    public void setEdge(int edge)
    {
        this.edge = Utils.clamp(0,100, edge);
    }

    public int getEdge() { return edge; }

    @Override
    protected void reward()
    {
        Visitor[] players = getPlayers();
        int reward = (int) (getUseCost() * 2 * 0.8F);
        int winner = Random.getRandomInt(0,10);
        boolean edgeCase = Random.getRandomInt(0,100) <= edge;

        if(edgeCase)
        {
            players[0].addInterest(-.5F);
            players[1].addInterest(-.5F);
        }
        else
        {
            players[winner % 2].earn(reward);
            players[winner % 2].addInterest(.3F);
            players[(winner + 1) % 2].addInterest(-.15F);
        }
    }

    @Override
    public void setUseCost(int useCost)
    {
        this.useCost = Utils.clamp(MIN_USE_COST, MAX_USE_COST, useCost);
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

    @Override
    public String getName() { return "Coin Flip"; }

    @Override
    public Preview getPreview() {
        Preview view = super.getPreview();
        view.addContent(new SetPercentComponent("Edge case", this::getEdge, this::setEdge));
        return view;
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
