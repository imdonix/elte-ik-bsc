class Main 
{
  public static void main(String[] args) 
  {
    int times = 100;

    Thread t1 = new Thread(
      ()->
      {
        for(int i=0;i<times;i++)
          {
            System.out.print("*".repeat(200));
            Thread.yield();
          }
      });

    Thread t2 = new Thread(
      ()->
      {
        for(int i=0;i<times;i++)
          {
            System.out.print("_".repeat(200));
            Thread.yield();
          }
      });

    t1.start();
    t2.start();
  }
}

class WithRunnable
{
  static class MyWrite implements Runnable
  {
    private String text;

    public MyWrite(String text)
    {this.text = text;}

    @Override
    public void run() 
    {
        for(int i=0;i<100;i++)
          {
            System.out.print(text.repeat(200));
            Thread.yield();
          }
    }
  }

  public static void main(String[] args) 
  {
    Thread t1 = new Thread(new MyWrite("*"));
    Thread t2 = new Thread(new MyWrite("_"));
    t1.start();
    t2.start();
  }

}

class PrimeSearch
{
  public static void main(String[] args)
  {
    System.out.print(Runtime.getRuntime().availableProcessors());
  }

}