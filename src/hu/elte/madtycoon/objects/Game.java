package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.Queue;

public abstract class Game extends Interactable {
    private int max;
    private float timer;
    private int useCost;
    private Queue <Visitor> queue;

    public Game(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, float health, float decorationValue, boolean opened, boolean needRepair, int max, float timer, int useCost, Queue<Visitor> queue) {
        super(world, sprite, position, size, health, decorationValue, opened, needRepair);
        this.max = max;
        this.timer = timer;
        this.useCost = useCost;
        this.queue = queue;
    }

    @Override
    protected void start() {
        // TODO
    }

    @Override
    protected int getRenderLayer() {
        return 1;
    }

    @Override
    public void update(float dt) {
        super.update(dt);
    }

    protected abstract void reward(Visitor visitor);

    public void setUseCost(int useCost) {
        this.useCost = useCost;
    }


}
