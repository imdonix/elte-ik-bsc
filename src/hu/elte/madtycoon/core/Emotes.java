package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Emote;
import hu.elte.madtycoon.objects.GameObject;
import hu.elte.madtycoon.render.LayeredSprite;
import hu.elte.madtycoon.render.SpriteRenderBuffer;

import java.util.*;

public class Emotes
{
    private final World world;
    private final Map<GameObject, Queue<Emote>> emotes;

    public Emotes(World world)
    {
        this.world = world;
        this.emotes = new HashMap<>();
    }

    public void pop(GameObject holder, String type)
    {
        Emote emote = Emote.Create(world, holder, type);
        emote.setActive(false);
        if(emotes.containsKey(holder))
            emotes.get(holder).add(emote);
        else
        {
            Queue<Emote> tmp = new ArrayDeque<>();
            tmp.add(emote);
            emotes.put(holder, tmp);
        }
    }

    public void update(float dt)
    {
        for(Queue<Emote> q : emotes.values())
        {
            Emote e = q.peek();
            if(e != null)
            {
                e.setActive(true);
                e.update(dt);
                if(e.isTimeToDie()) q.poll();
            }
        }
    }

    public void render(SpriteRenderBuffer buffer)
    {
        for(Queue<Emote> q : emotes.values())
        {
            Emote e = q.peek();
            if(e != null) e.render(buffer);
        }
    }
}
