#pragma once

#include "Engine/VertexBuffer.hpp"
#include "Engine/internal/graphics.hpp"
#include <array>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Triangle
{
	std::array<float, 9> m_vertices;

	VertexBuffer m_vb;
	int m_attr;

	void loadBuffer();

  public:
	explicit Triangle(std::array<glm::vec3, 3> vertices);
	explicit Triangle(std::array<float, 9> vertices);
	void setAttribute(int attr, size_t size, GLenum type, GLenum normalized, size_t stride, size_t offset);
	void bind() const;
};
} // namespace phyto::engine::primitives
