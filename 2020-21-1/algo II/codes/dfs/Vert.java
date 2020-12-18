import java.util.LinkedList;
import java.util.List;

public class Vert 
{
	public final String id;
	public final List<Vert> connected;
	public boolean visited;
	public int reachTime; //d
	public int endTime;	//f
	
	public Vert(String id)
	{
		connected = new LinkedList<Vert>();
		this.id = id;
		this.visited = false;
		this.reachTime = 0;
		this.endTime = 0;
	}
	
    public boolean greater(Vert v)
    {
    	try 
    	{
    		return Integer.parseInt(id) > Integer.parseInt(v.id);
    	}
        catch (NumberFormatException nfe) 
        {
        	return id.compareTo(v.id) < 0;
        }    		
    }
	
	@Override
	public String toString()
	{
		return id + "| d(" + reachTime + ") | f(" + endTime + ") | ";
	}
	
	@Override
	public boolean equals(Object o)
	{
		if(o instanceof Vert )
			return id.equals(((Vert)o).id);
		return false;
	}
	
    @Override
    public int hashCode()
    {
        return id.hashCode();
    }
	
}
