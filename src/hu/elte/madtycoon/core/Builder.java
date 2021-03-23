package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Building;
import hu.elte.madtycoon.objects.Buildings.*;
import hu.elte.madtycoon.ui.PopWindow;
import hu.elte.madtycoon.utils.BuildReference;
import hu.elte.madtycoon.utils.BuilderState;
import hu.elte.madtycoon.utils.Vector2F;
import hu.elte.madtycoon.utils.Vector2I;
import hu.elte.madtycoon.utils.exception.NoCoverageException;

import java.awt.*;
import java.lang.ref.Reference;
import java.util.HashMap;
import java.util.Map;

public class Builder
{
    public final static Map<String, BuildReference> buildings = new HashMap<>();

    private final World world;

    private BuilderState state;
    private Vector2I selected;
    private BuildReference reference;


    public Builder(World world)
    {
        this.world = world;
        this.state = BuilderState.SELECT;
        this.selected = null;
        this.reference = null;
        init();
    }

    private void init()
    {
        //Games
        CoinFlip.AddReference();

        //Decor
        Bush.AddReference();
        Flower.AddReference();
        Stick.AddReference();
        FirePit.AddReference();
    }


    public void setSelected(Vector2I selected)
    {
        this.selected = selected;
    }

    public void setState(BuilderState state, String buildingID)
    {
        this.state = state;
        this.reference = buildings.get(buildingID);
    }

    public void setState(BuilderState state)
    {
        setState(state, null);
    }


    //INTERFACE

    public void interact() throws NoCoverageException
    {
        if(selected == null || state == BuilderState.NONE) return;

        if(this.state == BuilderState.SELECT) selectBuilding();
        else if(this.state == BuilderState.BUILD) buildBuilding();
    }

    public void showMarker(Graphics g)
    {
        if(selected == null || state == BuilderState.NONE) return;

        if(this.state == BuilderState.SELECT) showSelection(g);
        else if(this.state == BuilderState.BUILD) showBuildingBounding(g);
    }

    //ACTION

    private void selectBuilding()
    {
        Building sb = world.collisionCheck(selected, Vector2I.ONE);
        if(sb != null)
        {
            PopWindow window = new PopWindow(sb,world);
        }
    }

    private void buildBuilding() throws NoCoverageException
    {
        if(world.getMoney() >= reference.price)
        {
            Vector2I realPos = selected.add(reference.size.div(-2));
            Building sb = world.collisionCheck(realPos, reference.size);
            if(sb == null)
            {
                world.pay(reference.price);
                world.instantiate(reference.create(world, new Vector2F(realPos)));
            }
        }
        else
            throw new NoCoverageException();
    }

    //SHOW

    private void showSelection(Graphics g)
    {
        Building sb = world.collisionCheck(selected, Vector2I.ONE);
        if(sb != null)
        {
            Vector2I pos = new Vector2I(sb.getPosition()).mul(Engine.BLOCK_SIZE);
            Vector2I size = sb.getSize().mul(Engine.BLOCK_SIZE);
            g.setColor(Color.MAGENTA);
            g.drawRect(pos.x,pos.y,size.x,size.y);
        }
    }

    private void showBuildingBounding(Graphics g)
    {
        String price = String.format("%d$", reference.price);
        Vector2I realPos = selected.add(reference.size.div(-2));
        Building sb = world.collisionCheck(realPos, reference.size);
        Vector2I pos = realPos.mul(Engine.BLOCK_SIZE);
        Vector2I size = reference.size.mul(Engine.BLOCK_SIZE);
        Vector2I textPos = pos.add(new Vector2I(reference.size.x,1).mul(Engine.BLOCK_SIZE).div(2));
        Vector2I adjustedTextPos = textPos.add(new Vector2I(price.length() * -4,0));
        g.drawString(price, adjustedTextPos.x, adjustedTextPos.y );
        g.setColor(sb == null && world.getMoney() >= reference.price ? Color.GREEN : Color.RED);
        g.drawRect(pos.x,pos.y,size.x,size.y);
    }

}
