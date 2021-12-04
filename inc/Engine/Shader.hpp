#pragma once

#include <glad/glad.h>
#include <string_view>

namespace phyto::engine
{
class Shader
{
	GLuint m_id;

	explicit Shader(GLuint id);
	void cleanup() const;

  public:
	~Shader();
	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;
	Shader(Shader&& other) noexcept;
	Shader& operator=(Shader&& other) noexcept;

	static Shader fromFile(std::string_view path);
};
} // namespace phyto::engine
