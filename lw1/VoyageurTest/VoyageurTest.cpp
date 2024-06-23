#include "pch.h"
#include "CppUnitTest.h"
#include "../lw1/lw1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void BaseMainTest(
	std::vector<std::vector<size_t>> distances,
	std::vector<std::vector<size_t>> expenses,
	std::vector<size_t> expectedIndexes,
	size_t expectedTotalExpenses
) {
	AppointmentData appointmentData = FindBestAppointment(distances, expenses);

	Assert::IsTrue(appointmentData.indexes == expectedIndexes, L"Unexpected indexes");
	Assert::AreEqual(appointmentData.totalExpenses, expectedTotalExpenses);
}

struct Data
{
	Data(
		std::vector<std::vector<size_t>> distances,
		std::vector<std::vector<size_t>> expenses,
		std::vector<size_t> expectedIndexes,
		size_t expectedTotalExpenses
	) : distances(distances),
		expenses(expenses),
		expectedIndexes(expectedIndexes),
		expectedTotalExpenses(expectedTotalExpenses)
	{}

	std::vector<std::vector<size_t>> distances;
	std::vector<std::vector<size_t>> expenses;
	std::vector<size_t> expectedIndexes;
	size_t expectedTotalExpenses;
};

std::vector<Data> cases = {
	{
		{
			{0, 1, 6, 4},
			{1, 0, 9, 5},
			{6, 9, 0, 3},
			{4, 5, 3, 0},
		},
		{
			{0, 1, 6, 4},
			{1, 0, 9, 5},
			{6, 9, 0, 3},
			{4, 5, 3, 0},
		},
		{ 3, 2, 1, 4 },
		206
	},
	{
		{
			{0, 2, 3, 1},
			{2, 0, 1, 4},
			{3, 1, 0, 2},
			{1, 4, 2, 0},
		},
		{
			{0, 1, 2, 3},
			{1, 0, 4, 2},
			{2, 4, 0, 1},
			{3, 2, 1, 0},
		},
		{ 1, 3, 2, 4 },
		44
	},
		{
		{
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0},
		},
		{
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0},
		},
		{ 1, 2, 3, 4 },
		12
	},
	{
		{
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0},
		},
		{
			{0, 1, 2, 3},
			{1, 0, 4, 5},
			{2, 4, 0, 6},
			{3, 5, 6, 0},
		},
		{ 1, 2, 3, 4 },
		42
	},
		{
		{
			{0, 1, 1, 1},
			{1, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0},
		},
		{
			{0, 1, 2, 3},
			{1, 0, 4, 5},
			{2, 4, 0, 6},
			{3, 5, 6, 0},
		},
		{ 1, 2, 3, 4 },
		42
	},
};

namespace VoyageurTest
{
	TEST_CLASS(VoyageurTest)
	{
	public:
		TEST_METHOD(MainTest)
		{
			for (const auto& Case : cases)
			{
				BaseMainTest(
					Case.distances,
					Case.expenses,
					Case.expectedIndexes,
					Case.expectedTotalExpenses
				);
			}
		}

		TEST_METHOD(Graph10x10)
		{
			std::vector<std::vector<size_t>> distances = {
				{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
			};

			std::vector<std::vector<size_t>> expenses = {
				{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
			};

			AppointmentData appointmentData = FindBestAppointment(distances, expenses);

			std::vector<size_t> expectedIndexes = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			size_t expectedTotalExpenses = 90;

			Assert::IsTrue(appointmentData.indexes == expectedIndexes, L"Unexpected indexes");
			Assert::AreEqual(appointmentData.totalExpenses, expectedTotalExpenses);
		}

		TEST_METHOD(TestMethod3)
		{
			std::vector<std::vector<size_t>> distances = {
				{0, 10, 15, 15},
				{10, 0, 2, 50},
				{15, 2, 0, 20},
				{15, 50, 20, 0},

			};

			std::vector<std::vector<size_t>> expenses = {
				{0, 5, 20, 30},
				{5, 0, 10, 15},
				{20, 10, 0, 200},
				{30, 15, 200, 0},
			};

			AppointmentData appointmentData = FindBestAppointment(distances, expenses);

			std::vector<size_t> expectedIndexes = { 1, 3, 4, 2 };
			size_t expectedTotalExpenses = 3850;

			Assert::IsTrue(appointmentData.indexes == expectedIndexes, L"Unexpected indexes");
			Assert::AreEqual(appointmentData.totalExpenses, expectedTotalExpenses);
		}
	};
}
