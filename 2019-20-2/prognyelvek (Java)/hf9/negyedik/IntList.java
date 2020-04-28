class IntList
{
	public int[] nums;
	public int i;
	private int n;
	
	public IntList(int n)
	{
		this.n=n;
		i=0;
		nums=new int[n];
	}
	
	public void add(int number)
	{
		if(i == n-1) throw new IllegalStateException();
		nums[i++]=number;
	}
	
	public void concat(IntList right)
	{
		if(this.i+right.i >= this.n) throw new IllegalStateException();
		for(int j=0;j<right.i;j++)
			this.add(right.nums[j]);
	}
	
	public String toString()
	{
		if(i==0) return "empty";
		StringBuilder builer = new StringBuilder();
		builer.append(nums[0]);
		for(int j=1;j<i;j++)
			builer.append(","+nums[j]);
		return builer.toString();
	}
	
	public void removeItemsGreaterThan(int limit)
	{
		int s=i;
		int[] temp=new int[n];
		for(int j=0;j<i;j++)
			if(nums[j]>limit) i--;
			else temp[j+s-i]=nums[j];
		nums=temp;
	}
}