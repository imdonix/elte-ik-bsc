package hu.elte.madtycoon.objects.entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.task.Task;
import hu.elte.madtycoon.task.employee.Repair;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.LinkedList;
import java.util.List;

public class RepairMan extends Worker {

    public static int START_MONEY = 100;
    public static float START_FOOD = 1f;
    public static float START_INT = 1f;
    public static float MIN_MS_SPEED = 1.5F;
    public static float MAX_MS_SPEED = 3F;
    public static int SALARY = 75;

    private final float movementSpeed;

    private RepairMan(World world, AnimatedSprite sprite, Vector2F position) {
        super(world, sprite, position, SALARY);
        this.money = START_MONEY;
        this.food = START_FOOD;
        this.interest = START_INT;
        this.movementSpeed = Random.getRandomFloat(MIN_MS_SPEED, MAX_MS_SPEED);
    }

    @Override
    protected void start() {}

    @Override
    public float getMovementSpeed()
    {
        return movementSpeed;
    }

    @Override
    protected Task getNewTask() {
        List<Building> buildings = getBuildingsWithLowHealth();

        System.out.println(buildings.size());

        if(buildings.size() > 0) {
            return new Repair(this, findNearestBuilding(buildings));
        } else {
            System.out.println(String.format("%s can't be employed!", this));
            return super.getNewTask();
        }
    }

    @Override
    public void onDestroy() { }

    private List<Building> getBuildingsWithLowHealth()
    {
        List<Building> tmp = new LinkedList<>();
        for(Building building : world.getBuildings()) {
            if(building.isRepairNeeded()) {
                tmp.add(building);
            }
        }
        return tmp;
    }

    protected Building findNearestBuilding(List<Building> buildings)
    {
        Building min = buildings.get(0);
        for(Building building : buildings)
            if(min.getPosition().distance(getPosition()) > building.getPosition().distance(getPosition()))
                min = building;
        return min;
    }
}
