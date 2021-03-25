package hu.elte.madtycoon.core;

import hu.elte.madtycoon.Main;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.buildings.CoinFlip;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.LinkedList;
import java.util.List;

public class World
{
    public static int DEFAULT_ENTRANCE_COST = 50;
    public static int DEFAULT_START_MONEY = 300000;
    public static Vector2I ENTRANCE_POINT = new Vector2I(Engine.GAME_SIZE_X/2,Engine.GAME_SIZE_Y - 1);

    private final List<Entity> entities;
    private final List<Building> buildings;
    private final List<GameObject> destroyBuffer;
    private final Emotes emotes;
    private final RoadSystem roadSystem;

    private int money;
    private int entranceCost;

    public World()
    {
        money = DEFAULT_START_MONEY;
        entranceCost = DEFAULT_ENTRANCE_COST;
        entities = new LinkedList<Entity>();
        buildings  = new LinkedList<Building>();
        destroyBuffer = new LinkedList<GameObject>();
        roadSystem = new RoadSystem(this);
        emotes = new Emotes(this);
        start();
    }

    private void start()
    {
        instantiate(Road.Create(this, new Vector2F( ENTRANCE_POINT)));


        instantiate(CoinFlip.Create(this, new Vector2F(5,5)));
        instantiate(CoinFlip.Create(this, new Vector2F(10,5))).getSprite().setRotation(true);

    }

    //DEBUG
    float timer = 0;

    public void update(float dt)
    {
        doDestroy();

        for(final GameObject obj : entities)
            if(obj.getActive())
                obj.update(dt);

        for(final GameObject obj : buildings)
            if(obj.getActive())
                obj.update(dt);

        emotes.update(dt);

        //DEBUG
        timer+=dt;
        if(timer > 1)
        {
            timer = 0;
            instantiate(Visitor.Create(this, new Vector2F(ENTRANCE_POINT)));
        }

    }

    public void render(SpriteRenderBuffer buffer)
    {
        for(final GameObject obj : entities)
            if(obj.getActive())
                obj.render(buffer);

        for(final GameObject obj : buildings)
            if(obj.getActive())
                obj.render(buffer);

        emotes.render(buffer);
    }

    public void destroy(GameObject obj)
    {
        obj.setActive(false);
        destroyBuffer.add(obj);
        if(obj instanceof Road) roadSystem.updateMap();
    }

    public GameObject instantiate(GameObject obj)
    {
        if(obj instanceof Entity)
            entities.add((Entity) obj);
        else if (obj instanceof Building)
        {
            buildings.add((Building) obj);
            if(obj instanceof Road) roadSystem.updateMap();
        }
        else
            throw new IllegalArgumentException("You can only instantiate entities or buildings");
        return obj;
    }

    public Emotes getEmotes()
    {
        return emotes;
    }

    public RoadSystem getRoadSystem(){ return roadSystem; }

    public int getMoney()
    {
        return money;
    }

    public void earn(int money)
    {
        this.money += money;
    }

    public void pay(int money)
    {
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

    public Building collisionCheck(Vector2I pos, Vector2I size) {

        if(pos == null)
            return null;

        int x = pos.x;
        int y = pos.y;
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

    public float getDecoration()
    {
        float sum = 0;
        for(Building building : buildings)
            sum+= building.getDecorationValue();
        return sum;
    }

    public List<Game> getGames()
    {
        List<Game> tmp = new LinkedList<>();
        for(Building building : buildings)
            if(building instanceof Game)
                tmp.add((Game) building);
        return tmp;
    }

    public List<Road> getRoads()
    {
        List<Road> tmp = new LinkedList<>();
        for(Building building : buildings)
            if(building instanceof Road)
                tmp.add((Road) building);
        return tmp;
    }

    private void doDestroy()
    {
        for(GameObject obj : destroyBuffer)
        {
            obj.onDestroy();
            if(obj instanceof Entity)
                entities.remove(obj);
            else if (obj instanceof Building)
                buildings.remove(obj);
        }
        destroyBuffer.clear();
    }

}
