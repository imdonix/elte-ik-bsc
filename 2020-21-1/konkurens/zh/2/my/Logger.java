package my;

import com.sun.deploy.panel.JSmartTextArea;

import javax.xml.crypto.Data;
import java.io.*;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

public class Logger
{
    private final PrintWriter writer;
    private final PipedOutputStream outputStream;
    private final DataOutputStream dataOutputStream;
    private final AtomicBoolean alive;
    private final Semaphore semaphore;
    private int size;


    public Logger(PrintWriter writer)
    {
        if(writer == null) throw new IllegalArgumentException();
        this.writer = writer;
        outputStream = new PipedOutputStream();
        dataOutputStream = new DataOutputStream(outputStream);
        alive = new AtomicBoolean(true);
        size = 10;
        semaphore = new Semaphore(size);
        createLoggerThread();
    }

    public Logger(OutputStream writer)
    {
        if(writer == null) throw new IllegalArgumentException();
        this.writer = new PrintWriter(writer);
        outputStream = new PipedOutputStream();
        dataOutputStream = new DataOutputStream(outputStream);
        alive = new AtomicBoolean(true);
        size = 10;
        semaphore = new Semaphore(size);
        createLoggerThread();
    }

    public Logger()
    {
        this.writer = new PrintWriter(System.err);
        outputStream = new PipedOutputStream();
        dataOutputStream = new DataOutputStream(outputStream);
        alive = new AtomicBoolean(true);
        size = 10;
        semaphore = new Semaphore(size);
        createLoggerThread();
    }

    public void log(String log) throws IllegalStateException
    {
        if(!alive.get()) throw new IllegalStateException();

        try
        {
            synchronized (dataOutputStream)
            {

                dataOutputStream.writeUTF(String.format("%d %s", System.currentTimeMillis(), log));
                dataOutputStream.flush();
                try { semaphore.acquire(); }
                catch (InterruptedException e) {}
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public void close()
    {
        alive.set(false);
    }

    public void setCapacity(int capacity)
    {
        int next = capacity - size;
        if(next > 0)
            semaphore.release(next);
        else {
            try {
                semaphore.acquire(-next);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private void createLoggerThread()
    {
        try {
            new Thread(new LoggerThread(outputStream, writer, alive, semaphore)).start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class LoggerThread implements Runnable
{
    private final DataInputStream inputStream;
    private final PrintWriter writer;
    private final AtomicBoolean alive;
    private final Semaphore semaphore;
    private boolean empty;

    public LoggerThread(PipedOutputStream stream, PrintWriter writer, AtomicBoolean alive, Semaphore semaphore) throws IOException {
        inputStream = new DataInputStream(new PipedInputStream(stream));
        this.writer = writer;
        this.alive = alive;
        this.empty = true;
        this.semaphore = semaphore;
    }

    @Override
    public void run()
    {
        while(!empty || alive.get())
        {
            try
            {
                String data = inputStream.readUTF();
                writer.println(data);
                writer.flush();
                semaphore.release();
            }
            catch (IOException e)
            {
                empty = true;
            }
        }
    }
}