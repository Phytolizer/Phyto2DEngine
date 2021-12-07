#pragma once

#include "Engine/Internal/Graphics.hpp"

namespace phyto::engine
{
class Texture
{
	GLuint m_id;
	GLsizei m_width;
	GLsizei m_height;

	void cleanup() const;

  public:
	Texture(GLsizei width, GLsizei height);
	~Texture();
	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;
	Texture(Texture&& other) noexcept;
	Texture& operator=(Texture&& other) noexcept;

	void bind() const;
	void setData(const GLubyte* data);
};
} // namespace phyto::engine