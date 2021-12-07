#include "Engine/Texture.hpp"

phyto::engine::Texture::Texture(GLsizei width, GLsizei height) : m_width{width}, m_height{height}, m_id{0}
{
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
}

phyto::engine::Texture::~Texture()
{
	cleanup();
}

phyto::engine::Texture::Texture(phyto::engine::Texture&& other) noexcept
    : m_width{other.m_width}, m_height{other.m_height}, m_id{other.m_id}
{
	other.m_id = 0;
}

phyto::engine::Texture& phyto::engine::Texture::operator=(phyto::engine::Texture&& other) noexcept
{
	if (&other != this)
	{
		cleanup();
		m_width = other.m_width;
		m_height = other.m_height;
		m_id = other.m_id;
		other.m_id = 0;
	}
	return *this;
}

void phyto::engine::Texture::cleanup() const
{
	if (m_id != 0)
	{
		glDeleteTextures(1, &m_id);
	}
}
void phyto::engine::Texture::setData(const GLubyte* data)
{
	bind();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}
void phyto::engine::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}
