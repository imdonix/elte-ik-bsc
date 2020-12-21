package my;

import java.io.OutputStream;
import java.io.PrintWriter;

public class Logger
{
    private final PrintWriter writer;

    public Logger(PrintWriter writer)
    {
        if(writer == null) throw new IllegalArgumentException();
        this.writer = writer;
    }

    public Logger(OutputStream writer)
    {
        if(writer == null) throw new IllegalArgumentException();
        this.writer = new PrintWriter(writer);
    }

    public Logger()
    {
        this.writer = new PrintWriter(System.err);
    }

    public synchronized void log(String[] logs)
    {
        for (String log : logs)
        {
            writer.println(String.format("%d %s", System.currentTimeMillis(), log));
        }
        writer.flush();
    }
}
