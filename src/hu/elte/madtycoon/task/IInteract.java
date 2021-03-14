package hu.elte.madtycoon.task;

import hu.elte.madtycoon.objects.GameObject;

@FunctionalInterface
public interface IInteract <T extends ITargetable>
{
    public void interact(T object);
}
