#pragma once

#include "ColorGraph.h"

namespace Yershov
{
	void ColorGraphVertices(ColorGraph& graph);
	void PrintColors(std::ostream& output, Graph& graph, const ColorGraph& dualGraph);
}