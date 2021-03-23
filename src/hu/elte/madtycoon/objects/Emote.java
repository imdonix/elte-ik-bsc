package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.Vector2F;
import java.awt.image.BufferedImage;

public class Emote extends GameObject
{
    public static final float SPEED = 1.25F;
    public static final float LIVE = 1.25F;
    public static final float EMOTE_SIZE = .5F;

    private final GameObject holder;
    private float timer;
    private float speed;

    public Emote(World world, AnimatedSprite sprite, GameObject holder)
    {
        super(world, sprite, Vector2F.ZERO);
        this.holder = holder;
        this.timer = 0;
        this.speed = SPEED;
    }

    @Override
    public void onDestroy() {}

    @Override
    protected void start()
    {

        if(holder instanceof Building)
        {
            position = new Vector2F(((Building) holder).getSize().x / 2F - EMOTE_SIZE / 2F , 0);
        }
        else
        {
            speed = 0;
            position = Vector2F.UP.mul(1/2F);
        }

    }

    @Override
    protected int getRenderLayer() { return 2; }

    @Override
    public Vector2F getRenderPosition()
    {
        return holder.getRenderPosition().add(super.getRenderPosition());
    }

    public boolean isTimeToDie()
    {
        return timer > LIVE;
    }

    @Override
    public void update(float dt)
    {
        super.update(dt);
        timer+=dt;
        position = position.add(Vector2F.UP.mul(speed * dt));
    }


    public static Emote Create(World world, GameObject holder, String type)
    {
        BufferedImage[] emoteSprite = AnimationResource.Instance.get(String.format("emote_%s", type));
        AnimatedSprite anim = new AnimatedSprite(type, emoteSprite, 1f);
        return new Emote(world, anim, holder);
    }
}
