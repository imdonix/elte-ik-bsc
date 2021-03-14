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

    public Building(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, float health, float decorationValue) {
        super(world, sprite, position);
        this.size = size;
        this.health = health;
        this.decorationValue = decorationValue;
    }

    public Vector2I getSize() {
        return size;
    }

    public float getDecorationValue() {
        return decorationValue;
    }

    public void rotate(int direction) {
        //TODO
    }
}
