import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;

public class dfstype
{
	
	public static void main(String[] args)
	{		
		DiGraph graph = new DiGraph(args);
		graph.show();	
		
		System.out.println("----\nNem tökéletes a Vissza éleket nem találja meg\n---\n");
		
		AtomicInteger time = new AtomicInteger(0);
		for(Vert v : graph.verts)
			if(!v.visited)
				visit(graph, v, time);
		
		Scanner scan = new Scanner(System.in);
		
		while(true) 
		{
			Vert u = graph.get(scan.next());
			Vert v = graph.get(scan.next());
			System.out.println("(%s, %s) - %s".formatted(u.id, v.id, getType(u,v)));	
		}
	}

	private static void visit(DiGraph graph, Vert v, AtomicInteger time) 
	{		
		v.reachTime = time.incrementAndGet();
		v.visited = true;
		for(Vert u : v.connected)
			if(!u.visited)
				visit(graph, u, time);
		v.endTime = time.incrementAndGet();		
	}
	
	private static String getType(Vert u, Vert v)
	{
		if(u.reachTime < v.endTime)
			return "E";
		if(u.reachTime > v.endTime)
			return "K";
		return "H";
	}

}
