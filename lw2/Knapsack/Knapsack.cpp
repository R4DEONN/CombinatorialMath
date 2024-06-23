#include <iostream>
#include <vector>

std::vector<size_t> SolveKnapsackProblem(
	const std::vector<size_t>& costs,
	const std::vector<size_t>& weights,
	size_t maxWeight
) {
	auto n = costs.size();
	size_t maxValue = 0;
	std::vector<size_t> bestSet;

	for (size_t i = 1; i < (1ui64 << n); i++)
	{
		size_t totalValue = 0;
		size_t totalWeight = 0;
		std::vector<size_t> currentSet;

		for (size_t j = 0; j < n; j++)
		{
			if (i & (1ui64 << j))
			{
				totalValue += costs[j];
				totalWeight += weights[j];
				currentSet.push_back(j + 1);
			}
		}

		if (totalValue > maxValue && totalWeight <= maxWeight)
		{
			maxValue = totalValue;
			bestSet = currentSet;
		}
	}

	return bestSet;
}

void PrintVector(const std::vector<size_t>& vector)
{
	std::cout << "{ ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i != vector.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

int main()
{
	std::vector<size_t> costs = {
			825594,
			1677009,
			1676628,
			1523970,
			943972,
			97426,
			69666,
			1296457,
			1679693,
			1902996,
			1844992,
			1049289,
			1252836,
			1319836,
			953277,
			2067538,
			675367,
			853655,
			1826027,
			65731,
			901489,
			577243,
			466257,
			369261
	};
	std::vector<size_t> weights = {
		382745,
		799601,
		909247,
		729069,
		467902,
		44328,
		34610,
		698150,
		823460,
		903959,
		853665,
		551830,
		610856,
		670702,
		488960,
		951111,
		323046,
		446298,
		931161,
		31385,
		496951,
		264724,
		224916,
		169684,
	};
	size_t maxWeight = 6404180;
	std::vector<size_t> itemIndexes = SolveKnapsackProblem(costs, weights, maxWeight);

	PrintVector(itemIndexes);

	return EXIT_SUCCESS;
}