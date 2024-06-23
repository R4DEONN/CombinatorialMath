#include "catch2/catch_test_macros.hpp"
#include "../src/Hopcroft.h"

TEST_CASE("Some test")
{
	Graph graph(4, 4);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	graph.AddEdge(2, 1);
	graph.AddEdge(3, 2);
	graph.AddEdge(4, 2);
	graph.AddEdge(4, 4);

	REQUIRE(graph.Hopcroft() == 4);
}

TEST_CASE("Some test 2")
{
	Graph graph(5, 5);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 4);
	graph.AddEdge(2, 1);
	graph.AddEdge(3, 2);
	graph.AddEdge(2, 5);
	graph.AddEdge(1, 3);

	REQUIRE(graph.Hopcroft() == 3);
}