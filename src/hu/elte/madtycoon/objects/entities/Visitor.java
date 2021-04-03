package hu.elte.madtycoon.objects.entities;

import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.task.*;
import hu.elte.madtycoon.task.utils.Idle;
import hu.elte.madtycoon.task.utils.LeavePark;
import hu.elte.madtycoon.task.utils.GoShop;
import hu.elte.madtycoon.task.visitor.Play;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.awt.image.BufferedImage;
import java.util.LinkedList;
import java.util.List;

public class Visitor extends Entity
{

    public static int START_MONEY_MIN = 200;
    public static int START_MONEY_MAX = 500;
    public static float START_FOOD_MIN = 0.65f;
    public static float START_FOOD_MAX = 0.8f;
    public static float START_INT_MIN = 0.2f;
    public static float START_INT_MAX = 0.5f;
    public static float MIN_MS_SPEED = 1F;
    public static float MAX_MS_SPEED = 2F;

    private final float movementSpeed;
    private final List<Game> visited;

    private Visitor(World world, AnimatedSprite sprite, Vector2F position)
    {
        super(world, sprite, position);
        this.money = Random.getRandomInt(START_MONEY_MIN, START_MONEY_MAX);
        this.food = Random.getRandomFloat(START_FOOD_MIN, START_FOOD_MAX);
        this.interest = Random.getRandomFloat(START_INT_MIN, START_INT_MAX);
        this.movementSpeed = Random.getRandomFloat(MIN_MS_SPEED, MAX_MS_SPEED);
        this.visited = new LinkedList<>();
    }

    public void addVisited(Game game)
    {
        visited.add(game);
    }

    @Override
    protected void start()
    {
        if(world.getEntrance().getEntranceCost() > money / 2)
            task = new LeavePark(this);
        else
            pay(world.getEntrance().getEntranceCost());
    }

    @Override
    public float getMovementSpeed()
    {
        return movementSpeed;
    }

    @Override
    protected Task getNewTask()
    {
        List<Game> unvisited = getUnvisitedGames();

        if(unvisited.size() > 0 && interest > .1F && food > .1F)
        {
            if(food > .45F)
            {
                Game game = findNearestGame(unvisited);

                if(game != null)
                    return new Play(this, game);
                else
                    return new Idle(this);
            }
            else
                return super.getNewTask();
        }
        else
            return new LeavePark(this);
    }

    @Override
    public void onDestroy() { }

    private List<Game> getUnvisitedGames()
    {
        List<Game> tmp = new LinkedList<>();
        for(Game game : world.getGames())
            if(!visited.contains(game))
                tmp.add(game);
        return tmp;
    }

    private List<Shop> getShop()
    {
        List<Shop> tmp = new LinkedList<>(world.getShops());
        return tmp;
    }

    private Game findNearestGame(List<Game> games)
    {
        Game min = null;
        for(Game game : games)
            if(game.isWorking())
                if(min == null || min.getPosition().distance(position) > game.getPosition().distance(position))
                    min = game;
        return min;

    }

    public static Visitor Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("visitor_idle");
        BufferedImage[] walk = AnimationResource.Instance.get("visitor_walk");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.25f);
        anim.addState(AnimatedSprite.WALK, walk);
        return new Visitor(world, anim, position);
    }
}
