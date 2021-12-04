#include "Engine/Primitives/Triangle.hpp"
#include <glm/gtc/type_ptr.hpp>

void phyto::engine::primitives::Triangle::loadBuffer()
{
	m_vb.loadData(m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);
}

phyto::engine::primitives::Triangle::Triangle(std::array<glm::vec3, 3> vertices) : m_vertices{0.0f}, m_vb{}, m_attr{-1}
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			m_vertices[j + i * 3] = vertices[i][(int)j];
		}
	}
	loadBuffer();
}

phyto::engine::primitives::Triangle::Triangle(std::array<float, 9> vertices) : m_vertices{vertices}, m_vb{}, m_attr{-1}
{
	loadBuffer();
}

void phyto::engine::primitives::Triangle::setAttribute(int attr, size_t size, GLenum type, GLenum normalized,
                                                       size_t stride, size_t offset)
{
	glVertexAttribPointer(attr, (GLint)size, type, normalized, (GLsizei)stride, (void*)offset);
	glEnableVertexAttribArray(attr);
	m_attr = attr;
}

void phyto::engine::primitives::Triangle::bind() const
{
	glEnableVertexAttribArray(m_attr);
}

void phyto::engine::primitives::Triangle::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
