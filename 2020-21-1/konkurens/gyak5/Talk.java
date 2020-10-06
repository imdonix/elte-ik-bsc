import java.io.IOException;

class TalkServer	
{
	public static void main(String[] args)
	{
			Talk.communicate(true);
	}
}


class TalkClient	
{
	public static void main(String[] args)
	{
			Talk.communicate(false);
	}
}


class Talk	
{
	
	
	private static void readFromConsole(Connection connection,	Alive isAlive)
	{		
		while(isAlive.getAlive())
		{
			String input = System.console().readLine();
			if(input == null)
				break;
			
			try 
			{
				connection.send(input);
			} 
			catch (IOException e) 
			{
				break;
			}
			
		}
		
		shutdown(connection, isAlive);
	}

	private static void receiveFromConnection(Connection connection,	Alive isAlive)
	{
		while( isAlive.getAlive() )
		{
			try 
			{
				System.out.println(connection.receive());
			}
			catch(IOException e)
			{
				System.out.println("Conncection lost");
			}
		}
		
		shutdown(connection, isAlive);
	}
	
	private static void shutdown(Connection connection,	Alive isAlive)
	{
		isAlive.stop();
		try 
		{
			connection.close();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
	
	public static void communicate(boolean isServer)
	{		
		try (Connection connection = isServer ? Connection.accept() : Connection.connect()) 
		{
			Alive alive = new Alive();
			Thread read = new Thread(() -> readFromConsole(connection, alive));
			read.start();
			receiveFromConnection(connection, alive);
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
	
	private static class Alive	
	{
		private boolean alive;
		
		public Alive()
		{
			alive = true;
		}
		
		public synchronized boolean getAlive()
		{
			return alive;
		}
		
		public synchronized void stop()
		{
			alive = false;
		}
	
	}
}
