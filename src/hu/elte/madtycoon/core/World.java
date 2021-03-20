package hu.elte.madtycoon.core;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Buildings.CoinFlip;
import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Stream;

public class World
{
    public static int DEFAULT_ENTRANCE_COST = 50;
    public static int DEFAULT_START_MONEY = 200;
    public static Vector2I ENTRANCE_POINT = new Vector2I(Engine.GAME_SIZE_X/2,Engine.GAME_SIZE_Y);

    private final List<Entity> entities;
    private final List<Building> buildings;
    private final List<GameObject> destroyBuffer;

    private int money;
    private int entranceCost;

    public World()
    {
        money = DEFAULT_START_MONEY;
        entranceCost = DEFAULT_ENTRANCE_COST;
        entities = new LinkedList<Entity>();
        buildings  = new LinkedList<Building>();
        destroyBuffer = new LinkedList<GameObject>();
        start();
    }

    private void start()
    {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                entities.add(Visitor.Create(this, new Vector2F(i+2,j+2)));
            }
        }

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++)
                buildings.add(CoinFlip.Create(this, new Vector2F(j*3+i*3+5,i*3+5)));
    }

    public void update(float dt)
    {
        doDestroy();

        for(final GameObject obj : entities)
            if(obj.getActive())
                obj.update(dt);

        for(final GameObject obj : buildings)
            if(obj.getActive())
                obj.update(dt);
    }

    public void render(SpriteRenderBuffer buffer)
    {
        for(final GameObject obj : entities)
            if(obj.getActive())
                obj.render(buffer);

        for(final GameObject obj : buildings)
            if(obj.getActive())
                obj.render(buffer);
    }

    public void destroy(GameObject game)
    {
        game.setActive(false);
        destroyBuffer.add(game);
    }

    public int getMoney()
    {
        return money;
    }

    public void earn(int money)
    {
        //TODO trigger gui
        this.money += money;
    }

    public void pay(int money)
    {
        //TODO trigger gui
        this.money -= money;
    }

    public int getEntranceCost()
    {
        return entranceCost;
    }

    public void setEntranceCost(int entranceCost)
    {
        this.entranceCost = entranceCost;
    }

    public Building collisionCheck(int x, int y, Vector2I size) {
        for(Building building : buildings)
            if(building.getPosition().x < x + size.x &&
                    building.getPosition().x + building.getSize().x > x &&
                    building.getPosition().y < y + size.y &&
                    building.getPosition().y + building.getSize().y > y) {
                return building;
            }
        return null;
    }

    public float getHappiness()
    {
        float sum = 0;
        for(Entity entity : entities)
            sum += entity.getHappiness();
        return sum / entities.size();
    }

    public List<Game> getGames()
    {
        List<Game> tmp = new LinkedList<>();
        for(Building building : buildings)
            if(building instanceof Game)
                tmp.add((Game) building);
        return tmp;
    }

    private void doDestroy()
    {
        for(GameObject obj : destroyBuffer)
            if(obj instanceof Entity)
                entities.remove(obj);
            else if (obj instanceof Building)
                buildings.remove(obj);
        destroyBuffer.clear();
    }

}
