#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

class Graph
{

public:
	int size;
	std::vector<std::vector<int>> matrix;
	bool ischar;
	bool directed;
	Graph(int k, bool ch = false, bool d = true) : size(k), matrix(k, std::vector<int>(k, 0)), ischar(ch), directed(d)
	{
		for (int i = 0; i < size; ++i)
			matrix[i][i] = 1;
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
				std::cout << matrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	void warshall()
	{
		std::vector<std::vector<bool>> T(matrix.size(), std::vector<bool>(matrix.size()));

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				T[i][j] = matrix[i][j];
			}
			T[i][i] = 1;
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (ischar)
					std::cout << "T0[" << char(i + 'a') << "," << char(j + 'a') << "]=" << T[i][j] << "\t";
				else
					std::cout << "T0[" << i + 1 << "," << j + 1 << "]=" << T[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;



		for (int k = 0; k < size; ++k)
		{
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					T[i][j] = T[i][j] || (T[i][k] && T[k][j]);
					if (ischar)
						std::cout << "T" << k + 1 << "[" << char(i + 'a') << "," << char(j + 'a') << "]=" << T[i][j] << "\t";
					else
						std::cout << "T" << k + 1 << "[" << i + 1 << "," << j + 1 << "]=" << T[i][j] << "\t";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				std::cout << "T[" << char(i + 'a') << "," << char(j + 'a') << "]=" << T[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};
void warshall(std::vector<std::vector<int>> A)
{
	int size = A.size();
	std::vector<std::vector<bool>> T(A.size(), std::vector<bool>(A.size()));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			T[i][j] = A[i][j];
		}
		T[i][i] = 1;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << "T0[" << i + 1 << "," << j + 1 << "]=" << T[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;



	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				T[i][j] = T[i][j] || (T[i][k] && T[k][j]);
				std::cout << "T" << k + 1 << "[" << i + 1 << "," << j + 1 << "]=" << T[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << "T[" << i + 1 << "," << j + 1 << "]=" << T[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int main()
{
	//std::vector<std::vector<int>> graph =
	//{
	//	{0,1,0,0},
	//	{0,0,0,1},
	//	{0,1,0,0},
	//	{0,0,1,0}
	//};
	//warshall(graph);
	/*
	Mindkét módon használható az algoritmus.
	std::cout << std::boolalpha pedig true/falset fog kiírni, 0/1 helyett
	//std::cout << std::boolalpha;
	*/

	Graph g(4, true);
	g.addEdge('a', 'c');
	g.addEdge('b', 'a');
	g.addEdge('c', 'd');
	g.addEdge('d', 'b');
	//g.print();
	g.warshall();

	return 0;
}