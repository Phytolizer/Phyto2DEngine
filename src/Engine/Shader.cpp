#include "Engine/Shader.hpp"
#include "CGLSL/Parser.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include <vector>

phyto::engine::Shader::Shader(GLuint id) : m_id{id}
{
}

phyto::engine::Shader phyto::engine::Shader::fromFile(std::string_view path)
{
	cglsl::ShaderSource sources = cglsl::Parser{}.parse(path);

	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexSource = sources.vertex.c_str();
	int vertexLength = (int)sources.vertex.size();
	glShaderSource(vertex, 1, &vertexSource, &vertexLength);
	glCompileShader(vertex);
	int success;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> rawLog(infoLogLength, '\0');
		glGetShaderInfoLog(vertex, infoLogLength, &infoLogLength, rawLog.data());
		std::ostringstream message;
		message << "Vertex shader compilation failed!\n";
		message << std::string{rawLog.data(), rawLog.data() + rawLog.size()};
		throw std::runtime_error{message.str()};
	}

	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentSource = sources.fragment.c_str();
	int fragmentLength = (int)sources.fragment.size();
	glShaderSource(fragment, 1, &fragmentSource, &fragmentLength);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> rawLog(infoLogLength, '\0');
		glGetShaderInfoLog(fragment, infoLogLength, &infoLogLength, rawLog.data());
		std::ostringstream message;
		message << "Fragment shader compilation failed!\n";
		message << std::string{rawLog.data(), rawLog.data() + rawLog.size()};
		throw std::runtime_error{message.str()};
	}

	GLuint program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> rawLog(infoLogLength, '\0');
		glGetProgramInfoLog(program, infoLogLength, &infoLogLength, rawLog.data());
		std::ostringstream message;
		message << "Shader program linking failed!\n";
		message << std::string{rawLog.data(), rawLog.data() + rawLog.size()};
		throw std::runtime_error{message.str()};
	}

	glDetachShader(program, vertex);
	glDetachShader(program, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	return Shader{program};
}
void phyto::engine::Shader::cleanup() const
{
	if (m_id != 0)
	{
		glDeleteProgram(m_id);
	}
}
phyto::engine::Shader::~Shader()
{
	cleanup();
}
phyto::engine::Shader::Shader(phyto::engine::Shader&& other) noexcept : m_id{other.m_id}
{
	other.m_id = 0;
}
phyto::engine::Shader& phyto::engine::Shader::operator=(phyto::engine::Shader&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_id = other.m_id;
		other.m_id = 0;
	}
	return *this;
}
void phyto::engine::Shader::bind() const
{
	glUseProgram(m_id);
}
void phyto::engine::Shader::uploadUniform(const std::string& name, const glm::vec4& uniform) const
{
	bind();
	int location = glGetUniformLocation(m_id, name.c_str());
	glUniform4fv(location, 1, glm::value_ptr(uniform));
}

void phyto::engine::Shader::uploadUniform(const std::string& name, const glm::mat4& value) const
{
	bind();
	int location = glGetUniformLocation(m_id, name.c_str());
	glUniform4fv(location, 4, glm::value_ptr(value));
}

void phyto::engine::Shader::uploadUniform(const std::string& name, const glm::vec3& value) const
{
	bind();
	int location = glGetUniformLocation(m_id, name.c_str());
	glUniform3fv(location, 1, glm::value_ptr(value));
}

void phyto::engine::Shader::uploadUniform(const std::string& name, int value) const
{
	bind();
	int location = glGetUniformLocation(m_id, name.c_str());
	glUniform1i(location, value);
}
