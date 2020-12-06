package tron;

import java.awt.Color;

public class ColorName 
{
	public final String name;
	public final Color color;
	
	public ColorName(String name, Color color) 
	{
		this.name = name;
		this.color = color;
	}
	
	@Override
	public String toString()
	{
		return name;
	}

	public static ColorName[] getList() 
	{			
		ColorName[] colors = 
			{
				new ColorName("Red", new Color(204,0,0)),
				new ColorName("Cyan", new Color(153,153,255)),
				new ColorName("Green", new Color(0,153,0)),
				new ColorName("Magenta", new Color(255,51,153)),
				new ColorName("Yellow", new Color(204,204,0))
			};
		return colors;
	}
	
}
