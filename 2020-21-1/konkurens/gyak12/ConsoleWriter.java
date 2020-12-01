package pipedPrime;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;

public class ConsoleWriter extends Thread 
{
	private final DataInputStream stream;

	public ConsoleWriter(InputStream stream)
	{
		this.stream = new DataInputStream(stream);
	}
	
	@Override
	public void run()
	{
		boolean live = true;
		while(live) 
		{
			try 
			{
				long l = stream.readLong();
				if(l < 0)
					live = false;
				else
					System.out.println(l);
			} 
			catch (IOException e) {}
		}
	}
	
}
