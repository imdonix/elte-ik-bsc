import java.util.concurrent.atomic.AtomicInteger;

public class dfstopologic 
{
	
	public static void main(String[] args)
	{
		DiGraph graph = new DiGraph(args, true);
		graph.show();	
		
		System.out.println("----");
		
		for(int c = 0; c < graph.verts.size(); c++)
		{
			Vert u = null;
			for(Vert v : graph.verts)
				if(!v.visited && check(v))
					if(u == null || v.greater(u))
						u = v;
			
			if(u == null)
				throw new IllegalArgumentException("Cant find a good node");
			u.visited = true;
			
			System.out.print(u.id + ";");
		}
	
	}	
	
	private static boolean check(Vert v)
	{
		for(Vert u : v.connected)
			if(!u.visited)
				return false;
		return true;
	}

}
