#pragma once

#include "Engine/Internal/graphics.hpp"
#include "Engine/VertexBuffer.hpp"
#include <array>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Triangle
{
	std::array<float, 9> m_vertices;

	VertexBuffer m_vb;
	int m_positionAttr;
	int m_colorAttr;

	void loadBuffer();

  public:
	explicit Triangle(std::array<glm::vec3, 3> vertices);
	explicit Triangle(std::array<float, 9> vertices);
	void setPositionAttribute(int attr);
	void setColorAttribute(int attr);
	void bind() const;
	void draw();
};
} // namespace phyto::engine::primitives
