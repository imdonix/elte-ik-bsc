package tron;

import java.awt.Color;
import java.awt.Graphics;
import java.util.LinkedList;
import java.util.List;

public class Player
{
	private final int size = 20;
	private final List<GameObject> body;
	private final Color color;
	private final String name;
	private Point direction;
	
    public Player(String name, Point position, Color color)
    {
    	this.name = name;
    	this.color = color;
    	this.direction = Point.down;
        this.body = new LinkedList<GameObject>();
        addPart(position);
    }

    public void setDirection(Point direction)
    {
    	this.direction = direction;
    }
    
    public void move() 
    {
    	if(!direction.isNull()) 
    	{
	    	Point head = getPosition().add(direction);
	    	addPart(head);
    	}
    }
    
    public Point getPosition()
    {
    	return body.get(0).position;
    }
    
    public boolean contain(Point p)
    {
    	for(GameObject o : body)
    		if(o.position.equals(p))
    			return true;
    	return false;
    }
    
	public void draw(Graphics g) 
	{
		g.setColor(color);
		for(GameObject o : body)
			o.draw(g);
	}
    
	public String getName()
	{
		return name;
	}
	
	public boolean valid()
	{
		return getName() != null;
	}
	
    private void addPart(Point p)
    {
    	body.add(0,new GameObject(p, size));
    }

}