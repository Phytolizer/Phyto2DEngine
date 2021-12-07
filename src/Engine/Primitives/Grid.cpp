#include "Engine/Primitives/Grid.hpp"
#include "Engine/Internal/graphics.hpp"
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

	for (GLuint i = 0; i < m_width; ++i)
	{
		for (GLuint j = 0; j < m_height; ++j)
		{
			// create indices for a square (2 triangles)
			GLuint tl = j + i * (m_height + 1);
			GLuint bl = tl + 1;
			GLuint tr = bl + m_height;
			GLuint br = tr + 1;

			indices.push_back(tl);
			indices.push_back(bl);
			indices.push_back(br);
			indices.push_back(tl);
			indices.push_back(br);
			indices.push_back(tr);
		}
	}

	m_vertices.loadData(points, GL_STATIC_DRAW);
	m_indices.loadData(indices, GL_STATIC_DRAW);
}

phyto::engine::primitives::Grid::Grid(size_t width, size_t height, std::array<glm::vec3, 2> bounds)
    : m_width{width}, m_height{height}, m_bounds{bounds}
{
	uploadPoints();
}

void phyto::engine::primitives::Grid::setPositionAttribute(int attr)
{
	glVertexAttribPointer(attr, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(attr);
}
void phyto::engine::primitives::Grid::setColorAttribute(int attr)
{
}
void phyto::engine::primitives::Grid::draw()
{
	glDrawElements(GL_TRIANGLES, m_width * m_height * 4, GL_UNSIGNED_INT, nullptr);
}
