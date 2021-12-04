#include "Engine/Primitives/Triangle.hpp"
#include <glm/gtc/type_ptr.hpp>

phyto::engine::primitives::Triangle::Triangle(std::array<glm::vec3, 3> vertices) : m_vertices{vertices}, m_vbo{0}
{
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), glm::value_ptr(m_vertices[0]), GL_STATIC_DRAW);
}
