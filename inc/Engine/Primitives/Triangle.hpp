#pragma once

#include "Engine/internal/graphics.hpp"
#include <array>
#include <glm/vec3.hpp>

namespace phyto::engine::primitives
{
class Triangle
{
	std::array<glm::vec3, 3> m_vertices;

	GLuint m_vbo;

  public:
	explicit Triangle(std::array<glm::vec3, 3> vertices);
};
} // namespace phyto::engine::primitives
