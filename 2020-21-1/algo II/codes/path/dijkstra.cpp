#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <algorithm>
#include <map>
#include <string>
typedef std::pair<int, int> iPair;

#define INF std::numeric_limits<int>::max()
// This class represents a directed graph using 
// adjacency list representation 
class Graph
{
	int size; // No. of vertices 
	bool ischar;
	// In a weighted graph, we need to store vertex 
	// and weight pair for every edge 
	std::vector<std::list<std::pair<int, int>>> adj;

public:
	Graph(int V, bool ch = false) : size(V), adj(V), ischar(ch) {}

	// function to add an edge to graph 
	void addEdge(int u, int v, int w)
	{
		--u;
		--v;
		auto it = adj[u].begin();
		while (it != adj[u].end() && (*it).first < v)
			++it;
		adj[u].insert(it, std::make_pair(v, w));
	}
	void addEdge(char u, char v, int w)
	{
		if (!ischar)
		{
			std::cout << "Construct graph with ischar parameter true!!!.. Returning" << std::endl;
			return;
		}
		int s = u - 'a';
		int d = v - 'a';

		auto it = adj[s].begin();
		while (it != adj[s].end() && (*it).first < d)
			++it;
		adj[s].insert(it, std::make_pair(d, w));
	}
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
			{
				std::cout << char(i + 'a') << " --> ";
				for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
					std::cout << "(" << char((*it).first + 'a') << ", " << (*it).second << "); ";
				//std::cout << "(" << (ischar ? char((*it).first + 'a') : char((*it).first)) << ", " << (*it).second << "); ";
			}
			else
			{
				std::cout << i + 1 << " --> ";
				for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
					std::cout << "(" << (*it).first + 1 << ", " << (*it).second << "); ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void shortestPath(int s)
	{
		std::vector<std::pair<int, int>> minqueue;

		std::vector<int> d(size, INF);
		std::vector<int> pi(size, -1);



		for (int i = 0; i < size; ++i)
		{
			if (i != s)
				minqueue.push_back(std::make_pair(i, d[i]));
		}

		d[s] = 0;
		int u = s;
		int curweight = 0;
		while (d[u] < INF && minqueue.size() > 0)
		{
			std::cout << "Kiterjesztett csucs: " << (ischar ? char(u + 'a') : char(u + '1')) << " (weight: " << curweight << ")" << std::endl;
			auto it = adj[u].begin();
			for (; it != adj[u].end(); ++it)
			{
				if (d[(*it).first] > d[u] + (*it).second)
				{
					pi[(*it).first] = u;
					d[(*it).first] = d[u] + (*it).second;
					auto tmp = std::find_if(minqueue.begin(), minqueue.end(), [=](iPair pair) { return pair.first == (*it).first; });
					if (tmp != minqueue.end())
					{
						tmp->second = d[u] + (*it).second;
					}
				}
			}

			for (int i = 0; i < size; ++i)
			{
				if (ischar)
				{
					if (pi[i] == -1)
						std::cout << "Pi[" << char(i + 'a') << "]= 0\t";
					else
						std::cout << "Pi[" << char(i + 'a') << "]= " << char(pi[i] + 'a') << "\t";
				}
				else
				{
					if (pi[i] == -1)
						std::cout << "Pi[" << i + 1 << "]= 0\t";
					else
						std::cout << "Pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
					//std::cout << "Pi[" << i + 1 << "]= " << (ischar ? (pi[i] == -1 ? '0' : char(pi[i] + 'a')) : char(pi[i] + '1')) << "\t";
				}
			}
			std::cout << std::endl;
			for (int i = 0; i < size; ++i)
			{
				if (d[i] == INF)
				{
					if (ischar)
						std::cout << "d[" << char(i + 'a') << "]=INF\t";
					else
						std::cout << "d[" << i + 1 << "]=INF\t";
				}
				else
				{
					if (ischar)
						std::cout << "d[" << char(i + 'a') << "]= " << d[i];
					else
						std::cout << "d[" << i + 1 << "]= " << d[i];
					std::cout << "\t\t";
				}

			}
			std::cout << std::endl << std::endl << std::endl;

			auto tmp = std::min_element(minqueue.begin(), minqueue.end(), [&](auto pair1, auto pair2) { return pair1.second < pair2.second; });

			u = (*tmp).first;
			curweight = (*tmp).second;
			minqueue.erase(tmp);

		}
		std::cout << std::endl << std::endl;
		std::cout << std::endl << std::endl;
		std::cout << "Eredmeny:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
				std::cout << "Pi[" << char(i + 'a') << "]= " << (pi[i] == -1 ? '0' : char(pi[i] + 'a')) << "\t";
			else
			{
				if (pi[i] == -1)
					std::cout << "Pi[" << i + 1 << "]= " << '0' << "\t";
				else
					std::cout << "Pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
				std::cout << "d[" << char(i + 'a') << "]= " << d[i] << "\t\t";
			else
				std::cout << "d[" << i + 1 << "]= " << d[i] << "\t\t";
		}
		std::cout << std::endl;
		utkiir('a', 'b', pi);
	}
	void shortestPath(char s)
	{
		shortestPath(s - 'a');
	}
	void utkiir(char s, char d, const std::vector<int>& pi)
	{
		int src = s - 'a';
		int dest = d - 'a';
		utkiir(src, dest, pi);
	}
	void utkiir(int src, int dest, const std::vector<int>& pi)
	{
		if (src == dest)
		{
			if (ischar)
				std::cout << char(src + 'a') << " ";
			else
				std::cout << src + 1 << " ";
		}
		else if (pi[src] == 0)
		{
			std::cout << "Nincs ut" << std::endl;
		}
		else
		{
			utkiir(src, pi[dest], pi);
			if (ischar)
				std::cout << char(dest + 'a') << " ";
			else std::cout << dest + 1 << " ";
		}
	}
};

// Driver program to test methods of graph class 
int main()
{

	// create the graph given in above fugure 
	int V = 7;
	Graph g(V, true);

	g.addEdge('a', 'b', 1);
	g.addEdge('b', 'c', 3);
	g.addEdge('c', 'd', 2);
	g.addEdge('a', 'e', 3);
	g.addEdge('b', 'e', 1);
	g.addEdge('f', 'b', 2);
	g.addEdge('c', 'f', 6);
	g.addEdge('g', 'c', 1);
	g.addEdge('d', 'g', 1);
	g.addEdge('f', 'e', 2);
	g.addEdge('g', 'f', 1);
	g.print();


	g.shortestPath(0);

	return 0;
}
