#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <stack>
#include <string>
#include <map>

#define INF std::numeric_limits<int>::max()

template<typename T, typename Container = std::deque<T>>
class iterable_stack
	: public std::stack<T, Container>
{
	using std::stack<T, Container>::c;

public:

	// expose just the iterators of the underlying container
	auto begin() { return std::begin(c); }
	auto end() { return std::end(c); }

	auto begin() const { return std::begin(c); }
	auto end() const { return std::end(c); }
	auto rbegin() const { return std::rbegin(c); }
	auto rend() const { return std::rend(c); }
};

enum class Colors
{
	WHITE,
	GREY,
	BLACK
};
class Graph
{
public:
	std::vector<std::list<std::pair<int, int>>>  adj;
	int size;
	bool ischar;
	Graph(int k, bool ch = false)
	{
		size = k;
		ischar = ch;
		adj = *new std::vector<std::list<std::pair<int, int>>>(size, std::list<std::pair<int, int>>());
	}
	void addEdge(int src, int dest, int weight)
	{
		--src;
		--dest;
		auto it = adj[src].begin();
		while (it != adj[src].end() && (*it).first < dest)
			++it;
		adj[src].insert(it, std::make_pair(dest, weight));
	}
	void addEdge(char src, char dest, int weight)
	{
		if (!ischar)
		{
			std::cout << "Construct graph with ischar parameter true!!!.. Returning" << std::endl;
			//return;
		}
		int s = src - 'a';
		int d = dest - 'a';

		auto it = adj[s].begin();
		while (it != adj[s].end() && (*it).first < d)
			++it;
		adj[s].insert(it, std::make_pair(d, weight));
	}
	void print()
	{
		if (ischar)
		{
			for (int i = 0; i < size; ++i)
			{
				std::cout << char(i + 'a') << " --> ";
				for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
					std::cout << "(" << char((*it).first + 'a') << ", " << (*it).second << "); ";
				std::cout << std::endl;
			}
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				std::cout << i + 1 << " --> ";
				for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
					std::cout << "(" << (*it).first + 1 << ", " << (*it).second << "); ";
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	void DFSVisit(int u, int& dcg, iterable_stack<int>& stack, std::vector<Colors>& color, std::vector<int>& pi, std::vector<int>& d, std::vector<int>& f, int& time, bool ischar)
	{
		color[u] = Colors::GREY;
		d[u] = ++time;

		auto it = adj[u].begin();
		while (it != adj[u].end() && dcg == -1)
		{
			int v = (*it).first;
			if (color[v] == Colors::WHITE)
			{
				pi[v] = u;
				DFSVisit(v, dcg, stack, color, pi, d, f, time, ischar);
			}
			else if (color[v] == Colors::GREY)
			{
				pi[v] = u;
				dcg = v;
			}
			++it;
		}
		f[u] = ++time;
		color[u] = Colors::BLACK;
		stack.push(u);
	}

	void DAGshP(iterable_stack<int>& stack)
	{
		std::vector<int> d(size, INF);
		std::vector<int> pi(size, -1);

		int s = stack.top();
		stack.pop();
		d[s] = 0;
		int u = s;

		while (!stack.empty())
		{
			if (ischar)
				std::cout << std::endl << std::endl << "Kiterjesztett csucs / d ertek: " << char(u + 'a') << " / " << (d[u] == INF ? "INF" : std::to_string(d[u])) << std::endl;
			else
				std::cout << std::endl << std::endl << "Kiterjesztett csucs / d ertek: " << u + 1 << " / " << (d[u] == INF ? "INF" : std::to_string(d[u])) << std::endl;

			auto it = adj[u].begin();
			while (it != adj[u].end())
			{
				if (d[(*it).first] > (d[u] + (*it).second))
				{

					pi[(*it).first] = u;
					d[(*it).first] = d[u] + (*it).second;
				}
				++it;
			}


			if (ischar)
			{
				for (int i = 0; i < size; ++i)
				{

					std::cout << "d[" << char(i + 'a') << "]= " << (d[i] == INF ? "INF" : std::to_string(d[i])) << "\t";
					if (d[i] != INF)
						std::cout << "\t";
				}
				std::cout << std::endl;

				for (int i = 0; i < size; ++i)
				{
					std::cout << "pi[" << char(i + 'a') << "]= " << (pi[i] == -1 ? '0' : char(pi[i] + 'a')) << "\t";
				}
			}
			else
			{
				for (int i = 0; i < size; ++i)
				{
					std::cout << "d[" << i + 1 << "]= " << (d[i] == INF ? "INF" : std::to_string(d[i])) << "\t";
					if (d[i] != INF)
						std::cout << "\t";
				}
				std::cout << std::endl;

				for (int i = 0; i < size; ++i)
				{
					std::cout << "pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
				}
			}

			std::cout << std::endl;
			u = stack.top();
			stack.pop();
		}
		std::cout << std::endl << std::endl << "Eredmeny:" << std::endl;
		if (ischar)
		{
			for (int i = 0; i < size; ++i)
			{
				std::cout << "d[" << char(i + 'a') << "]= " << (d[i] == INF ? "INF" : std::to_string(d[i])) << "\t";
				if (d[i] != INF)
					std::cout << "\t";
			}
			std::cout << std::endl;

			for (int i = 0; i < size; ++i)
			{
				std::cout << "pi[" << char(i + 'a') << "]= " << (pi[i] == -1 ? '0' : char(pi[i] + 'a')) << "\t";
			}
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				std::cout << "d[" << i + 1 << "]= " << (d[i] == INF ? "INF" : std::to_string(d[i])) << "\t";
				if (d[i] != INF)
					std::cout << "\t";
			}
			std::cout << std::endl;

			for (int i = 0; i < size; ++i)
			{
				std::cout << "pi[" << i + 1 << "]= " << pi[i] + 1 << "\t";
			}
		}

		std::cout << std::endl;
	}

	void topologicalsort(int u, int& dcg, iterable_stack<int>& stack, std::vector<Colors>& color, std::vector<int>& pi, std::vector<int>& d, std::vector<int>& f, int& time, bool ischar)
	{
		for (int i = 0; i < color.size(); ++i)
		{
			color[i] = Colors::WHITE;
			pi[i] = -1;
		}
		time = 0;
		DFSVisit(u, dcg, stack, color, pi, d, f, time, ischar);
	}
	int DAGShortestPath(int s)
	{
		iterable_stack<int> stack;

		int dcg = -1;
		int time = 0;

		std::vector<Colors> colors(size, Colors::WHITE);
		std::vector<int> pi(size, -1);
		std::vector<int> d(size, 0);
		std::vector<int> f(size, 0);

		topologicalsort(s, dcg, stack, colors, pi, d, f, time, true);
		std::cout << "Topological sort: < ";
		for (auto it = stack.rbegin(); it != stack.rend(); ++it)
		{
			if (it != stack.rbegin())
				std::cout << ", ";
			if (ischar)
				std::cout << char(*it + 'a');
			else std::cout << *it + 1;
		}
		std::cout << " >" << std::endl << std::endl;

		if (dcg == -1)
		{
			DAGshP(stack);
		}
		return dcg;
	}
};

int main()
{
	Graph g(7, true);
	g.addEdge('a', 'b', 3);
	g.addEdge('b', 'c', 4);
	g.addEdge('a', 'd', 1);
	g.addEdge('a', 'e', 4);
	g.addEdge('b', 'f', 3);
	g.addEdge('f', 'c', 1);
	g.addEdge('f', 'g', 1);
	g.addEdge('e', 'f', 2);
	g.addEdge('d', 'e', 1);
	g.addEdge('e', 'g', 4);

	g.print();
	g.DAGShortestPath(0);
	//g.dfs();
}