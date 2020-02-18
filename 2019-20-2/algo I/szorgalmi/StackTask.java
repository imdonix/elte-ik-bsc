class StackTask
{
	public static void main(String[] args)
	{
		Solution sol = new Solution();
		System.out.println(sol.IsSymmetry(args[0]));
	}
}

class Solution
{
	CharStack v;
	
	boolean IsSymmetry(String x)
	{
		boolean sym = true;
		boolean tk = false;
		int n = x.length();
		v = new CharStack(n);

		
		for(int i=0;i < n && sym;i++ )
			if(x.charAt(i) == '#')
			{
				if(tk && !v.isEmpty())
					sym = false;
				
				if(!v.isEmpty())
					tk = true;
			}
			else
				if(tk)
				{

					sym = v.pop() == x.charAt(i);
					tk = !v.isEmpty();
				}
				else
					v.push(x.charAt(i));
		
		sym = sym && v.isEmpty();
		return sym;
	}
}

class CharStack
{
	char[] x;
	int i;	
	
	CharStack(int n)
	{
		x = new char[n];
		i = 0;
	}
	
	void push(char c)
	{
		x[i++] = c;
	}
	
	char pop()
	{
		return x[--i];
	}
	
	boolean isEmpty()
	{
		return i == 0;
	}
}