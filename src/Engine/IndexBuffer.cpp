#include "Engine/IndexBuffer.hpp"

void phyto::engine::IndexBuffer::cleanup() const
{
	if (m_id != 0)
	{
		glDeleteBuffers(1, &m_id);
	}
}

phyto::engine::IndexBuffer::IndexBuffer() : m_id{0}
{
	glGenBuffers(1, &m_id);
}

phyto::engine::IndexBuffer::~IndexBuffer()
{
	cleanup();
}

phyto::engine::IndexBuffer::IndexBuffer(phyto::engine::IndexBuffer&& other) noexcept : m_id{other.m_id}
{
	other.m_id = 0;
}

phyto::engine::IndexBuffer& phyto::engine::IndexBuffer::operator=(phyto::engine::IndexBuffer&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_id = other.m_id;
		other.m_id = 0;
	}
	return *this;
}

void phyto::engine::IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void phyto::engine::IndexBuffer::loadData(size_t length, const GLuint* pointer, GLenum usage) const
{
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(length), pointer, usage);
}

void phyto::engine::IndexBuffer::loadData(std::span<GLuint> data, GLenum usage) const
{
	loadData(data.size_bytes(), data.data(), usage);
}
