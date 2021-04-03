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
import hu.elte.madtycoon.ui.components.building.OpenComponent;
import hu.elte.madtycoon.ui.components.building.SetComponent;
import hu.elte.madtycoon.ui.components.building.ToggleComponent;
import hu.elte.madtycoon.ui.components.building.WorkingComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.*;
import hu.elte.madtycoon.utils.exception.*;

import java.awt.image.BufferedImage;

public class Shop extends Building
{

    public final static String ID = "shop";
    public final static Vector2I SIZE = new Vector2I(5,3);
    public final static Vector2I ENTRANCE = new Vector2I(-2,1);
    public final static int PRICE = 100;
    public final static int DEFAULT_FOOD_COST = 20;
    public final static int MAX_FOOD_COST = 50;
    public final static int MIN_FOOD_COST = 10;

    private ShopAssistant employee;
    private int foodCost;


    private Shop(World world, AnimatedSprite sprite, Vector2F position, Vector2I size, int foodCost)
    {
        super(world, sprite, position, size);
        this.foodCost = foodCost;
        this.employee = null;
    }

    public int getFoodCost()
    {
        return foodCost;
    }

    public void setFoodCost(int foodCost)
    {
        this.foodCost = Utils.clamp(MIN_FOOD_COST, MAX_FOOD_COST, foodCost);
    }

    public void work(ShopAssistant employee) throws JobAlreadyTaken, GameUnderConstruction
    {
        if(this.employee != null) throw new JobAlreadyTaken();
        if(!isWorking()) throw new GameUnderConstruction();

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
        if(employee != null) employee.setActive(true);
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

    @Override
    public String getName() { return "Shop"; }

    @Override
    public Preview getPreview() {
        Preview preview = super.getPreview();
        preview.addContent(new OpenComponent(this));
        preview.addContent(new WorkingComponent(this));
        preview.addContent(new SetComponent("Food cost", this::getFoodCost, this::setFoodCost));
        preview.addAction(new ToggleComponent(this::isOpened, this::setOpened));
        return preview;
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
        return new Shop(world, anim, position, SIZE, DEFAULT_FOOD_COST);
    }

    public static void AddReference()
    {
        Builder.buildings.put(ID, new BuildReference(SIZE, PRICE, Shop::Create));
    }

}
