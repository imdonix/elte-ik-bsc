package hu.elte.madtycoon.objects;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entities.Visitor;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;

import java.util.Queue;

public abstract class Game extends Building {
    private int max;
    private  float period;
    private float timer;
    private int useCost;
    private Queue <Visitor> queue;

    public Game(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, float health,
                float decorationValue, boolean opened, boolean needRepair, int max, float period, float timer,
                int useCost, Queue<Visitor> queue) {
        super(world, sprite, position, size, health, decorationValue, opened, needRepair);
        this.max = max;
        this.period = period;
        this.timer = 0;
        this.useCost = useCost;
        this.queue = queue;
    }

    public void enter(Visitor visitor) {
        if(queue.size() < max) {
            queue.add(visitor);
        }
    }

    protected boolean gameStart() {
        if(queue.size() == max) {
            return true;
        }
        return false;
    }

    @Override
    protected int getRenderLayer() {
        return 1;
    }

    @Override
    public void update(float dt) {
        super.update(dt);
        if(gameStart()) {
            this.setOpened(false);
        }

        this.timer++;

        if(timer == period) {
            for(int i = 0; i< queue.size(); i++) {
                this.reward(queue.element());
            }
        }

        this.reset();
    }

    public void reset() {
        this.setOpened(true);
        timer = 0;
        queue.clear();
    }

    protected abstract void reward(Visitor visitor);

    public void setUseCost(int useCost) {
        this.useCost = useCost;
    }


}
