package pipedPrime;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class PrimeSearcher extends Thread 
{

	private final DataOutputStream stream;
	private final long start;
	private final long end;
	
	public PrimeSearcher(long start, long end, OutputStream stream)
	{
		this.stream = new DataOutputStream(stream);
		this.start = start;
		this.end = end;
	}
	
	@Override
	public void run()
	{
		for(long l = start; l < end; l++)
			if(isPrime(l))
			{
				try 
				{
					stream.writeLong(l);
					stream.flush();	
				} catch (IOException e) {}		
			}
	}
	
	private static boolean isPrime(long l)
	{
		for(long i = 2; i < l; i++)
			if(l % i == 0)
				return false;
		return true;		
	}
}
