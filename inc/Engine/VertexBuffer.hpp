#pragma once

#include "Engine/Internal/graphics.hpp"
#include <span>

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
	void loadData(std::span<GLfloat> data, GLenum usage) const;
};
} // namespace phyto::engine
