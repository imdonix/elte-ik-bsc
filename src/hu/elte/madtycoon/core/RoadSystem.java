package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.buildings.Road;
import hu.elte.madtycoon.pathfind.Node;
import hu.elte.madtycoon.pathfind.Path;
import hu.elte.madtycoon.pathfind.PathFindJob;
import hu.elte.madtycoon.pathfind.PathFindRequest;
import hu.elte.madtycoon.utils.Vector2I;

import java.awt.*;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class RoadSystem
{
    private final ThreadPoolExecutor executor;
    private final World world;
    private Road[][] map;


    public RoadSystem(World world)
    {
        int cores = Runtime.getRuntime().availableProcessors();
        this.executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(cores/2);
        this.world = world;
        updateMap();
    }

    public PathFindRequest pathFind(Vector2I pos, Vector2I dest)
    {
        //if(map[pos.x][pos.y] == null) throw new IllegalStateException("The start position not valid" + pos);
        //if(map[dest.x][dest.y] == null) throw new IllegalStateException("The end position not valid " + pos);

        PathFindRequest request = new PathFindRequest();
        PathFindJob job = new PathFindJob(request, map, pos, dest);
        executor.execute(job);

        return request;
    }

    public void updateMap()
    {
        map = new Road[Engine.GAME_SIZE_X][Engine.GAME_SIZE_Y];
        for(Road road : world.getRoads())
            if(road.getActive() && road.isInside())
            {
                Vector2I pos = new Vector2I(road.getPosition());
                map[pos.x][pos.y] = road;
            }
    }

}
