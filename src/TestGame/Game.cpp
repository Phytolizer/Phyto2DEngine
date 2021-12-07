#include "Game.hpp"
#include <CGLSL/Parser.hpp>
#include <glm/ext/matrix_clip_space.hpp>

Game::Game(int width, int height, GLubyte* data)
    : m_window{"Breakout", 800, 600}, m_spriteShader{phyto::engine::Shader::fromFile("res/shaders/sprite.cglsl")},
      m_renderer{m_spriteShader}, m_faceTexture{width, height, data}
{
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_window.width()), static_cast<float>(m_window.height()),
	                                  0.0f, -1.0f, 1.0f);
	m_spriteShader.bind();
	m_spriteShader.uploadUniform("image", 0);
	m_spriteShader.uploadUniform("projection", projection);
}
bool Game::shouldClose()
{
	return m_window.shouldClose();
}
void Game::render()
{
	m_renderer.drawSprite(m_faceTexture, glm::vec2{200.0f, 200.0f}, glm::vec2{300.0f, 400.0f}, 45.0f,
	                      glm::vec3{0.0f, 1.0f, 0.0f});
	m_window.swapBuffers();
}
