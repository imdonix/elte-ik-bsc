package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

public abstract class Interactable extends Building {
    private boolean opened;
    private boolean needRepair;
    public static float MIN_HEALTH = 50;

    public Interactable(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, float health, float decorationValue, boolean opened, boolean needRepair) {
        super(world, sprite, position, size, health, decorationValue);
        this.opened = opened;
        this.needRepair = needRepair;
    }

    public void interact(Entity e) {
        //TODO
    }

    public boolean isRepairNeeded() {
        if(this.health < MIN_HEALTH) {
            this.needRepair = true;
        } else {
            this.needRepair = false;
        }
        return needRepair;
    }

    public boolean isOpened() {
        return opened;
    }
}
