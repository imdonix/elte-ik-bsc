package polyhedra;

abstract class Prism
{
	protected double h;
	
	public double volume(){return baseArea() * h;}
	
	protected abstract double baseArea();
}