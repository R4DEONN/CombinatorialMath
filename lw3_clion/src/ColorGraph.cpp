#include "ColorGraph.h"
#include <queue>
#include <map>


void ColorGraph::FillVertex(int vertex, int color)
{
	m_colors[vertex] = color;
}

void ColorGraph::PrintColors(std::ostream& output)
{
    for (const auto& pair : m_colors)
    {
        output << pair.first << ": " << pair.second << std::endl;
    }
}

int ColorGraph::GetMinUncolorVertex()
{
    int minVertex = INT_MAX;

    for (const auto& pair : m_adjacencies)
    {
        auto vertex = pair.first;

        if (m_colors.find(vertex) == m_colors.end() && minVertex > vertex)
        {
            minVertex = vertex;
        }
    }

    return minVertex;
}

size_t ColorGraph::GetColorVertexCount()
{
    return m_colors.size();
}

int ColorGraph::GetVertexFromTwoNeighborhood(int vertex)
{
    std::queue<int> queue;

    std::map<int, int> visited;
    std::map<int, int> distances;

    visited[vertex] = 1;
    distances[vertex] = 0;
    queue.push(vertex);

    while (!queue.empty())
    {
        auto currentVertex = queue.front();
        queue.pop();

        for (int to : m_adjacencies[currentVertex])
        {
            if (!visited[to])
            {
                visited[to] = 1;
                distances[to] = distances[currentVertex] + 1;

                if (distances[to] == 2)
                {
                    return to;
                }

                queue.push(to);
            }
        }
    }

    return -1;
}

int ColorGraph::GetCurrentColor()
{
    return m_currentColor++;
}

size_t ColorGraph::GetColorsCount()
{
    return m_currentColor;
}

std::map<int, int> ColorGraph::GetColors() const
{
	return m_colors;
}
