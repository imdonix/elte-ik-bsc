package hu.elte.madtycoon.objects;

import com.sun.xml.internal.bind.v2.TODO;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

public abstract class Building extends GameObject
{
    public static float SAFE_HEALTH = 0.3f;

    private Vector2I size;
    protected float health;
    private boolean opened;
    private boolean repairRequested;

    public Building(World world, AnimatedSprite sprite, Vector2F position, Vector2I size) {
        super(world, sprite, position);
        this.size = size;
        this.health = 1F;
        this.opened = true;
    }

    @Override
    protected int getRenderLayer()
    {
        return 1;
    }

    @Override
    public Vector2F getTargetPosition()
    {
        Vector2F pos = getPosition();
        return new Vector2F(pos.x + size.x/2F, pos.y + size.y/2F);
    }

    public Vector2I getSize() {
        return size;
    }

    public boolean isOpened() {
        return opened;
    }

    public void setOpened(boolean opened) {
        this.opened = opened;
    }

    public boolean isRepairNeeded()
    {
       return this.health < Building.SAFE_HEALTH;
    }

    public void markRepair()
    {
        repairRequested = true;
    }

    public boolean isRepairRequested()
    {
        return repairRequested;
    }

    public void repair() {
        health = 1F;
    }

    public abstract float getDecorationValue();




}
