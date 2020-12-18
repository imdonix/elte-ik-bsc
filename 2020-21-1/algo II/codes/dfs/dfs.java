import java.util.concurrent.atomic.AtomicInteger;

public class dfs 
{
	
	public static void main(String[] args)
	{		
		DiGraph graph = new DiGraph(args);
		graph.show();	
		
		System.out.println("----");
		
		AtomicInteger time = new AtomicInteger(0);
		for(Vert v : graph.verts)
			if(!v.visited)
				visit(graph, v, time);
		
		for(Vert v : graph.verts)
			System.out.println(v);
				
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
	

}
