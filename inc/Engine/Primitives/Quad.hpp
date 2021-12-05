#pragma once

#include "Engine/IndexBuffer.hpp"
#include "Engine/VertexBuffer.hpp"
#include "Engine/internal/graphics.hpp"
#include <array>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Quad
{
	VertexBuffer m_vertices;
	// 2 triangles
	IndexBuffer m_indices;
	GLint m_attr;

	void load(std::array<GLfloat, 12> points);

  public:
	explicit Quad(std::array<glm::vec3, 4> points);
	explicit Quad(std::array<GLfloat, 12> points);
	void setPositionAttribute(GLint attr);
	void bind() const;
	void draw();
};
} // namespace phyto::engine::primitives
