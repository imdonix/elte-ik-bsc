package hu.elte.madtycoon.core;

public class Statistics
{

    public final World world;

    private int moneyGain;
    private int moneySpent;
    private int allVisitorCount;
    private int currentVisitorCount;
    private float decorationValue;


    public Statistics(World world)
    {
        this.world = world;
    }

    //GETTERS

    public int getMoneyGain() {
        return moneyGain;
    }

    public int getMoneySpent() {
        return moneySpent;
    }

    public int getAllVisitorCount() {
        return allVisitorCount;
    }

    public int getCurrentVisitorCount() {
        return currentVisitorCount;
    }

    public float getDecorationValue() {
        return decorationValue;
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

    public void setDecorationValue(float value)
    {
        this.decorationValue = value;
    }

}
