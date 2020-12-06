package tron;

import java.awt.Graphics;

public class GameObject 
{
	public final int size;
    public final Point position;

    public GameObject(Point position, int size) 
    {
        this.position = position;
        this.size = size;
    }
    
    public void draw(Graphics g) 
    {
        g.fillRect(position.x * size, position.y * size, size, size);
    }
}
