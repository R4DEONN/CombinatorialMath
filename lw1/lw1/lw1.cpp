#include <vector>
#include <algorithm>
#include <iostream>
#include <boost/timer.hpp>

struct AppointmentData
{
	std::vector<size_t> indexes;
	size_t totalExpenses;
};

size_t CountExpenses(
	const std::vector<std::vector<size_t>>& distances,
	const std::vector<std::vector<size_t>>& expenses,
	std::vector<size_t> indexes
) {
	size_t summary = 0;

	for (size_t i = 0; i < distances.size(); i++)
	{
		for (size_t j = 0; j < distances[i].size(); j++)
		{
			summary += distances[i][j] * expenses[indexes[i]][indexes[j]];
		}
	}

	return summary;
}

AppointmentData FindBestAppointment(
	const std::vector<std::vector<size_t>>& distances,
	const std::vector<std::vector<size_t>>& expenses
) {
	std::vector<size_t> indexes;
	for (size_t i = 0; i < distances.size(); i++)
	{
		indexes.push_back(i);
	}

	size_t totalExpenses = SIZE_MAX;
	std::vector<size_t> totalIndexes = indexes;

	do
	{
		size_t sum = CountExpenses(distances, expenses, indexes);
		if (sum < totalExpenses)
		{
			totalExpenses = sum;
			totalIndexes = indexes;
		}
	} while (std::next_permutation(indexes.begin(), indexes.end()));

	for (size_t i = 0; i < totalIndexes.size(); i++)
	{
		totalIndexes[i]++;
	}

	return AppointmentData{ totalIndexes, totalExpenses };
}

int main()
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

	boost::timer timer;
	timer.restart();

	AppointmentData appointmentData = FindBestAppointment(distances, expenses);

	double timeElapsed = timer.elapsed();

	std::wcout << appointmentData.totalExpenses << "\n";
	bool isFirst = true;
	for (size_t factory : appointmentData.indexes)
	{
		if (isFirst)
		{
			isFirst = false;
			std::cout << "{ " << factory;
		}
		else
		{
			std::cout << ", " << factory;
		}
	}

	std::cout << " }\n";

	std::cout << "Time elapsed: " << timeElapsed << '\n';
}