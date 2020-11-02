import java.io.IOException;
import java.io.EOFException;
import java.util.Set;
import java.util.HashSet;

public class ChatRoom {

    static private class ConnectionSet {
        // TODO: IMPLEMENT ME
    }

    static private class ClientHandler implements Runnable {

        private final ConnectionSet activeConnections;
        private final Connection myClient;

        ClientHandler(ConnectionSet activeConnections, Connection myClient) {
            assert activeConnections != null && myClient != null;
            this.activeConnections = activeConnections;
            this.myClient = myClient;
        }

        @Override
        public void run() {
            boolean running = true;
            while (running) {
                try {
                    String message = myClient.receive();
                    activeConnections.sendToAllButOne(message, myClient);
                } catch (EOFException e) {
                    // client closes down, so we quit
                    running = false;
                } catch (IOException e) {
                    // report error and quit
                    e.printStackTrace();
                    running = false;
                }
            }
            try {
                activeConnections.remove(myClient);
                myClient.close();
            } catch (IOException e) {
                // close failed, report error and stop
                e.printStackTrace();
            }
        }
    }


    public static void start() {
        ConnectionSet activeConnections = new ConnectionSet();
        while (true) {
            try {
                // TODO: IMPLEMENT ME
            } catch (IOException e) {
                // accept failed; report and go on
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        ChatRoom.start();
    }
}

