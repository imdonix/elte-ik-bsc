#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <string>
#include <map>


#define INF std::numeric_limits<int>::max()

template<typename T, typename Container = std::deque<T> >
class iterable_queue : public std::queue<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }


};


class Graph
{
public:
	std::vector<std::list<std::pair<int, int>>>  adj;
	int size;
	bool ischar;

	Graph(int k, bool ch = false)
	{
		ischar = ch;
		size = k;
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
	int FindNegCycle(int v, const std::vector<int>& pi)
	{
		bool* B = new bool[size];
		for (int i = 0; i < size; ++i)
			B[i] = false;
		B[v] = true;
		int u = pi[v];
		while (!B[u])
		{
			B[u] = true;
			u = pi[u];
		}
		return u;
	}
	void BellmanFord(int s)
	{
		int res = QBasedBellmanFord(s);
		if (res != -1)
		{
			std::cout << "Negative cycle found: " << res << std::endl;
		}
	}
	void BellmanFord(char s)
	{
		int res = QBasedBellmanFord(s - 'a');
		if (res != -1)
		{
			std::cout << "Negative cycle found: " << char(res + 'a') << std::endl;
		}
	}
	int QBasedBellmanFord(int s)
	{
		std::vector<int> d(size, INF);
		std::vector<int> Pi(size, -1);
		std::vector<int> E(size, 0);
		bool* InQ = new bool[size];
		for (int i = 0; i < size; ++i)
			InQ[i] = false;


		d[s] = 0;
		E[s] = 0;
		iterable_queue<int> Q;
		Q.push(s);
		Q.push(std::numeric_limits<int>::min());
		InQ[s] = true;
		int menet = 0;
		while (!Q.empty())
		{
			

			int u = Q.front();
			Q.pop();
			if (u == std::numeric_limits<int>::min())
				Q.push(std::numeric_limits<int>::min());
			while (!Q.empty() && u == std::numeric_limits<int>::min())
			{
				u = Q.front();
				Q.pop();
				++menet;
			}
			
			if (u == std::numeric_limits<int>::min())
				break;
			std::cout << std::endl << std::endl << menet << ". Menet" << std::endl;
			InQ[u] = false;



			auto it = adj[u].begin();
			for (; it != adj[u].end(); ++it)
			{
				if (d[(*it).first] > (d[u] + (*it).second))
				{
					d[(*it).first] = d[u] + (*it).second;
					Pi[(*it).first] = u;
					E[(*it).first] = E[u] + 1;

					if (E[(*it).first] < size)
					{
						if (!InQ[(*it).first])
						{
							Q.push((*it).first);
							InQ[(*it).first] = true;
						}
					}
					else
					{
						return FindNegCycle((*it).first, Pi);
					}
				}
			}

			for (int i = 0; i < size; ++i)
			{
				if (ischar)
				{
					std::cout << "pi[" << char(i + 'a') << "]= ";
					if (Pi[i] == -1)
						std::cout << '0' << "\t";
					else
						std::cout << char(Pi[i] + 'a') << "\t";
				}
				else
					std::cout << "pi[" << i + 1 << "]= " << Pi[i] + 1 << "\t";
			}
			std::cout << std::endl;

			for (int i = 0; i < size; ++i)
			{
				if (ischar)
				{
					std::cout << "d[" << char(i + 'a') << "]= ";
					if (d[i] == INF)
						std::cout << "INF\t\t";
					else std::cout << d[i] << "\t\t";
				}
				else
				{
					std::cout << "d[" << i + 1 << "]= ";
					if (d[i] == INF)
						std::cout << "INF\t\t";
					else std::cout << d[i] << "\t\t";
				}
			}
			std::cout << std::endl;

			for (int i = 0; i < size; ++i)
			{
				if (ischar)
					std::cout << "e[" << char(i + 'a') << "]= " << E[i] << "\t\t";
				else
					std::cout << "e[" << i + 1 << "]=" << E[i] << "\t\t";
			}
			if (ischar)
				std::cout << std::endl << "Kiterjesztett csucs/d/e:    " << char(u + 'a') << " : " << d[u] << "/ " << E[u] << std::endl;
			else
				std::cout << std::endl << "Kiterjesztett csucs/d/e:    " << u + 1 << " : " << d[u] << "/ " << E[u] << std::endl;

			std::cout << "Sor tartalma : <";
			int count = 0;
			for (auto queueit = Q.begin(); queueit != Q.end(); ++queueit)
			{
				if (*queueit != std::numeric_limits<int>::min())
				{
					if (count != 0)
					{
						std::cout << " , ";
					}
					++count;
					//std::cout << (ischar ? char(*queueit + 'a') : char(*queueit));
					if (ischar)
						std::cout << char(*queueit + 'a');
					else
						std::cout << *queueit + 1;
				}
			}
			std::cout << ">" << std::endl;
		}

		std::cout << std::endl << std::endl << "Eredmeny:" << std::endl;
		for (int i = 0; i < size; ++i)
		{
			if (ischar)
			{
				std::cout << "pi[" << char(i + 'a') << "]= ";
				if (Pi[i] == -1)
					std::cout << '0' << "\t";
				else
					std::cout << char(Pi[i] +'a') << "\t";
			}
			else
				std::cout << "pi[" << i + 1 << "]= " << Pi[i] + 1 << "\t";
		}
		std::cout << std::endl;

		for (int i = 0; i < size; ++i)
		{
			if (ischar)
			{
				std::cout << "d[" << char(i + 'a') << "]= ";
				if (d[i] == INF)
					std::cout << "INF\t\t";
				else std::cout << d[i] << "\t\t";
			}
			else
			{
				std::cout << "d[" << i + 1 << "]= ";
				if (d[i] == INF)
					std::cout << "INF\t\t";
				else std::cout << d[i] << "\t\t";
				//std::cout << "d[" << i + 1 << "]=" << d[i] << "\t\t";
			}
		}
		std::cout << std::endl;

		for (int i = 0; i < size; ++i)
		{
			if (ischar)
				std::cout << "e[" << char(i + 'a') << "]= " << E[i] << "\t\t";
			else
				std::cout << "e[" << i + 1 << "]=" << E[i] << "\t\t";
		}
		std::cout << std::endl;
		return -1;
	}

};

int main()
{
	Graph g(7, true);
	g.addEdge('a', 'b', 2);
	g.addEdge('b', 'e', 0);
	g.addEdge('e', 'g', 3);
	g.addEdge('a', 'c', 4);
	g.addEdge('c', 'b', 2);
	g.addEdge('b', 'd', -1);
	g.addEdge('d', 'e', 2);
	g.addEdge('e', 'f', 1);
	g.addEdge('f', 'g', -2);
	g.addEdge('d', 'c', 1);
	g.addEdge('d', 'f', 3);


	g.print();
	g.BellmanFord('a');
	return 0;
}
