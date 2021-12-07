#pragma once

#include "Engine/Internal/Graphics.hpp"
#include <glm/vec4.hpp>
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
	void bind() const;
	void uploadUniform(const std::string& name, const glm::vec4& value) const;
};
} // namespace phyto::engine
