#include "Engine/Primitives/Triangle.hpp"

void phyto::engine::primitives::Triangle::loadBuffer()
{
	m_vb.loadData(m_vertices, GL_STATIC_DRAW);
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

void phyto::engine::primitives::Triangle::setPositionAttribute(int attr)
{
	glVertexAttribPointer(attr, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
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
