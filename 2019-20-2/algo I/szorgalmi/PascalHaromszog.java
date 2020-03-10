class PascalHaromszog
{
	public static void main(String[] args)
	{
		int k = Integer.parseInt(args[0]);
		for(int i=1;i<=k;i++)
			PascalKSor(i).print();		
	}
	
	//SZORGALMI ALGO
	static Queue PascalKSor(int k)
	{
		Queue q = new Queue(k);
		q.add(1);
		for(int i=1;i<k;i++)
		{
			for(int j=0;j<i-1;j++)
				q.add(q.rem() + q.first()); 
			q.add(1);
		}
		return q;
	}
}

class Queue
{
	int[] Z;
	int n,k;
	
	Queue(int m)
	{
		Z = new int[m];
		n = k = 0;
	}
	
	void add(int x)
	{
		if(n<Z.length)
			Z[(k+n++) % Z.length] = x;
	}
	
	int rem()
	{
		if(n>0)
		{
			n--;
			int i = k;
			k = (k+1) % Z.length;
			return Z[i];
		}
		else
			return -1;
	}
	
	int first()
	{
		if(n>0)
			return Z[k];
		else
			return -1;
	}
	
	void print()
	{
		int f = n;
		for(int i=0;i<f;i++)
			System.out.print(rem() + " ");
		System.out.println();
	}
}