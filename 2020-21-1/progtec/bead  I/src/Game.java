import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Game 
{
	private String src;
	private List<Entity> entities;
	private String gamePlay;
	private boolean loaded;
	
	public Game(String src)
	{
		this.src = src;
		loaded = false;
		
	}
	
	public void Load() throws FileNotFoundException, IllegalArgumentException
	{
		Scanner scanner = new Scanner(new File(src));
		
		int size = scanner.nextInt();
		entities = new ArrayList<Entity>(size);
		
		for(int i = 0; i < size; i++)
			entities.add(Entity.Create(scanner));
		
		if(scanner.hasNext())
			gamePlay = scanner.next();
		else
			gamePlay = "";
		
		loaded = true;
	}
	
	public Entity Play() throws NotLoadedException, NoWinnerException, IllegalArgumentException
	{
		if(!loaded)
			throw new NotLoadedException();
		
		for (char w : gamePlay.toCharArray())
			for(Entity ent : entities)
				ent.apply(Weather.fromChar(w));
		
		entities = entities.stream().filter(e -> e.isAlive()).collect(Collectors.toList());
		
		Collections.sort(entities);
		
		if(entities.size() > 0)
			return entities.get(0);
		else
			throw new NoWinnerException();
	}
	
}
