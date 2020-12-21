#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

#define INF std::numeric_limits<int>::max()

struct Node
{
	Node* next;
	int v;
	int weight;
};

class Graph
{
public:
	int size;
	std::vector<Node*> adj;
	bool ischar;
	Graph(int k, bool ch) : size(k), ischar(ch), adj(k, nullptr) {	}
	void addEdge(int src, int dest, int weight)
	{
		--src;
		--dest;
		Node* pre = nullptr;
		Node* it = adj[src];
		while (it && it->v < dest)
		{
			pre = it;
			it = it->next;
		}
		Node* newnode = new Node();
		newnode->next = it;
		if (pre)
			pre->next = newnode;
		else
			adj[src] = newnode;
		newnode->v = dest;
		newnode->weight = weight;
	}
	void addEdge(char s, char d, int weight)
	{
		int src = s - 'a';
		int dest = d - 'a';

		Node* pre = nullptr;
		Node* it = adj[src];
		while (it && it->v < dest)
		{
			pre = it;
			it = it->next;
		}
		Node* newnode = new Node();
		newnode->next = it;
		if (pre)
			pre->next = newnode;
		else
			adj[src] = newnode;
		newnode->v = dest;
		newnode->weight = weight;
	}
	void print()
	{
		if (ischar)
		{
			for (int i = 0; i < adj.size(); ++i)
			{
				std::cout << char(i + 'a') << " --> ";
				Node* it = adj[i];
				while (it)
				{
					std::cout << "(" << char(it->v + 'a') << " , " << it->weight << ") ";
					if (it->next)
						std::cout << "; ";
					it = it->next;
				}
				std::cout << std::endl;
			}
		}
		else
		{
			for (int i = 0; i < adj.size(); ++i)
			{
				std::cout << i + 1 << " --> ";
				Node* it = adj[i];
				while (it)
				{
					std::cout << "(" << it->v + 1 << " , " << it->weight << ") ";
					if (it->next)
						std::cout << "; ";
					it = it->next;
				}
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	void Prim(int r)
	{
		--r;
		std::vector<int> c(size, INF);
		std::vector<int> pi(size, -1);
		c[r] = 0;

		std::vector<std::pair<int, int>> queue;
		for (int i = 0; i < size; ++i)
		{
			if (i != r)
				queue.push_back(std::make_pair(i, c[i]));
		}


		int u = r;

		//for (int i = 0; i < size; ++i)
		//{
		//	std::cout << "c[" << i + 1 << "]\tPi[" << i + 1 << "]\t";
		//}
		std::cout << std::endl;
		auto tmp = queue.end();
		while (!queue.empty())
		{
			if (tmp != queue.end())
				queue.erase(tmp);
			std::cout << std::endl << "Kiterjesztett csucs: ";
			if (ischar)
				std::cout << char(u + 'a');
			else
				std::cout << u + 1;
			auto p = adj[u];
			int counter = 0;
			std::cout << std::endl << "Sor tartalma: <";
			for (int i = 0; i < queue.size(); ++i)
			{
				if (i != 0) std::cout << ", ";
				if (ischar)
					std::cout << char(queue[i].first + 'a');
				else
					std::cout << queue[i].first + 1;
			}
			std::cout << ">" << std::endl;
			while (p)
			{
				auto it = std::find_if(queue.begin(), queue.end(), [&](std::pair<int, int>& pair) { return p->v == pair.first; });
				if (it != queue.end())
				{

					if (c[p->v] > p->weight)
					{
						c[p->v] = p->weight;
						pi[p->v] = u;
						(*it).second = c[p->v];
					}
				}
				p = p->next;
			}
			for (int i = 0; i < size; ++i)
			{
				if (ischar)
				{
					if (c[i] == INF)
						std::cout << "c[" << char(i + 'a') << "]= INF\t";
					else
						std::cout << "c[" << char(i + 'a') << "]= " << c[i] << "\t\t";
				}
				else
				{
					if (c[i] == INF)
						std::cout << "c[" << i + 1 << "]= INF" << "\t";
					else
						std::cout << "c[" << i + 1 << "]= " << c[i] << "\t\t";
				}
			}
			std::cout << std::endl;
			for (int i = 0; i < size; ++i)
			{
				if (ischar)
				{
					if (pi[i] == -1)
						std::cout << "pi[" << char(i + 'a') << "]= 0\t";
					else
						std::cout << "pi[" << char(i + 'a') << "]= " << char(pi[i] + 'a') << "\t";
				}
				else
					std::cout << "pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
			}
			std::cout << std::endl;


			tmp = std::min_element(queue.begin(), queue.end(), [&](auto pair1, auto pair2) { return pair1.second < pair2.second; });
			if (tmp != queue.end())
				u = (*tmp).first;
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl << "Eredmeny: " << std::endl << "Csucsok c ertekei:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
			{
				if (c[i] == INF)
					std::cout << "c[" << char(i + 'a') << "]= INF\t";
				else
					std::cout << "c[" << char(i + 'a') << "]= " << c[i] << "\t\t";
			}
			else
			{
				if (c[i] == INF)
					std::cout << "c[" << i + 1 << "]= INF" << "\t";
				else
					std::cout << "c[" << i + 1 << "]= " << c[i] << "\t\t";
			}
		}
		std::cout << std::endl << std::endl << "Csucsok Pi ertekei:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
				if (pi[i] == -1)
					std::cout << "pi[" << char(i + 'a') << "]= 0\t";
				else
					std::cout << "pi[" << char(i + 'a') << "]= " << char(pi[i] + 'a') << "\t";
			else
				std::cout << "pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
		}
		std::cout << std::endl;


	}
};
int main()
{
	Graph g(7, true);
	g.addEdge('a', 'b', 2);
	g.addEdge('a', 'c', 1);
	g.addEdge('a', 'd', 5);
	g.addEdge('b', 'a', 2);
	g.addEdge('b', 'd', 0);
	g.addEdge('b', 'e', 3);
	g.addEdge('c', 'a', 1);
	g.addEdge('c', 'd', 3);
	g.addEdge('d', 'a', 5);
	g.addEdge('d', 'c', 3);
	g.addEdge('d', 'e', 2);
	g.addEdge('d', 'g', 5);
	g.addEdge('d', 'f', 1);
	g.addEdge('e', 'b', 3);
	g.addEdge('e', 'd', 2);
	g.addEdge('e', 'g', 2);
	g.addEdge('f', 'd', 1);
	g.addEdge('f', 'g', 4);
	g.addEdge('g', 'd', 5);
	g.addEdge('g', 'f', 4);
	g.addEdge('g', 'e', 2);


	g.print();
	g.Prim(1);
}