import basics.Matrix;
import utils.Vector;
import utils.IntVector;

class Main
{
	public static void main(String[] args)
	{
		System.out.println("m1 =");
		Matrix m1 = new Matrix(2,2);
		System.out.println(m1.toString());
		
		System.out.println("m2 =");
		int[][] m2const =  {{1,2,1},{1,2,1},{1,2,1}};
		Matrix m2 = new Matrix(3,3,m2const);
		System.out.println(m2.toString());
		
		System.out.println("m3 =");
		Matrix m3 = Matrix.unit(3);
		System.out.println(m3.toString());
		
		System.out.println("t1 = T(m2)");
		Matrix t1 = Matrix.transponate(m2);
		System.out.println(t1.toString());
		
		System.out.println("t2 = t1 + m2");
		Matrix t2 = Matrix.add(t1, m2);
		System.out.println(t2.toString());
		
		System.out.println("t2 = t2 - m3");
		Matrix t3 = Matrix.remove(t2,m3);
		System.out.println(t3.toString());
		
		System.out.println("v1 = ");
		int[] v1const = {1,2,3,4};
		Vector v1 = new Vector(4,v1const);
		System.out.println(v1.toString());
		
		System.out.println("v2 = ");
		int[] v2const = {1,2,0,1};
		Vector v2 = new Vector(4,v2const);
		System.out.println(v2.toString());
		
		System.out.println("vt1 = v1 + v2");
		Vector vt1 = Vector.add(v1,v2);
		System.out.println(vt1.toString());
		
		System.out.println("vt2 = v1 - v2");
		Vector vt2 = Vector.remove(v1,v2);
		System.out.println(vt2.toString());
		
		System.out.println("vt3 = vt1 * -1");
		Vector vt3 = Vector.scalar(vt1,-1);
		System.out.println(vt3.toString());
		
		System.out.println("s = vt1 * vt3");
		int s = Vector.dotproduct(vt1,vt3);
		System.out.println(s);
		
		System.out.println("\r\nIntVectors:");
		IntVector iv = new IntVector(v1const);
		System.out.println(iv);
		iv.add(2);
		System.out.println(iv);
		iv.add(4);
		iv.add(5);
		iv.add(6);
		iv.add(8);
		System.out.println(iv);
		IntVector iv2 = new IntVector(v2const);
		System.out.println(IntVector.sum(iv,iv2));
		
		
		
	}
}