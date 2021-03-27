package hu.elte.madtycoon.objects.buildings;

import hu.elte.madtycoon.core.Builder;
import hu.elte.madtycoon.core.World;
import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Entity;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.objects.entities.Visitor;
import hu.elte.madtycoon.objects.Game;
import hu.elte.madtycoon.render.AnimatedSprite;
import hu.elte.madtycoon.render.AnimationResource;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.*;

import java.awt.image.BufferedImage;

public class Shop extends Building
{

    public final static String ID = "shop";
    public final static Vector2I SIZE = new Vector2I(5,3);
    public final static Vector2I ENTRANCE = new Vector2I(-2,1);
    public final static int PRICE = 100;
    public final static int FOOD_COST = 100;

    private ShopAssistant employee;
    private int foodCost;


    private Shop(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int foodCost)
    {
        super(world, sprite, position, size);
        this.foodCost = foodCost;
        this.employee = null;
    }

    public void work(ShopAssistant employee) throws JobAlreadyTaken
    {
        if(this.employee != null) throw new JobAlreadyTaken();

        this.employee = employee;
        this.sprite.setState(AnimatedSprite.IDLE);
        this.employee.setActive(false);
    }

    public void eat(Entity entity) throws NoCoverageException, GameUnderConstruction, NoWorkerInDuty, BuildingDestroyed {
        if(employee == null) throw new NoWorkerInDuty();
        if(!isWorking()) throw new GameUnderConstruction();
        if(!entity.pay(foodCost)) throw new NoCoverageException();
        if(!getActive()) throw new BuildingDestroyed();
        world.getEmotes().pop(this, AnimatedSprite.PARK_EARN);

        entity.addFood(0.5F);

        this.employee.earn(employee.getSalary());
    }

    public ShopAssistant getEmployee()
    {
        return employee;
    }

    @Override
    public void onDestroy()
    {
        employee.setActive(true);
    }

    @Override
    protected void start()
    {
        construction(AnimatedSprite.GAME_STOP);
    }

    @Override
    public float getDecorationValue()
    {
        return 0.2F;
    }

    @Override
    public Vector2F getTargetPosition() {
        return super.getTargetPosition().add(new Vector2F(ENTRANCE));
    }


    public static Shop Create(World world, Vector2F position)
    {
        BufferedImage[] idle = AnimationResource.Instance.get("shop_idle");
        BufferedImage[] play = AnimationResource.Instance.get("shop_play");
        BufferedImage[] stop = AnimationResource.Instance.get("shop_stop");
        BufferedImage[] construction = AnimationResource.Instance.get("shop_construction");
        AnimatedSprite anim = new AnimatedSprite(AnimatedSprite.IDLE, idle, 0.75f);
        anim.addState(AnimatedSprite.GAME_PLAY, play);
        anim.addState(AnimatedSprite.GAME_STOP, stop);
        anim.addState(AnimatedSprite.GAME_UNDER_CONSTRUCTION, construction);
        return new Shop(world, anim, position, SIZE, FOOD_COST);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, Shop::Create));
    }

}
