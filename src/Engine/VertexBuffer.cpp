#include "Engine/VertexBuffer.hpp"

void phyto::engine::VertexBuffer::cleanup() const
{
	if (m_id != 0)
	{
		glDeleteBuffers(1, &m_id);
	}
}

phyto::engine::VertexBuffer::VertexBuffer() : m_id{0}
{
	glGenBuffers(1, &m_id);
}

phyto::engine::VertexBuffer::~VertexBuffer()
{
	cleanup();
}

phyto::engine::VertexBuffer::VertexBuffer(phyto::engine::VertexBuffer&& other) noexcept : m_id{other.m_id}
{
	other.m_id = 0;
}

phyto::engine::VertexBuffer& phyto::engine::VertexBuffer::operator=(phyto::engine::VertexBuffer&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_id = other.m_id;
		other.m_id = 0;
	}
	return *this;
}
void phyto::engine::VertexBuffer::loadData(size_t length, const GLfloat* pointer, GLenum usage) const
{
	bind();
	glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(length), pointer, usage);
}

void phyto::engine::VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void phyto::engine::VertexBuffer::loadData(std::span<GLfloat> data, GLenum usage) const
{
	loadData(data.size_bytes(), data.data(), usage);
}
