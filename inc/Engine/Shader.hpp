#pragma once

#include <glad/glad.h>
#include <string_view>

namespace phyto::engine
{
class Shader
{
	GLuint m_id;

	explicit Shader(GLuint id);

  public:
	static Shader fromFile(std::string_view path);
};
} // namespace phyto::engine
