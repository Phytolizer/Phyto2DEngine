#pragma once

#include "Engine/IndexBuffer.hpp"
#include "Engine/VertexBuffer.hpp"
#include <array>
#include <cstddef>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Grid
{
	size_t m_width;
	size_t m_height;
	std::array<glm::vec3, 2> m_bounds;
	VertexBuffer m_vertices;
	IndexBuffer m_indices;

	void uploadPoints();

  public:
	Grid(size_t width, size_t height, std::array<glm::vec3, 2> bounds);
	void setPositionAttribute(int attr);
	void setColorAttribute(int attr);
	void draw();
};
} // namespace phyto::engine::primitives
