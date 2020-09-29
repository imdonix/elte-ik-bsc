import java.util.ArrayList;
import java.util.List;
import java.lang.InterruptedException;
import java.util.concurrent.Semaphore;

class Main
{
  public static void main(String[] args)
  {
    int n = 10000;
    Thread[] trans = new Thread[n];
    SycAccount unsafe = new SycAccount();

    for(int i = 0; i < n; i++)
      trans[i] = new Thread(new Transaction(unsafe, 1));

    for(int i = 0; i < n; i++)
      trans[i].start();

    try
    {
      for(int i = 0; i < n; i++)
        trans[i].join();
    }
    catch(InterruptedException exeption) 
    {}

    System.out.println(unsafe.getMoney());
  }
}

class Transaction implements Runnable 
{
    private final Account account;
    private final long amount;

    public Transaction(Account account, long amount)
    {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() 
    {
        account.increment(amount);
    }
}

abstract class Account 
{
    protected long money = 0;
    protected List<Long> savedTransactions = new ArrayList<>();

    public abstract void increment(long amount);

    public long getMoney()
    {
        for (long t : savedTransactions) 
        {
            money += t;
        }
        savedTransactions.clear();
        return money;
    }
}

class UnsafeAccount extends Account
{
    public void increment(long amount)
    {
        savedTransactions.add(amount);
    }
}

class SemAccount extends Account
{
  Semaphore safe = new Semaphore(1);

  public void increment(long amount)
  {
    try
    {
      safe.acquire();
    }
    catch(InterruptedException exeption) 
    {/* TODO */}
    savedTransactions.add(amount);

    safe.release();
  }
}

class SycAccount extends Account
{
  public synchronized  void increment(long amount)
  {
    savedTransactions.add(amount);
  }
}