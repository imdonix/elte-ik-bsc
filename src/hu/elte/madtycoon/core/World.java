package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.LinkedList;
import java.util.List;

public class World
{
    public static int DEFAULT_ENTRANCE_COST = 50;
    public static int DEFAULT_START_MONEY = 200;

    private final List<Entity> entities;
    private List<Building> buildings;

    private int money;
    private int entranceCost;

    public World()
    {
        money = DEFAULT_START_MONEY;
        entranceCost = DEFAULT_ENTRANCE_COST;
        entities = new LinkedList<Entity>();
        start();
    }

    private void start()
    {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                entities.add(Visitor.CreateNewVisitor(this, new Vector2F(i+2,j+2)));
            }
        }
    }

    public void update(float dt)
    {
        for(final GameObject obj : entities) obj.update(dt);
    }

    public void render(SpriteRenderBuffer buffer)
    {
        for(final GameObject obj : entities) obj.render(buffer);
    }

    public int getMoney()
    {
        return money;
    }

    public void earn(int money)
    {
        this.money += money;
    }

    public int getEntranceCost()
    {
        return entranceCost;
    }

    public void setEntranceCost(int entranceCost)
    {
        this.entranceCost = entranceCost;
    }

    public boolean isColide(int x, int y, Vector2I size) {
        for(int i = 0; i < buildings.size(); i++) {
            if(buildings.get(i).getPosition().x < x + size.x &&
            buildings.get(i).getPosition().x + buildings.get(i).getSize().x > x &&
            buildings.get(i).getPosition().y < y + size.y &&
            buildings.get(i).getPosition().y + buildings.get(i).getSize().y > y) {
                return true;
            }
        }
        return false;
    }
}
