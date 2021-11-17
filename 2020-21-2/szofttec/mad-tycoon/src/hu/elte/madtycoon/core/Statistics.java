package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.ui.components.DisplayComponent;
import hu.elte.madtycoon.ui.components.building.DecorationComponent;
import hu.elte.madtycoon.ui.components.statistics.BuildingCounterDisplayComponent;
import hu.elte.madtycoon.ui.components.statistics.MoneyDisplayComponent;
import hu.elte.madtycoon.ui.components.statistics.NumberDisplayComponent;
import hu.elte.madtycoon.ui.components.statistics.ParkDecorationDisplayComponent;
import hu.elte.madtycoon.ui.core.Preview;

import java.util.List;

public class Statistics
{

    public final World world;

    private int moneyGain;
    private int moneySpent;
    private int allVisitorCount;
    private int currentVisitorCount;


    public Statistics(World world)
    {
        this.world = world;
    }

    public Preview getPreview()
    {
        Preview preview = new Preview("Statistics");
        preview.addContent(new MoneyDisplayComponent("Money gain", this::getMoneyGain));
        preview.addContent(new MoneyDisplayComponent("Money spent", this::getMoneySpent));
        preview.addContent(new NumberDisplayComponent("All visitor count", this::getAllVisitorCount));
        preview.addContent(new NumberDisplayComponent("Current visitor count", this::getCurrentVisitorCount));
        preview.addContent(new ParkDecorationDisplayComponent("Park decoration", this::getDecorationValue));
        preview.addContent(new BuildingCounterDisplayComponent("Game count", world::getGames));
        preview.addContent(new BuildingCounterDisplayComponent("Shop count", world::getShops));
        preview.addContent(new NumberDisplayComponent("Damaged games", this::getDamagedGames));
        return preview;
    }

    //GETTERS

    public int getMoneyGain()
    {
        return moneyGain;
    }

    public int getMoneySpent()
    {
        return moneySpent;
    }

    public int getAllVisitorCount()
    {
        return allVisitorCount;
    }

    public int getCurrentVisitorCount()
    {
        return currentVisitorCount;
    }

    public float getDecorationValue()
    {
        return world.getDecoration();
    }

    public int getDamagedGames() {
        int c = 0;
        List<Game> buildingList = world.getGames();
        for (Game building : buildingList)
            if (building.isRepairNeeded())
                c++;
        return c;
    }

    //SETTERS

    public void addMoneyGain(int moneyGain)
    {
        this.moneyGain+=moneyGain;
    }

    public void addMoneySpent(int moneySpent)
    {
        this.moneySpent+=moneySpent;
    }

    public void increaseVisitorCount()
    {
        currentVisitorCount++;
        allVisitorCount++;
    }

    public void decreaseVisitorCount()
    {
        currentVisitorCount--;
    }

}
