#pragma once

#include "Engine/IndexBuffer.hpp"
#include "Engine/Internal/Graphics.hpp"
#include "Engine/Primitives/ColoredPoint.hpp"
#include "Engine/VertexBuffer.hpp"
#include <array>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Quad
{
	VertexBuffer m_vertices;
	// 2 triangles
	IndexBuffer m_indices;
	GLint m_positionAttr;
	GLint m_colorAttr;

	void load(std::array<GLfloat, 28> points);

  public:
	explicit Quad(std::array<ColoredPoint, 4> points);
	explicit Quad(std::array<GLfloat, 28> points);
	void setPositionAttribute(GLint attr);
	void setColorAttribute(GLint attr);
	void bind() const;
	void draw();
};
} // namespace phyto::engine::primitives
