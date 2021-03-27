package hu.elte.madtycoon.objects;

import com.sun.xml.internal.bind.v2.TODO;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.entities.RepairMan;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.JobAlreadyTaken;

public abstract class Building extends GameObject
{
    public static float SAFE_HEALTH = 0.4f;

    private Vector2I size;
    protected float health;
    private boolean opened;

    private RepairMan employee;

    public Building(World world, AnimatedSprite sprite, Vector2F position, Vector2I size) {
        super(world, sprite, position);
        this.size = size;
        this.health = 1F;
        this.opened = true;
        this.employee = null;
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
        return opened && health > 0;
    }

    public void setOpened(boolean opened) {
        this.opened = opened;
    }

    public boolean isRepairNeeded()
    {
       return this.health < Building.SAFE_HEALTH;
    }

    public boolean isWorking()
    {
        return health > 0;
    }

    public void repair(RepairMan employee) throws JobAlreadyTaken
    {
        if(this.employee != null) throw new JobAlreadyTaken();

        this.employee = employee;
        this.employee.setActive(false);
        world.getEmotes().pop(this, AnimatedSprite.REPAIR);
        getSprite().setState(AnimatedSprite.GAME_UNDER_CONSTRUCTION); //TODO **this takes some time**
        health = 1F;
        this.employee.earn(this.employee.getSalary());
        this.employee.setActive(true);
    }

    protected void damage(float dmg)
    {
        health -= dmg;
        if(!isWorking()) {
            world.getEmotes().popSpecial(this, AnimatedSprite.NEED_REPAIR);
            getSprite().setState(AnimatedSprite.GAME_STOP);
        }
    }

    public abstract float getDecorationValue();

    public float getHealth(){return health;};



}
