#include <sstream>
#include "Graph.h"

Graph::Graph(const std::map<int, std::set<int>>& adjacencies, const std::vector<std::set<int>>& faces)
: m_adjacencies(adjacencies)
{
	for (int i = 0; i < faces.size(); i++)
	{
		m_faces[i] = faces[i];
	}
}

void Graph::PrintGraph(std::ostream& output)
{
    for (const auto& pair : m_adjacencies)
    {
        output << pair.first << ": ";
        auto isFirst = true;
        for (int v : pair.second)
        {
            if (!isFirst)
            {
                output << ", ";
            }
            else
            {
                isFirst = false;
            }
            output << v;
        }
        output << std::endl;
    }
}

size_t Graph::GetVertexCount()
{
    return m_adjacencies.size();
}

void Graph::MergeVertexes(int firstVertex, int secondVertex)
{
    for (std::set<int>::iterator p = m_adjacencies[secondVertex].begin(); p != m_adjacencies[secondVertex].end(); ++p)
    {
        m_adjacencies[firstVertex].insert(*p);
    }
    m_adjacencies.erase(secondVertex);

    for (auto& pair : m_adjacencies)
    {
        if (pair.second.count(secondVertex) == 1)
        {
            pair.second.insert(firstVertex);
            pair.second.erase(secondVertex);
        }
    }
}

Graph Graph::GetDualGraph()
{
	std::map<int, std::set<int>> adjacencies;

	if (m_faces.size() == 1)
	{
		adjacencies[0].insert({});
		return Graph{adjacencies};
	}

	for (int i = 0; i < m_faces.size() - 1; i++)
	{
		for (int j = i + 1; j < m_faces.size(); j++)
		{
			if (AreFacesAdjacent(m_faces[i], m_faces[j]))
			{
				adjacencies[i].insert(j);
				adjacencies[j].insert(i);
			}
		}
	}

	return Graph{adjacencies};
}

bool Graph::AreFacesAdjacent(const std::set<int>& firstFace, const std::set<int>& secondFace)
{
	for (auto firstVertex : firstFace)
	{
		if (secondFace.contains(firstVertex))
		{
			for (auto secondVertex : firstFace)
			{
				if (secondVertex == firstVertex)
				{
					continue;
				}

				if (secondFace.contains(secondVertex))
				{
					return true;
				}
			}
		}
	}

	return false;
}

Graph::Graph(const std::map<int, std::set<int>>& adjacencies)
: m_adjacencies(adjacencies)
{

}

std::string Graph::GetFaceVerticesString(int faceKey)
{
	std::stringstream faceVertices;
	faceVertices << "{";
	bool isFirst = true;
	for (const auto& face : m_faces[faceKey])
	{
		if (!isFirst)
		{
			faceVertices << ", ";
		}
		isFirst = false;
		faceVertices << face;
	}

	faceVertices << "}";

	return faceVertices.str();
}
