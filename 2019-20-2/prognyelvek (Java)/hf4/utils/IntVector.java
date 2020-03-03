package utils; 

import java.util.Arrays;
 
public class IntVector 
{   
	int i;
	int[] ns; 
 
    public IntVector(int[] numbers)
	{         
		ns = numbers; 
		i = numbers.length;
    } 
 
    public void add(int n) 
	{         
		if(i > ns.length-1)
		{
			int[] v = new int[ns.length*2];
			for(int x=0;x<ns.length;x++)
				v[x] = ns[x];
			ns = v;
		}
		
		ns[i++] = n;
	} 
 
    public void increase(int n) 
	{         
		for (int i = 0; i < ns.length; i++)             
			ns[i] += n;     
	} 
 
    public String toString() 
	{         
		return Arrays.toString(ns);
	} 
	
	public static IntVector sum(IntVector left, IntVector right)
	{
		int max = (left.i > right.i ? left.i : right.i);
		int[] v = new int[max];
		for(int i=0;i<max;i++)
		{
			//Ez biztos lehetne szebben/jobban
			if(i < left.i)
				v[i]+=left.ns[i];
			if(i < right.i)
				v[i]+=right.ns[i];
		}
		
		return new IntVector(v);
	}
} 