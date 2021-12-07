#pragma once

#include <Engine/Shader.hpp>
#include <Engine/Texture.hpp>
#include <Engine/VertexArray.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class SpriteRenderer
{
	phyto::engine::Shader& m_shader;
	phyto::engine::VertexArray m_quadVao;

	void initRenderData();

  public:
	explicit SpriteRenderer(phyto::engine::Shader& shader);
	void drawSprite(const phyto::engine::Texture& texture, const glm::vec2& position,
	                const glm::vec2& size = glm::vec2{10, 10}, float rotate = 0.0f,
	                const glm::vec3& color = glm::vec3{1.0f});
};
