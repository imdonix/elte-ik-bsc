package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.Entity;

public abstract class WaitTask extends Task<Entity>
{
    private float execute;

    public WaitTask(Entity entity, float time, IInteract<Entity> interaction)
    {
        super(entity, interaction);
        execute = time;
    }

    @Override
    protected void doPre(float dt)
    {
        execute-=dt;
        if(execute <= 0) reach = true;
    }

    @Override
    protected void interact()
    {
        interaction.interact(entity);
    }
}
