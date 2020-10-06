public enum Weather 
{
	Sunny,
	Cloudy,
	Rainy;
	
	public static Weather fromChar(char c) 
	{
		switch(c) 
        { 
            case 'n': return Sunny;
            case 'f': return Cloudy;
            case 'e': return Rainy;
            default: 
                throw new IllegalArgumentException(String.format("The given wheater type doesnt exists: %c ", c));
        } 
	}
}
