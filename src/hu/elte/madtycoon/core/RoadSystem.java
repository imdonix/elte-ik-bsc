package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.pathfind.Path;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.*;

public class RoadSystem
{

    private final World world;
    private Road[][] map;

    public RoadSystem(World world)
    {
        this.world = world;
        updateMap();
    }


    public Path pathFind(Vector2I pos, Vector2I dir)
    {
        
    }

    public void updateMap()
    {
        map = new Road[Engine.GAME_SIZE_X][Engine.GAME_SIZE_Y];
        for(Road road : world.getRoads())
            if(road.getActive())
            {
                Vector2I pos = new Vector2I(road.getPosition());
                map[pos.x][pos.y] = road;
            }
    }

    public void debug(Graphics g)
    {
        g.setColor(Color.yellow);
        for (int i = 0; i < Engine.GAME_SIZE_X; i++)
            for (int j = 0; j < Engine.GAME_SIZE_Y; j++)
                if(map[i][j] != null)
                    g.drawRect(i * Engine.BLOCK_SIZE, j * Engine.BLOCK_SIZE, Engine.BLOCK_SIZE, Engine.BLOCK_SIZE);
    }
}
