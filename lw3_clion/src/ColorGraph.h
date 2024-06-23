#pragma once

#include "Graph.h"

class ColorGraph : public Graph
{
public:
	ColorGraph(const Graph& graph)
		: Graph(graph)
	{}

	void FillVertex(int vertex, int color);

	void PrintColors(std::ostream& output);

	int GetMinUncolorVertex();

	size_t GetColorVertexCount();

	int GetVertexFromTwoNeighborhood(int vertex);

	int GetCurrentColor();

	size_t GetColorsCount();

	std::map<int, int> GetColors() const;

private:
	std::map<int, int> m_colors;
	std::map<int, std::set<int>> vertexEdgeMap;
	int m_currentColor = 0;
};