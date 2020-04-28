class Stream
{
	private int maxLen;
	private int length;
	private Logger logger;
	
	public Stream(int e,int d,Logger logger)
	{
		if(e<0 && d<0) 
			throw new IllegalArgumentException();
		maxLen=e;
		length=d;
		this.logger=logger;
	}
	
	public void startStreaming()
	{
		for(int i=0;i<length;i++)
			logger.log(generateRandomString());
	}
	
	private String generateRandomString()
	{
		 String AlphaNumericString = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		 StringBuilder sb = new StringBuilder(maxLen);
		 
		 for(int i=0;i<maxLen;i++)
			 sb.append(AlphaNumericString .charAt((int)(AlphaNumericString.length() * Math.random())));
		 return sb.toString();
	}
	

}