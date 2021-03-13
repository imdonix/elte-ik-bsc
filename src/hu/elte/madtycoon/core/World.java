package hu.elte.madtycoon.core;

import hu.elte.madtycoon.render.SpriteRenderBuffer;

public class World
{
    public static int DEFAULT_ENTRANCE_COST = 50;
    public static int DEFAULT_START_MONEY = 200;

    private int money;
    private int entranceCost;

    public World()
    {
        money = DEFAULT_START_MONEY;
        entranceCost = DEFAULT_ENTRANCE_COST;
    }

    public void update(float dt)
    {
        //TODO
    }

    public void render(SpriteRenderBuffer buffer)
    {
        //TODO
    }

    public int getMoney()
    {
        return money;
    }

    public int getEntranceCost()
    {
        return entranceCost;
    }

    public void setEntranceCost(int entranceCost)
    {
        this.entranceCost = entranceCost;
    }
}
