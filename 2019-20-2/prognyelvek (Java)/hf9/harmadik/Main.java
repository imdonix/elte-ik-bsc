class Main
{
	public static void main(String[] args)
	{
		ConsoleLogger consolelogger = new ConsoleLogger();
		ConsoleCipherLogger concolechiper = new ConsoleCipherLogger();
		
		FileLogger filelogger = new FileLogger("ki2.txt");
		
		Stream stream = new Stream(2,1,consolelogger);
		stream.startStreaming();
		
		stream = new Stream(93,120,concolechiper);
		stream.startStreaming();
		
		stream = new Stream(5,5,filelogger);
		stream.startStreaming();
	}
}