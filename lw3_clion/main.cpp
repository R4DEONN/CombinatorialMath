#include <iostream>
#include "src/Graph.h"
#include "src/ColorGraph.h"
#include "src/Yershov.h"

Graph CreateGraph()
{
	std::map<int, std::set<int>> adjacencies = {
		{ 1, { 2, 3, 6 }},
		{ 2, { 1, 4, 5, 7 }},
		{ 3, { 1, 4, 6 }},
		{ 4, { 3, 2, 5, 6 }},
		{ 5, { 4, 2, 6, 7, 9 }},
		{ 6, { 5, 4, 3, 1, 9 }},
		{ 7, { 5, 2, 9 }},
		{ 8, { 9 }},
		{ 9, { 5, 6, 7, 8 }}
	};

	std::vector<std::set<int>> faces = {
		{ 1, 2, 3, 4 },
		{ 1, 2, 3, 6, 7, 9 },
		{ 3, 4, 6 },
		{ 2, 4, 5 },
		{ 2, 5, 7 },
		{ 5, 6, 9 },
		{ 5, 7, 9 },
		{ 4, 5, 6 }
	};

	Graph graph(
		adjacencies,
		faces
	);

	return graph;
}

int main()
{
	auto graph = CreateGraph();
    auto colorGraph = ColorGraph(graph.GetDualGraph());

    Yershov::ColorGraphVertices(colorGraph);

    std::cout << "Vertexes colors: " << std::endl;
	Yershov::PrintColors(std::cout, graph, colorGraph);
    std::cout << std::endl;

    std::cout << "Colors count: " << colorGraph.GetColorsCount() << std::endl;
}