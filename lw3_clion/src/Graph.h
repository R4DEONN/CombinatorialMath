#pragma once

#include <iostream>
#include <set>
#include <map>
#include <vector>

class Graph
{
public:
	explicit Graph(
		const std::map<int, std::set<int>>& adjacencies
	);
	Graph(
		const std::map<int, std::set<int>>& adjacencies,
		const std::vector<std::set<int>>& faces
	);

	void PrintGraph(std::ostream& output);

	size_t GetVertexCount();

	void MergeVertexes(int firstVertex, int secondVertex);

	Graph GetDualGraph();

	bool AreFacesAdjacent(const std::set<int>& firstFace, const std::set<int>& secondFace);

	std::string GetFaceVerticesString(int faceKey);

protected:
	std::map<int, std::set<int>> m_adjacencies;
	std::map<int, std::set<int>> m_faces;
};