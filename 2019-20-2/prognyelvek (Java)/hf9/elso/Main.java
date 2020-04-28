public class Main
{
	public static void main(String[] args)
	{
		Point p = new Point();
		ColouredCircle cc = new ColouredCircle(p,5,Colour.GREEN);
		
		System.out.printf(cc.getSzin().name()+"\n");
		
		cc = new ColouredCircle(5,12,5,Colour.RED);
		
		System.out.printf(cc.getSzin().name()+"\n");
		
	}
}