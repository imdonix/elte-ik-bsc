package pipedPrime;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main 
{
	public static void main(String[] args) throws IOException
	{
		final long n = 16;
		final int t = 16;
		final PipedOutputStream out = new PipedOutputStream();
		final PipedInputStream in = new PipedInputStream(out);
		
		ConsoleWriter wr =  new ConsoleWriter(in);
		
		long chunk = n/t;
		PrimeSearcher[] ps = new PrimeSearcher[t];
		for(int i = 0; i < t; i++)
			ps[i] = new PrimeSearcher(chunk * i, chunk * (i+1), out);
		
		wr.start();
		for(int i = 0; i < t; i++)
			ps[i].start();
		
	}

}