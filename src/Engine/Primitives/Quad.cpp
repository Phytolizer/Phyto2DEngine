#include "Engine/Primitives/Quad.hpp"

phyto::engine::primitives::Quad::Quad(std::array<ColoredPoint, 4> points)
    : m_vertices{}, m_indices{}, m_positionAttr{-1}, m_colorAttr{-1}
{
	load({
	    points[0].position.x, points[0].position.y, points[0].position.z, points[0].color.r,    points[0].color.g,
	    points[0].color.b,    points[0].color.a,    points[1].position.x, points[1].position.y, points[1].position.z,
	    points[1].color.r,    points[1].color.g,    points[1].color.b,    points[1].color.a,    points[2].position.x,
	    points[2].position.y, points[2].position.z, points[2].color.r,    points[2].color.g,    points[2].color.b,
	    points[2].color.a,    points[3].position.x, points[3].position.y, points[3].position.z, points[3].color.r,
	    points[3].color.g,    points[3].color.b,    points[3].color.a,
	});
}

phyto::engine::primitives::Quad::Quad(std::array<GLfloat, 28> points)
    : m_vertices{}, m_indices{}, m_positionAttr{-1}, m_colorAttr{-1}
{
	load(points);
}
void phyto::engine::primitives::Quad::load(std::array<GLfloat, 28> points)
{
	m_vertices.loadData(points, GL_STATIC_DRAW);
	std::array<GLuint, 6> indices{0, 1, 2, 0, 2, 3};
	m_indices.loadData(indices, GL_STATIC_DRAW);
}

void phyto::engine::primitives::Quad::setPositionAttribute(GLint attr)
{
	glVertexAttribPointer(attr, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), nullptr);
	glEnableVertexAttribArray(attr);
	m_positionAttr = attr;
}
void phyto::engine::primitives::Quad::bind() const
{
	glEnableVertexAttribArray(m_positionAttr);
	glEnableVertexAttribArray(m_colorAttr);
}
void phyto::engine::primitives::Quad::draw()
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
void phyto::engine::primitives::Quad::setColorAttribute(GLint attr)
{
	bind();
	glVertexAttribPointer(attr, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(attr);
	m_colorAttr = attr;
}
