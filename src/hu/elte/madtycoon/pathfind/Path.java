package hu.elte.madtycoon.pathfind;

import hu.elte.madtycoon.objects.buildings.Road;

import java.util.Collections;
import java.util.List;
import java.util.ListIterator;

public class Path
{
    private final List<Road> path;
    private int i;


    public Path(List<Road> path)
    {
        this.path = path;
        this.i = 0;
        Collections.reverse(path);
    }

    public boolean hasNext()
    {
        return path.size() > i;
    }

    public Road current()
    {
        return path.get(i);
    }

    public void next()
    {
        i++;
    }

}
