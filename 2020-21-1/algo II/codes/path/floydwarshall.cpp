#include <iostream>
#include <vector>
#include <limits>
#include <string>

#define INF 10000


template<typename T>
void printMatrix(const T& M, const std::string& name = "", int k = -2, bool ischar = false, bool ismatrixchar = false)
{
	std::cout << name << ((k != -2) ? std::to_string(k + 1) : "");
	for (int i = 0; i < M.size(); ++i)
	{
		if (ischar)
			std::cout << "\t" << char(i + 'a');
		else
			std::cout << "\t" << i + 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < M.size(); ++i)
	{
		if (ischar)
			std::cout << char(i + 'a') << " [\t";
		else
			std::cout << i + 1 << " [\t";
		for (int j = 0; j < M.size(); ++j)
		{
			if (ismatrixchar)
				if (M[i][j] != INF)
					if (M[i][j] == 0)
						std::cout << '0' << "\t";
					else
						std::cout << char(M[i][j] + 'a' - 1) << "\t";
				else
					std::cout << "INF\t";
			else
				if (M[i][j] != INF)
					std::cout << M[i][j] << "\t";
				else
					std::cout << "INF\t";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;
}

class Graph
{
public:
	int size;
	std::vector<std::vector<int>> matrix;
	bool ischar, directed;
	Graph(int k, bool ch = false, bool d = true) : size(k), matrix(k, std::vector<int>(k, 0)), ischar(ch), directed(d)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (i == j)
					matrix[i][i] = 0;
				else
					matrix[i][j] = INF;
			}
		}
	}
	void addEdge(int src, int dest, int weight = 1)
	{
		--src;
		--dest;
		matrix[src][dest] = weight;
		if (!directed)
			matrix[dest][src] = weight;
	}
	void addEdge(char s, char d, int weight = 1)
	{
		int src = s - 'a';
		int dest = d - 'a';

		matrix[src][dest] = weight;
		if (!directed)
			matrix[dest][src] = weight;
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << "\t";
			if (ischar)
				std::cout << char(i + 'a');
			else
				std::cout << i + 1;
		}
		std::cout << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
				std::cout << char(i + 'a') << "\t";
			else std::cout << i + 1 << "\t";
			for (int j = 0; j < size; ++j)
			{
				if (matrix[i][j] == INF)
					std::cout << "INF\t";
				else
					std::cout << matrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	int FloydWarshall()
	{
		std::vector<std::vector<int>> D(size, std::vector<int>(size));
		std::vector<std::vector<int>> pi(size, std::vector<int>(size));

		//SETUP
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				D[i][j] = matrix[i][j];
				if (i != j && matrix[i][j] < INF)
				{
					pi[i][j] = i + 1;
				}
				else
					pi[i][j] = 0;
			}
		}
		std::cout << "================== K: " << 0 << " ==================" << std::endl << std::endl;
		printMatrix<>(D, "D", -1, ischar);
		printMatrix<>(pi, "Pi", -1, ischar, ischar);
		//F-W
		for (int k = 0; k < size; ++k)
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					if (D[i][j] > (D[i][k] + D[k][j]))
					{
						D[i][j] = D[i][k] + D[k][j];
						pi[i][j] = pi[k][j];
						if (i == j && D[i][i] < 0)
						{
							if (ischar)
								std::cout << "Neg cycle with node: " << char(i + 'a') << std::endl;
							else
								std::cout << "Neg cycle with node: " << i + 1 << std::endl;
							return i;
						}
					}
				}
			}
			std::cout << "================== K: " << k + 1 << " ==================" << std::endl << std::endl;
			printMatrix<>(D, "D", k, ischar);
			printMatrix<>(pi, "Pi", k, ischar, ischar);
			std::cout << std::endl;
		}
		std::cout << "============= FINISH RESULT ==============" << std::endl << std::endl;
		printMatrix<>(D, "D", -2, ischar);
		printMatrix<>(pi, "Pi", -2, ischar, ischar);

		return -1;
	}
};



int FloydMarshall(std::vector<std::vector<int>> A)
{
	int n = A.size();
	std::vector<std::vector<int>> D(n, std::vector<int>(n));
	std::vector<std::vector<int>> pi(n, std::vector<int>(n));

	//SETUP
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			D[i][j] = A[i][j];
			if (i != j && A[i][j] < INF)
			{
				pi[i][j] = i + 1;
			}
			else
				pi[i][j] = 0;
		}
	}
	std::cout << "================== K: " << 0 << " ==================" << std::endl << std::endl;
	printMatrix<>(D, "D", -1);
	printMatrix<>(pi, "Pi", -1);
	//F-W
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (D[i][j] > (D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					pi[i][j] = pi[k][j];
					if (i == j && D[i][i] < 0)
					{
						std::cout << "Neg cycle with node: " << i + 1 << std::endl;
						return i;
					}
				}
			}
		}
		std::cout << "================== K: " << k + 1 << " ==================" << std::endl << std::endl;
		printMatrix<>(D, "D", k);
		printMatrix<>(pi, "Pi", k);
		std::cout << std::endl;
	}
	std::cout << "============= FINISH RESULT ==============" << std::endl << std::endl;
	printMatrix<>(D, "D");
	printMatrix<>(pi, "Pi");

	return -1;
}


int main()
{										   // a    b     c   d
	//std::vector<std::vector<int>> graph = { { 0,   1,   INF, 3  }, //a
	//										{ INF, 0,   INF, 1  }, //b
	//										{ 1,   2,   0,   INF}, //c
	//										{ INF, INF, 2,   0}    //d
	//};

		//int res = FloydMarshall(graph);
	// std::cout << res << std::endl;


	Graph g(4,true);

	g.addEdge('a', 'b', 2);
	g.addEdge('a', 'd', 5);
	g.addEdge('b', 'c', 1);
	g.addEdge('c', 'a', 3);
	g.addEdge('c', 'd', 1);
	g.addEdge('d', 'b', 2);

	g.print();
	std::cout << std::endl;
	g.FloydWarshall();


}