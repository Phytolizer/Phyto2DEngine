#pragma once

#include "Engine/internal/graphics.hpp"

namespace phyto::engine
{
class VertexBuffer
{
	GLuint m_id;
	void cleanup() const;

  public:
	VertexBuffer();
	~VertexBuffer();
	VertexBuffer(const VertexBuffer&) = delete;
	VertexBuffer& operator=(const VertexBuffer&) = delete;
	VertexBuffer(VertexBuffer&& other) noexcept;
	VertexBuffer& operator=(VertexBuffer&& other) noexcept;

	void bind() const;
	void loadData(const GLfloat* pointer, size_t length, GLenum usage) const;
};
} // namespace phyto::engine
