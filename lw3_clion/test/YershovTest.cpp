#include "catch2/catch_test_macros.hpp"
#include "Graph.h"
#include "ColorGraph.h"
#include "Yershov.h"
#include "sstream"

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

Graph CreateSmallGraph()
{
	std::map<int, std::set<int>> adjacencies = {
		{ 0, {1}},
		{ 1, {0, 2}},
		{ 2, {0, 1, 3}},
		{ 3, {0, 2}},
	};

	std::vector<std::set<int>> faces = {
		{ 0, 1, 2 },
		{ 0, 2, 3 },
		{ 1, 2, 3, 4 },
	};

	Graph graph(
		adjacencies,
		faces
	);

	return graph;
}

Graph CreateVerySmallGraph()
{
	std::map<int, std::set<int>> adjacencies = {
		{ 0, {}},
	};

	std::vector<std::set<int>> faces = {
		{ 0 },
	};

	Graph graph(
		adjacencies,
		faces
	);

	return graph;
}

TEST_CASE("ConstructAndPrintGraph")
{
	auto graph = CreateGraph();

	std::stringstream output;
	graph.PrintGraph(output);

	std::string expected =
		"1: 2, 3, 6\n"
		"2: 1, 4, 5, 7\n"
		"3: 1, 4, 6\n"
		"4: 2, 3, 5, 6\n"
		"5: 2, 4, 6, 7, 9\n"
		"6: 1, 3, 4, 5, 9\n"
		"7: 2, 5, 9\n"
		"8: 9\n"
		"9: 5, 6, 7, 8\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("MergeTwoVertexes")
{
	auto graph = CreateGraph();

	graph.MergeVertexes(1, 4);

	std::stringstream output;
	graph.PrintGraph(output);

	std::string expected =
		"1: 2, 3, 5, 6\n"
		"2: 1, 5, 7\n"
		"3: 1, 6\n"
		"5: 1, 2, 6, 7, 9\n"
		"6: 1, 3, 5, 9\n"
		"7: 2, 5, 9\n"
		"8: 9\n"
		"9: 5, 6, 7, 8\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("ConstructAndPrintColorGraph")
{
	auto colorGraph = ColorGraph(CreateGraph());

	colorGraph.FillVertex(1, 0);
	colorGraph.FillVertex(2, 1);
	colorGraph.FillVertex(3, 1);
	colorGraph.FillVertex(4, 2);
	colorGraph.FillVertex(5, 0);
	colorGraph.FillVertex(6, 3);
	colorGraph.FillVertex(7, 2);
	colorGraph.FillVertex(8, 0);
	colorGraph.FillVertex(9, 1);

	std::stringstream output;
	colorGraph.PrintColors(output);

	std::string expected =
		"1: 0\n"
		"2: 1\n"
		"3: 1\n"
		"4: 2\n"
		"5: 0\n"
		"6: 3\n"
		"7: 2\n"
		"8: 0\n"
		"9: 1\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("ColorGraphVertices1")
{
	auto colorGraph = ColorGraph(CreateSmallGraph().GetDualGraph());

	Yershov::ColorGraphVertices(colorGraph);

	std::stringstream output;
	colorGraph.PrintColors(output);

	std::string expected =
		"0: 0\n"
		"1: 1\n"
		"2: 2\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("ColorGraphVertices2")
{
	auto colorGraph = ColorGraph(CreateGraph().GetDualGraph());

	Yershov::ColorGraphVertices(colorGraph);

	std::stringstream output;
	colorGraph.PrintColors(output);

	std::string expected =
		"0: 0\n"
		"1: 1\n"
		"2: 2\n"
		"3: 1\n"
		"4: 0\n"
		"5: 0\n"
		"6: 2\n"
		"7: 3\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("ColorGraphVertices3")
{
	auto colorGraph = ColorGraph(CreateVerySmallGraph().GetDualGraph());

	Yershov::ColorGraphVertices(colorGraph);

	std::stringstream output;
	colorGraph.PrintColors(output);

	std::string expected =
		"0: 0\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("ColorGraphVertices3WithFaces")
{
	auto graph = CreateVerySmallGraph();
	auto colorGraph = ColorGraph(graph.GetDualGraph());

	Yershov::ColorGraphVertices(colorGraph);

	std::stringstream output;
	Yershov::PrintColors(output, graph, colorGraph);

	std::string expected =
		"{0}: 0\n";

	REQUIRE(expected == output.str());
}

TEST_CASE("GetMinUncolorVertexAndTwoNeighborhoodVertex")
{
	auto colorGraph = ColorGraph(CreateGraph());

	auto firstVertex = colorGraph.GetMinUncolorVertex();
	REQUIRE(1 == firstVertex);

	auto secondVertex = colorGraph.GetVertexFromTwoNeighborhood(firstVertex);
	REQUIRE(4 == secondVertex);
}
