#include "Engine/Primitives/Grid.hpp"
#include <vector>

void phyto::engine::primitives::Grid::uploadPoints()
{
	std::vector<float> points;
	std::vector<GLuint> indices;

	points.reserve((m_width * m_height + m_width + m_height + 1) * 3);
	indices.reserve(m_width * m_height * 6);
	float topLeftX = m_bounds[0].x;
	float topLeftY = m_bounds[0].y;
	float gridWidth = m_bounds[1].x - m_bounds[0].x;
	float gridHeight = m_bounds[1].y - m_bounds[0].y;
	for (size_t i = 0; i < m_width + 1; ++i)
	{
		for (size_t j = 0; j < m_height + 1; ++j)
		{
			// create point
			points.push_back(topLeftX);
			points.push_back(topLeftY);
			points.push_back(0);
			topLeftY += gridHeight / (float)m_height;
		}
		topLeftX += gridWidth / (float)m_width;
	}

	for (size_t i = 0; i < m_width; ++i)
	{
		for (size_t j = 0; j < m_height; ++j)
		{
			// create indices for a square (2 triangles)
		}
	}
}

phyto::engine::primitives::Grid::Grid(size_t width, size_t height, std::array<glm::vec3, 2> bounds)
    : m_width{width}, m_height{height}, m_bounds{bounds}
{
	uploadPoints();
}
