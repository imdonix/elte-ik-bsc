package hu.elte.madtycoon.objects.buildings.games;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.Resources;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;
import java.net.URL;

public class GhostCastle extends Game {
    public final static String ID = "castle";
    public final static Vector2I SIZE = new Vector2I(3,4);
    public final static Vector2I ENTRANCE = new Vector2I(0,1);
    public final static int PRICE = 5000;

    public final static int MAX = 10;
    public final static int MIN_USE_COST = 20;
    public final static int MAX_USE_COST = 100;

    private GhostCastle(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max) {
        super(world, sprite, position, size, max, MAX_USE_COST/2);
    }

    public static GhostCastle Create(World world, Vector2F position) {
        BufferedImage[] idle = AnimationResource.Instance.get("castle_idle");
        BufferedImage[] play = AnimationResource.Instance.get("castle_play");
        BufferedImage[] stop = AnimationResource.Instance.get("castle_stop");
        BufferedImage[] underConstruction = AnimationResource.Instance.get("castle_construction");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        anim.addState(AnimatedSprite.GAME_PLAY, play);
        anim.addState(AnimatedSprite.GAME_STOP, stop);
        anim.addState(AnimatedSprite.GAME_UNDER_CONSTRUCTION, underConstruction);
        return new GhostCastle(world, anim, position, SIZE, MAX);
    }

    public static void AddReference() {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, GhostCastle::Create));
    }

    @Override
    public void setUseCost(int useCost)
    {
        this.useCost = Utils.clamp(MIN_USE_COST, MAX_USE_COST, useCost);
    }

    @Override
    protected float getPlayPeriod() {
        return 20F;
    }

    @Override
    public float getDecorationValue() {
        return 0.5F;
    }

    @Override
    public Vector2F getTargetPosition() {
        return super.getTargetPosition().add(new Vector2F(ENTRANCE));
    }

    @Override
    public String getName() { return "Ghost Castle"; }

    @Override
    protected void reward() {
        Visitor[] players = getPlayers();
        for (Visitor player : players)
            player.addInterest(0.3F);
    }

    @Override
    protected URL getGameAudioClip()
    {
        return Resources.Instance.casteSound;
    }
}
