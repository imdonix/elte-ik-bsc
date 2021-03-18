package hu.elte.madtycoon.objects;

import com.sun.xml.internal.bind.v2.TODO;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

public abstract class Building extends GameObject {
    private Vector2I size;
    protected float health;
    protected float decorationValue;
    private boolean opened;
    private boolean needRepair;
    public static float MIN_HEALTH = 50;

    public Building(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, float health,
                    float decorationValue, boolean opened, boolean needRepair) {
        super(world, sprite, position);
        this.size = size;
        this.health = health;
        this.decorationValue = decorationValue;
        this.opened = opened;
        this.needRepair = needRepair;
    }

    public Vector2I getSize() {
        return size;
    }

    public float getDecorationValue() {
        return decorationValue;
    }

    public boolean isOpened() {
        return opened;
    }

    public void setOpened(boolean opened) {
        this.opened = opened;
    }

    public void isRepairNeeded() {
        if(this.health < MIN_HEALTH) {
            this.needRepair = true;
        } else {
            this.needRepair = false;
        }
    }

    public void repair() {
        this.health = 100;
    }
}
