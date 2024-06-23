#include "catch2/catch_test_macros.hpp"
#include "../src/CountSpanningTrees.h"

TEST_CASE("CountSpanningTrees tests", "[CountSpanningTrees]")
{
	SECTION("Пустой граф (изолированные вершины)")
	{
		Matrix adjMatrix = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 0);
	}

	SECTION("Граф-дерево (линейный граф)")
	{
		Matrix adjMatrix = {
			{0, 1, 0},
			{1, 0, 1},
			{0, 1, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 1);
	}

	SECTION("Полный граф на 3 вершинах")
	{
		Matrix adjMatrix = {
			{0, 1, 1},
			{1, 0, 1},
			{1, 1, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 3);
	}

	SECTION("Полный граф на 4 вершинах")
	{
		Matrix adjMatrix = {
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 16);
	}

	SECTION("Граф с двумя компонентами связности")
	{
		Matrix adjMatrix = {
			{0, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 1},
			{0, 0, 1, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 0);
	}

	SECTION("Граф с двумя компонентами связности")
	{
		Matrix adjMatrix = {
			{0, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 1},
			{0, 0, 1, 0}
		};
		REQUIRE(CountSpanningTrees(adjMatrix) == 0);
	}
}