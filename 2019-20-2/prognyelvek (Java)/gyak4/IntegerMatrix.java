class IntegerMatrix
{
	int[] linearData;
	int rowNum;
	int colNum;
	
	IntegerMatrix(int rowNum, int colNum, int[] linearData)
	{
		this.linearData=linearData;
		this.rowNum=rowNum;
		this.colNum=colNum;
	}
	
	public String toString()
	{
		String s = "";
		for(int i=0;i<rowNum;i++)
			for(int j=0;j<colNum;j++)
				s += Integer.toString(linearData[(colNum*i)+j]) + ((colNum-1 == j) ? ":" : ","); 
		return s.substring(0, s.length()-1);
	}
	
}