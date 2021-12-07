#include "SpriteRenderer.hpp"
#include <Engine/VertexBuffer.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

void SpriteRenderer::initRenderData()
{
	std::array vertices{
	    0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	    0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	};

	phyto::engine::VertexBuffer vbo;
	vbo.bind();
	vbo.loadData(vertices, GL_STATIC_DRAW);

	m_quadVao.bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
}
SpriteRenderer::SpriteRenderer(phyto::engine::Shader* shader) : m_shader{shader}, m_quadVao{}
{
}
void SpriteRenderer::drawSprite(const phyto::engine::Texture& texture, const glm::vec2& position, const glm::vec2& size,
                                float rotate, const glm::vec3& color)
{
	m_shader->bind();
	glm::mat4 model{1.0f};
	model = glm::translate(model, glm::vec3{position, 0.0f});
	model = glm::translate(model, glm::vec3{0.5f * size.x, 0.5f * size.y, 0.0f});
	model = glm::rotate(model, glm::radians(rotate), glm::vec3{0.0f, 0.0f, 1.0f});
	model = glm::translate(model, glm::vec3{-0.5f * size.x, -0.5f * size.y, 0.0f});
	model = glm::scale(model, glm::vec3{size, 1.0f});
	m_shader->uploadUniform("model", model);
	m_shader->uploadUniform("spriteColor", color);
	glActiveTexture(GL_TEXTURE0);
	texture.bind();
	m_quadVao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
