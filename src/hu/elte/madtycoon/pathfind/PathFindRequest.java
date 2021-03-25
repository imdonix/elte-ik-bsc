package hu.elte.madtycoon.pathfind;

public class PathFindRequest
{
    private Path path;
    private boolean finished;
    private boolean successful;

    public PathFindRequest()
    {
        this.path = null;
        this.finished = false;
        this.successful = false;
    }

    public Path getPath()
    {
        return path;
    }

    public boolean isSuccessful()
    {
        return successful;
    }


    public synchronized boolean isDone()
    {
        return finished;
    }

    public synchronized void finalizePath(Path path)
    {
        this.finished = true;
        this.successful = true;
        this.path = path;
    }

    public synchronized void finalizePath()
    {
        this.finished = true;
        this.successful = false;
        this.path = null;
    }

}
