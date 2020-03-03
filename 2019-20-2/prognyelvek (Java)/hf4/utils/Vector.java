package utils;

public class Vector
{
	int n;
	int[] arr;
	
	public Vector(int n, int[] arr)
	{
		this.n = n;
		this.arr = arr;
	}
	
	public String toString()
	{
		StringBuilder sb = new StringBuilder("(");
		for(int x=0;x<n;x++)
			sb.append(Integer.toString(arr[x]) + (x != n-1 ? "," : ")"));
		sb.append("\r\n");
		return sb.toString();
	}
	
	public static Vector add(Vector left, Vector right)
	{
		if(left.n != right.n)
			return null;
		
		Vector v = new Vector(left.n, new int[left.n]);
		for(int x=0;x<left.n;x++)
			v.arr[x] = left.arr[x] + right.arr[x];
		return v;		
	}
	
	public static Vector scalar(Vector left, int s)
	{
		Vector v = new Vector(left.n, new int[left.n]);
		for(int x=0;x<left.n;x++)
			v.arr[x] = left.arr[x] * s;
		return v;		
	}
	
	public static int dotproduct(Vector left, Vector right)
	{
		int s = 0;
		for(int x=0;x<left.n;x++)
			s += left.arr[x] * right.arr[x];
		return s;		
	}
	
	public static Vector remove(Vector left, Vector right)
	{
		right = Vector.scalar(right,-1);
		return Vector.add(left, right);		
	}
	
}