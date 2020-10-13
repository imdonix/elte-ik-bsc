import java.io.IOException;

public class Talk {

	private static void readFromConsole( Connection connection, Alive isAlive ){
		try {
			java.io.Console in = System.console();
			String str;
			while( isAlive.get() && (str = in.readLine()) != null ){
				connection.send(str);
			}
		} catch( IOException e ){
			// sending through connection has failed
			// nothing to do, go and shut down
		} finally {
			shutdown( connection, isAlive );
		}
	}

	private static void receiveFromConnection( Connection connection, Alive isAlive ){
		try {
			while( isAlive.get() ){
				String str = connection.receive();
				System.out.println(">> " + str + " <<");
			}
		} catch( IOException e ){
			// reading from connection has failed
			// nothing to do, go and shut down
		} finally {
			shutdown( connection, isAlive );
		}
	}

	private static void shutdown( Connection connection, Alive isAlive ){
		try { connection.close(); }
		catch( IOException e ){ e.printStackTrace(); }
		isAlive.stop();
	}

	public static void communicate( boolean isServer ){
		try {
			final Connection connection = isServer 
		                                   ? Connection.accept()
		                                   : Connection.connect();
			final Alive isAlive = new Alive();
			Thread reader = new Thread( () -> readFromConsole(connection,isAlive) );
			reader.setDaemon(true);
			reader.start();
			receiveFromConnection(connection,isAlive);
		} catch( IOException e ){
			System.err.println( "Connection could not be established." );
			e.printStackTrace();
		}
	}

	private static class Alive {
		public synchronized void stop(){
			alive = false;
		}
		public synchronized boolean get(){
			return alive;
		}
		private boolean alive = true;
	}

}

class TalkServer {
	public static void main( String[] args ){
		Talk.communicate(true);
	}
}

class TalkClient {
	public static void main( String[] args ){
		Talk.communicate(false);
	}
}

