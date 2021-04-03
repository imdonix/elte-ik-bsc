package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.*;
import hu.elte.madtycoon.objects.buildings.Entrance;
import hu.elte.madtycoon.objects.buildings.games.CoinFlip;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.render.SpriteRenderBuffer;
import hu.elte.madtycoon.utils.Utils;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.LinkedList;
import java.util.List;

public class World
{
    public static int DEFAULT_START_MONEY = 300000;
    public static Vector2I ENTRANCE_POINT = new Vector2I(Engine.GAME_SIZE_X/2 + 2,Engine.GAME_SIZE_Y - 2);

    private final List<Entity> entities;
    private final List<Building> buildings;
    private final List<GameObject> destroyBuffer;
    private final Emotes emotes;
    private final RoadSystem roadSystem;
    private final Coroutines coroutines;
    private final Statistics statistics;
    private final Employment employment;
    private final Loans loans;

    private Entrance entrance;
    private int money;

    public World()
    {
        money = DEFAULT_START_MONEY;
        entities = new LinkedList<Entity>();
        buildings  = new LinkedList<Building>();
        destroyBuffer = new LinkedList<GameObject>();
        roadSystem = new RoadSystem(this);
        emotes = new Emotes(this);
        statistics = new Statistics(this);
        employment = new Employment(this);
        loans = new Loans(this);
        coroutines = new Coroutines();
        start();
    }

    private void start()
    {
        entrance = (Entrance) instantiate(Entrance.Create(this));
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

        loans.update(dt);
        emotes.update(dt);
        coroutines.update(dt);
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
        if(obj instanceof Entity) {
            entities.add((Entity) obj);
            if(obj instanceof Visitor) statistics.increaseVisitorCount();
        }
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

    public Coroutines getCoroutines(){ return coroutines; }

    public Statistics getStatistics(){ return statistics; }

    public Employment getEmployment(){ return employment; }

    public Entrance getEntrance(){ return entrance; }

    public int getMoney()
    {
        return money;
    }

    public void earn(int money)
    {
        this.money += money;
        this.statistics.addMoneyGain(money);
    }

    public void pay(int money)
    {
        this.money -= money;
        this.statistics.addMoneySpent(money);
    }

    public List<Building> collisionCheckMultiple(Vector2I pos, Vector2I size) {

        List<Building> buildings = new LinkedList<>();
        if(pos == null) return buildings;

        int x = pos.x;
        int y = pos.y;
        for(Building building : this.buildings)
            if(building.getPosition().x < x + size.x &&
                    building.getPosition().x + building.getSize().x > x &&
                    building.getPosition().y < y + size.y &&
                    building.getPosition().y + building.getSize().y > y) {
                buildings.add(building);
            }
        return buildings;
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
            sum += building.getDecorationValue();
        return Utils.clamp(1,5, sum);
    }

    public List<Building> getBuildings() {return new LinkedList<Building>(buildings);}

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

    public List<Shop> getShops(){
        List<Shop> tmp = new LinkedList<>();
        for(Building building : buildings)
            if(building instanceof Shop)
                tmp.add((Shop) building);
        return tmp;
    }

    public List<Visitor> getVisitors(){
        List<Visitor> tmp = new LinkedList<>();
        for(Entity entity : entities)
            if(entity instanceof Visitor)
                tmp.add((Visitor) entity);
        return tmp;
    }

    public List<Worker> getWorkers(){
        List<Worker> tmp = new LinkedList<>();
        for(Entity entity : entities)
            if(entity instanceof Worker)
                tmp.add((Worker) entity);
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

            if(obj instanceof Visitor)
                statistics.decreaseVisitorCount();
        }
        destroyBuffer.clear();
    }

}
