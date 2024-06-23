#include "Hopcroft.h"

int Graph::Hopcroft()
{
	for (int i = 0; i <= countLeftVertexes; i++)
	{
		pairU.push_back(0);
		dist.push_back(0);
	}

	for (int i = 0; i <= countRightVertexes; i++)
	{
		pairV.push_back(0);
	}
	
	int result = 0;

	while (BFS())
	{
		for (int u = 1; u <= countLeftVertexes; u++)
		{
			if (pairU[u] == 0 && DFS(u))
			{
				result++;
			}
		}
	}
	return result;
}

bool Graph::BFS()
{
	std::queue<int> queue;

	for (int u = 1; u <= countLeftVertexes; u++)
	{
		if (pairU[u] == 0)
		{
			dist[u] = 0;
			queue.push(u);
		}
		else
		{
			dist[u] = INF;
		}
	}

	dist[0] = INF;

	while (!queue.empty())
	{
		int vertex = queue.front();
		queue.pop();

		if (dist[vertex] < dist[0])
		{
			std::list<int>::iterator i;
			for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
			{
				int v = *i;

				if (dist[pairV[v]] == INF)
				{
					dist[pairV[v]] = dist[vertex] + 1;
					queue.push(pairV[v]);
				}
			}
		}
	}

	return (dist[0] != INF);
}

bool Graph::DFS(int vertex)
{
	if (vertex != 0)
	{
		std::list<int>::iterator i;
		for (i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
		{
			int v = *i;

			if (dist[pairV[v]] == dist[vertex] + 1)
			{
				if (DFS(pairV[v]) == true)
				{
					pairV[v] = vertex;
					pairU[vertex] = v;
					return true;
				}
			}
		}

		dist[vertex] = INF;
		return false;
	}
	return true;
}

Graph::Graph(int countLeftVertexes, int countRightVertexes)
{
	this->countLeftVertexes = countLeftVertexes;
	this->countRightVertexes = countRightVertexes;
	adj = new std::list<int>[countLeftVertexes + 1];
}

void Graph::AddEdge(int left, int right)
{
	adj[left].push_back(right);
}
