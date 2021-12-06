#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace phyto::engine::primitives
{
struct ColoredPoint
{
	glm::vec3 position;
	glm::vec4 color;
};
} // namespace phyto::engine::primitives