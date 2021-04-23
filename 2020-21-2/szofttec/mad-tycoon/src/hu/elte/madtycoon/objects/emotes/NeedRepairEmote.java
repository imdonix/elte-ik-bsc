package hu.elte.madtycoon.objects.emotes;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.render.SpriteRenderBuffer;

import java.awt.image.BufferedImage;

public class NeedRepairEmote extends Emote
{
    public static final float FLICKERING  = 1.5F;

    private Building building;
    private boolean show;

    private NeedRepairEmote(World world, AnimatedSprite sprite, Building holder)
    {
        super(world, sprite, holder);
        this.building = holder;
        this.show = true;
    }

    @Override
    public boolean isTimeToDie()
    {
        return building.isWorking() || !building.getActive();
    }

    @Override
    protected void start()
    {
        super.start();
        speed = 0;
    }

    @Override
    public void update(float dt)
    {
        super.update(dt);
        if(FLICKERING < timer)
        {
            timer = 0;
            show = !show;
        }
    }

    @Override
    public void render(SpriteRenderBuffer buffer)
    {
        if(show)
            super.render(buffer);
    }

    public static NeedRepairEmote Create(World world, Building holder, String type)
    {
        BufferedImage[] emoteSprite = AnimationResource.Instance.get(String.format("emote_%s", type));
        AnimatedSprite anim = new AnimatedSprite(type, emoteSprite, 1f);
        return new NeedRepairEmote(world, anim, holder);
    }
}
