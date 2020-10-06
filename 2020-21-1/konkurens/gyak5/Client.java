public class Client {
  public static void main(String[] args) throws java.io.IOException {
    try (Connection connection = Connection.connect()) {
      for (int i = 0; i < args.length; ++i) {
        connection.send(args[i]);
        System.out.println(connection.receive());
      }
    }
  }
}
