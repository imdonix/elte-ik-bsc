# Notes

1. Létrehozás

i.) `Thread` [doc](https://docs.oracle.com/en/java/javase/14/docs/api/java.base/java/lang/Thread.html)
  * `run`: amit vegrehajtunk
  * `start`: magát a szálat indítja

  Származtatással:

  class MyThread extends Thread {
    @Override
    public void run() {
      // ...
    }
  }

  Thread myLittleThreadInstance = new MyThread();
  myLittleThreadInstance.start();

ii.) `Runnable` [doc](https://docs.oracle.com/en/java/javase/14/docs/api/java.base/java/lang/Runnable.html)
  * `run`: amit vegrehajtunk

  class MyRunnable implements Runnable {
    @Override
    public void run() {
      // ...
    }
  }

  Thread thread = new Thread(new MyRunnable());
  thread.start();


