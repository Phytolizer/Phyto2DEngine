#include "Engine/Shader.hpp"
#include "CGLSL/Parser.hpp"

phyto::engine::Shader::Shader(GLuint id) : m_id{id}
{
}

phyto::engine::Shader phyto::engine::Shader::fromFile(std::string_view path)
{
	cglsl::ShaderSource sources = cglsl::Parser{}.parse(path);

	return Shader{0};
}
