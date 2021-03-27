package hu.elte.madtycoon.core;


import java.util.LinkedList;
import java.util.List;

public class Coroutines
{

    private final List<Coroutine> coroutines;
    private float timer;

    public Coroutines()
    {
        this.coroutines = new LinkedList<>();
    }

    public void update(float dt)
    {
        timer += dt;

        List<Coroutine> expired = new LinkedList<>();
        for(Coroutine coroutine : coroutines)
            if(coroutine.isReady(timer))
            {
                coroutine.task.run();
                expired.add(coroutine);
            }
        coroutines.removeAll(expired);
    }

    public void schedule(float timeout, Runnable task)
    {
        coroutines.add(new Coroutine(timer + timeout , task));
    }

    private class Coroutine
    {

        public final float timeout;
        public final Runnable task;

        public Coroutine(float timeout, Runnable task)
        {
            this.timeout = timeout;
            this.task = task;
        }

        public boolean isReady(float timer){ return timer >= timeout;}
    }

}
