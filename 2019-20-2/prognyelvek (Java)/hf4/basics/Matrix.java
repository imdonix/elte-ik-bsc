
package basics;

import java.lang.StringBuilder;

public class Matrix
{
	int n,m;
	int[][] matrix;
	
	public Matrix(int n, int m)
	{
		this.n = n;
		this.m = m;
		matrix = new int[n][m];		
	}
	
	public Matrix(int n, int m, int[][] matrix)
	{
		this.n = n;
		this.m = m;
		this.matrix = matrix;
	}
	
	public String toString()
	{
		StringBuilder sb = new StringBuilder("|");
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<m;y++)
				sb.append(Integer.toString(matrix[x][y]) + "|");
			sb.append("\r\n" + (x != n-1 ? "|" : ""));
		}
		return sb.toString();
	}
	
	public static Matrix unit(int n)
	{
		Matrix m = new Matrix(n,n);
		for(int i=0;i<n;i++)
			m.matrix[i][i] = 1;
		return m;
	}
	
	public static Matrix transponate(Matrix m)
	{
		Matrix t = new Matrix(m.m,m.n);
		for(int x=0;x<m.n;x++)
			for(int y=0;y<m.m;y++)
				t.matrix[y][x] = m.matrix[x][y];
		return t;
	}
	
	public static Matrix negate(Matrix m)
	{
		Matrix t = new Matrix(m.n,m.m);
		for(int x=0;x<m.n;x++)
			for(int y=0;y<m.m;y++)
				t.matrix[x][y] = -m.matrix[x][y];
		return t;
	}
	
	public static Matrix add(Matrix left, Matrix right)
	{
		if(left.n != right.n || left.m != right.m)
			return null;
		
		Matrix s = new Matrix(left.n,left.m);
		for(int x=0;x<left.n;x++)
			for(int y=0;y<left.m;y++)
				s.matrix[x][y] = left.matrix[x][y] + right.matrix[x][y];			
		return s;
	}
	
	public static Matrix remove(Matrix left, Matrix right)
	{
		
		return add(left, Matrix.negate(right));
	}
	
}