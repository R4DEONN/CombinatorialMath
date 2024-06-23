#pragma once
#define INF INT_MAX
#include <iostream>
#include <list>
#include <queue>

class Graph
{
	int countLeftVertexes, countRightVertexes;

	std::list<int>* adj;

	std::vector<int> pairU, pairV, dist;

public:
	Graph(int countLeftVertexes, int countRightVertexes);
	void AddEdge(int left, int right);

	bool BFS();

	bool DFS(int vertex);

	int Hopcroft();
};