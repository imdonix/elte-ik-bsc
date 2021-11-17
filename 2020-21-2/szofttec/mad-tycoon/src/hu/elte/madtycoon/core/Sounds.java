package hu.elte.madtycoon.core;

import java.applet.Applet;
import java.applet.AudioClip;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

public class Sounds
{
    private static List<URL> toDoAfterRestart = new ArrayList<>();

    private static AtomicBoolean audio = new AtomicBoolean(false);
    private static AtomicBoolean music = new AtomicBoolean(false);


    public  static boolean getAudio()
    {
        return audio.get();
    }

    public  static boolean getMusic()
    {
        return music.get();
    }

    public synchronized static void setAudio(boolean audio)
    {
        Sounds.audio.set(audio);
    }

    public synchronized static void setMusic(boolean music)
    {
        Sounds.music.set(music);
        if(music) for(URL ac : toDoAfterRestart) loop(ac, false);
    }

    public static void play(URL clip)
    {
        if(audio.get())
            new Thread(() -> newFromURL(clip).play()).start();
    }

    public static void loop(URL clip)
    {
        loop(clip, true);
    }

    private static void loop(URL clip, boolean isNew)
    {
        new Thread(loopRunnable(clip)).start();
        if(isNew) toDoAfterRestart.add(clip);
    }

    private static Runnable loopRunnable(URL clip)
    {
        return () -> {
            AudioClip sound = Sounds.newFromURL(clip);
            sound.loop();
            while (getMusic())
                try { Thread.sleep(200); } catch (InterruptedException e) { }
            sound.stop();
        };
    }

    private static AudioClip newFromURL(URL url)
    {
        return Applet.newAudioClip(url);
    }

}
