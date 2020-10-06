import java.io.*;
import java.net.*;

public class Connection implements AutoCloseable {

	public static Connection accept() throws IOException {
		if( serverSocket == null ){
			serverSocket = new ServerSocket( port );
		}
		return new Connection( serverSocket.accept() );
	}

	public static Connection connect() throws IOException {
		return new Connection( new Socket( server, port ) );
	}

	public void send( String str ) throws IOException {
		out.writeUTF( str );
		out.flush();
	}

	public String receive() throws IOException {
		return in.readUTF();
	}

	public void close() throws IOException {
		synchronized(socket){
			if( ! socket.isClosed() ){
				socket.close();
			}
		}
	}

	private static final String server = "localhost";
	private static final int port = 1234;

	private static ServerSocket serverSocket;

	private Socket socket;
	private DataInputStream in;
	private DataOutputStream out;

	private Connection( Socket socket ) throws IOException {
		this.socket = socket;
		in  = new  DataInputStream( socket.getInputStream());
		out = new DataOutputStream(socket.getOutputStream());
	}
}
