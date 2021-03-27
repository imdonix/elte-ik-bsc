package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;

public abstract class Worker extends Entity {
    protected int salary;

    public Worker(World world, AnimatedSprite sprite, Vector2F position, int salary) {
        super(world, sprite, position);
        this.salary = salary;
    }

    public int getSalary() {
        return salary;
    }
}
