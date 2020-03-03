class PointsMain
{
	public static void main(String[] args)
	{
		Point p1 = new Point(0,0);
		Point p2 = new Point(3,0);
		Point p3 = new Point(0,3);
		
		Point[] ps = {p1,p2,p3};
		Point.centerOfmass(ps).print();
		
		int[] linearData = {1,2,3,4,5,6,7,8,9};
		IntegerMatrix im = new IntegerMatrix(3,3,linearData);
		System.out.println(im.toString());
	}
}