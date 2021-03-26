package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.image.BufferedImage;

public class GhostCastle extends Game {
    public final static String ID = "castle";
    public final static Vector2I SIZE = new Vector2I(3,4);
    public final static Vector2I ENTRANCE = new Vector2I(0,1);
    public final static int PRICE = 1200;

    public final static int MAX = 5;
    public final static int MIN_USE_COST = 100;
    public final static int MAX_USE_COST = 200;

    private GhostCastle(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int max) {
        super(world, sprite, position, size, max, MAX_USE_COST);
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
    protected void reward() {
        Visitor[] players = getPlayers();
        for (Visitor player : players) {
            player.addInterest(1F);
        }
    }
}
