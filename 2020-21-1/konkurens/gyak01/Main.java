
class HelloRunnable implements Runnable {
  @Override
  public void run() {
    for (int i = 0; i < 1_000; i += 1) {
      System.out.println(i);
    }
  }
}

class PrimeSearch implements Runnable {

  private final int prime;
  private final int start;
  private final int end;

  PrimeSearch(int prime, int start, int end) {
    this.prime = prime;
    this.start = start;
    this.end = end;
  }

  @Override
  public void run() {
    for (i in start..end) {
      if prime % i != 0:
        ...
    }
  }
}

public class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
    Thread[] threads = new Thread[5];

    for (int i = 0; i < threads.length; i += 1) {
      threads[i] = new Thread(new HelloRunnable());
      threads[i].start();
    }    

    Thread[] primeSearchers = new Thread[5];

    prime = 17;

    for (int i = 0; i < threads.length; i += 1) {
      threads[i] = new Thread(new PrimeSearch(prime, 1 + i, 50 + i));
      threads[i].start();
    } 


  }
}