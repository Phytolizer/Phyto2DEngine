#include "Engine/VertexArray.hpp"

void phyto::engine::VertexArray::cleanup() const
{
	if (m_id != 0)
	{
		glDeleteVertexArrays(1, &m_id);
	}
}

phyto::engine::VertexArray::VertexArray() : m_id{0}
{
	glGenVertexArrays(1, &m_id);
}

phyto::engine::VertexArray::~VertexArray()
{
	cleanup();
}

phyto::engine::VertexArray::VertexArray(phyto::engine::VertexArray&& other) noexcept : m_id{other.m_id}
{
	other.m_id = 0;
}

phyto::engine::VertexArray& phyto::engine::VertexArray::operator=(phyto::engine::VertexArray&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_id = other.m_id;
		other.m_id = 0;
	}
	return *this;
}

void phyto::engine::VertexArray::bind() const
{
	glBindVertexArray(m_id);
}
