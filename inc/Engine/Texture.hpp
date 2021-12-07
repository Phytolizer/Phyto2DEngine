#pragma once

#include "Engine/Internal/Graphics.hpp"

namespace phyto::engine
{
class Texture
{
	GLuint m_id;
	GLsizei m_width;
	GLsizei m_height;

  public:
	Texture(GLsizei width, GLsizei height);
};
} // namespace phyto::engine