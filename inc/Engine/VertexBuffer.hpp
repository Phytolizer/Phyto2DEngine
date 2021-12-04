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
	void loadData(size_t length, const GLfloat* pointer, GLenum usage) const;
};
} // namespace phyto::engine
