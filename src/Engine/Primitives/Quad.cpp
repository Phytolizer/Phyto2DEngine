#include "Engine/Primitives/Quad.hpp"

phyto::engine::primitives::Quad::Quad(std::array<glm::vec3, 4> points) : m_vertices{}, m_indices{}, m_attr{0}
{
	load({
	    points[0].x,
	    points[0].y,
	    points[0].z,
	    points[1].x,
	    points[1].y,
	    points[1].z,
	    points[2].x,
	    points[2].y,
	    points[2].z,
	    points[3].x,
	    points[3].y,
	    points[3].z,
	});
}

phyto::engine::primitives::Quad::Quad(std::array<GLfloat, 12> points) : m_vertices{}, m_indices{}, m_attr{0}
{
	load(points);
}
void phyto::engine::primitives::Quad::load(std::array<GLfloat, 12> points)
{
	m_vertices.loadData(points, GL_STATIC_DRAW);
	std::array<GLuint, 6> indices{0, 1, 2, 1, 2, 3};
	m_indices.loadData(indices, GL_STATIC_DRAW);
}

void phyto::engine::primitives::Quad::setAttribute(GLint attr)
{
	glVertexAttribPointer(attr, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
	glEnableVertexAttribArray(attr);
	m_attr = attr;
}
void phyto::engine::primitives::Quad::bind() const
{
	glEnableVertexAttribArray(m_attr);
}
void phyto::engine::primitives::Quad::draw()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
