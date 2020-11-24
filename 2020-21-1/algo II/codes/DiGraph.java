import java.util.HashSet;

public class DiGraph 
{
	public HashSet<Vert> verts;
	
	public DiGraph(String[] pairs)
	{	
		if(pairs.length % 2 != 0)
			throw new IllegalArgumentException("Bad edge count");
		
		verts = new HashSet<Vert>();
		for(String id : pairs)
			verts.add(new Vert(id));

		for(int i = 0; i < pairs.length; i+=2)
			get(pairs[i]).connected.add(get(pairs[i+1]));			
	}
	
	public DiGraph(String[] pairs, boolean reverse)
	{	
		if(pairs.length % 2 != 0)
			throw new IllegalArgumentException("Bad edge count");
		
		verts = new HashSet<Vert>();
		for(String id : pairs)
			verts.add(new Vert(id));

		for(int i = 0; i < pairs.length; i+=2)
			get(pairs[i+1]).connected.add(get(pairs[i]));			
	}
	
	public Vert get(String id)
	{
		for(Vert v : verts)
			if(v.id.equals(id))
				return v;
		throw new  IllegalArgumentException("Edge doesnt exists: " + id);
	}
	
	public void show()
	{
		for(Vert v : verts)
		{
			System.out.print(v.id + " - ");
			for(Vert u : v.connected)
				System.out.print(u.id  + "|");
			System.out.println();
		}		
	}
	
}
