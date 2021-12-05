#pragma once

#include <span>
#include "Engine/internal/graphics.hpp"

namespace phyto::engine
{
class IndexBuffer
{
	GLuint m_id;

	void cleanup() const;

  public:
	IndexBuffer();
	~IndexBuffer();
	IndexBuffer(const IndexBuffer&) = delete;
	IndexBuffer& operator=(const IndexBuffer&) = delete;
	IndexBuffer(IndexBuffer&& other) noexcept;
	IndexBuffer& operator=(IndexBuffer&& other) noexcept;

	void bind() const;
	void loadData(size_t length, const GLuint* pointer, GLenum usage) const;
	void loadData(std::span<GLuint> data, GLenum usage) const;
};
} // namespace phyto::engine