import java.io.*;

class Circle
{
	private final String defaultLabel = "unnamed";
	
	private String tag;
	private Point p;
	private double r;
	
	public Circle(Point p, double r, String tag)
	{
		this.p = new Point(p);
		this.r = r;
		if(tag!=null)
			this.tag = tag;
		else
			this.tag = defaultLabel;
	}
	
	public Circle(double r, String tag)
	{
		this(new Point(0,0),r,tag);
	}
	
	public Circle(double x, double y, double r, String tag)
	{
		this(new Point(x,y),r,tag);
	}
	
	public void saveToFile(String filename) throws IOException
	{
		FileWriter fr = new FileWriter(filename);    
		BufferedWriter br = new BufferedWriter(fr);
		
		br.write(String.valueOf(p.x)); br.newLine();
		br.write(String.valueOf(p.y)); br.newLine();
		br.write(String.valueOf(r)); br.newLine();
		br.write(tag); br.newLine();
		
		br.flush();
		br.close();
	}
	
	public static Circle readFromFile(String filename) 
	{
		Double x = 0.;
		Double y = 0.;
		Double r = 0.;
		String tag = "";
		
		try
		{
			FileReader fr = new FileReader(filename);    
			BufferedReader br = new BufferedReader(fr);
			x = Double.parseDouble(br.readLine());
			y = Double.parseDouble(br.readLine());
			Double.parseDouble(br.readLine());
			tag = br.readLine();
		}
		catch(Exception ex)
		{
			System.out.println("error while reading from " + filename);
		}		
		return new Circle(x,y,r,tag);
	}
	
	
	void enlarge(double f)
	{
		r*=f;
	}	
	
	double getArea()
	{
		return r*r*Math.PI;
	}
	
	public String toString()
	{
		return tag;
	}
	
	public static void main(String[] args)
	{
		try
		{
			Circle c = Circle.readFromFile("in.txt");
			c.saveToFile("out.txt");
		}catch(Exception ex)
		{
			System.out.println(ex.toString());
		}
		
	}
}