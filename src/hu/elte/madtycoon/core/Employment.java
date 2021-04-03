package hu.elte.madtycoon.core;

import hu.elte.madtycoon.objects.Worker;
import hu.elte.madtycoon.objects.buildings.Shop;
import hu.elte.madtycoon.objects.entities.Cleaner;
import hu.elte.madtycoon.objects.entities.RepairMan;
import hu.elte.madtycoon.objects.entities.ShopAssistant;
import hu.elte.madtycoon.ui.components.TextComponent;
import hu.elte.madtycoon.ui.components.employement.FireComponent;
import hu.elte.madtycoon.ui.components.employement.HireComponent;
import hu.elte.madtycoon.ui.components.employement.StartInterviewsComponent;
import hu.elte.madtycoon.ui.components.employement.WorkerDisplayComponent;
import hu.elte.madtycoon.ui.core.Preview;
import hu.elte.madtycoon.utils.Random;
import hu.elte.madtycoon.utils.Vector2F;

import java.util.ArrayList;
import java.util.List;

public class Employment
{
    public final static float INTERVIEW_TIME = 60;

    private final World world;
    private final F[] creators;
    private List<Worker> workers;


    public Employment(World world)
    {
        this.creators = new F[]{Cleaner::Create, RepairMan::Create, ShopAssistant::Create};
        this.world = world;
        createNewWorkerList();
    }

    public void schedule()
    {
        workers = null;
        world.getCoroutines().schedule(INTERVIEW_TIME, () -> createNewWorkerList());
    }

    public void hire(Worker worker)
    {
        if(workers != null)
        {
            workers.remove(worker);
            worker.hire();
        }
    }

    public Preview getPreview()
    {
        List<Worker> yours = world.getWorkers();

        Preview preview = new Preview("Employment");

        if(workers == null)
            preview.addContent(new TextComponent("Interviews are in progress... "));
        else
        {
            preview.addContent(new TextComponent( String.format("Candidates [%d]", workers.size())));
            for(Worker worker : workers)
                preview.addContent(new HireComponent(worker,this));
            preview.addAction(new StartInterviewsComponent(this));
        }

        preview.addContent(new TextComponent(String.format("Your employment [%d]", yours.size())));
        for(Worker worker : yours)
            preview.addContent(new FireComponent(worker));

        return preview;
    }

    private void createNewWorkerList()
    {
        workers = new ArrayList<Worker>();
        for (int i = 0; i < Random.getRandomInt(2,5); i++)
            workers.add(creators[Random.getRandomInt(0,3)].Create(world, Vector2F.ZERO));
    }

    @FunctionalInterface
    interface F
    {
        Worker Create(World world, Vector2F position);
    }

}
