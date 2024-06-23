#include "pch.h"
#include "CppUnitTest.h"
#include "../Knapsack/Knapsack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KnapsackTest
{
	TEST_CLASS(KnapsackTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			std::vector<size_t> costs = { 1, 4, 2 };
			std::vector<size_t> weights = { 5, 12, 6 };
			size_t maxWeight = 12;

			std::vector<size_t> actual = SolveKnapsackProblem(costs, weights, maxWeight);
			std::vector<size_t> expected = { 2 };

			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod2)
		{
			std::vector<size_t> costs = { 92, 57, 49, 68, 60, 43, 67, 84, 87, 72 };
			std::vector<size_t> weights = { 23, 31, 29, 44, 53, 38, 63, 85, 89, 82 };
			size_t maxWeight = 165;

			std::vector<size_t> actual = SolveKnapsackProblem(costs, weights, maxWeight);
			std::vector<size_t> expected = { 1, 2, 3, 4, 6 };

			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMethod3)
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

			std::vector<size_t> actual = SolveKnapsackProblem(costs, weights, maxWeight);
			std::vector<size_t> expected = { 1, 2, 4, 5, 6, 10, 11, 13, 16, 22, 23, 24 };

			Assert::IsTrue(actual == expected);
		}
	};
}
