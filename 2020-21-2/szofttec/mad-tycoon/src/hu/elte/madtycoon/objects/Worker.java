package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.ui.components.employement.WorkerDisplayComponent;
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

    public void fire()
    {
        setTask(new LeavePark(this));
        System.out.println( String.format("%s is fired!", getName()));
    }

    public void hire()
    {
        setPosition(world.getEntrance().getTargetPosition());
        world.instantiate(this);
        System.out.println( String.format("%s is hired.", getName()));
    }


    @Override
    public String toString()
    {
        return String.format("Salary: %d | Speed: %d u/s", salary, (int)(getMovementSpeed()*10));
    }

    public abstract String getTypeName();

}
