#pragma once

#include "Engine/internal/graphics.hpp"

namespace phyto::engine
{
class VertexArray
{
	GLuint m_id;
	void cleanup() const;

  public:
	VertexArray();
	~VertexArray();
	VertexArray(const VertexArray&) = delete;
	VertexArray& operator=(const VertexArray&) = delete;
	VertexArray(VertexArray&& other) noexcept;
	VertexArray& operator=(VertexArray&& other) noexcept;

	void bind() const;
};
} // namespace phyto::engine
