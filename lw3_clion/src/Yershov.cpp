#include "Yershov.h"

namespace Yershov
{
	void ColorGraphVertices(ColorGraph& graph)
	{
		ColorGraph tmpGraph = graph;

		while (graph.GetColorVertexCount() != graph.GetVertexCount())
		{
			auto firstVertex = tmpGraph.GetMinUncolorVertex();
			auto color = graph.GetCurrentColor();
			graph.FillVertex(firstVertex, color);
			tmpGraph.FillVertex(firstVertex, color);

			int secondVertex = tmpGraph.GetVertexFromTwoNeighborhood(firstVertex);
			
			while (secondVertex != -1)
			{
				graph.FillVertex(secondVertex, color);
				tmpGraph.MergeVertexes(firstVertex, secondVertex);

				secondVertex = tmpGraph.GetVertexFromTwoNeighborhood(firstVertex);
			}
		}
	}

	void PrintColors(std::ostream& output, Graph& graph, const ColorGraph& dualGraph)
	{
		auto colors = dualGraph.GetColors();
		for (const auto& pair : colors)
		{
			output << graph.GetFaceVerticesString(pair.first) << ": " << pair.second << std::endl;
		}
	}
}