#include <iostream>
#include <vector>
#include "src/CountSpanningTrees.h"

int main() {
	std::vector<std::vector<int>> graph = {
		{0, 1, 0, 0},
		{1, 0, 1, 1},
		{0, 1, 0, 1},
		{0, 1, 1, 0}
	};

	int countSpanningTrees = CountSpanningTrees(graph);
	std::cout << "Count of spanning trees: " << countSpanningTrees << std::endl;

	return 0;
}