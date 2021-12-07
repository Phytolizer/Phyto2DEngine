#pragma once

#include "SpriteRenderer.hpp"
#include <Engine/Shader.hpp>
#include <Engine/Window.hpp>

class Game
{
	phyto::engine::Window m_window;
	phyto::engine::Shader m_spriteShader;
	SpriteRenderer m_renderer;
	phyto::engine::Texture m_faceTexture;

  public:
	explicit Game(int width, int height, GLubyte* data);

	void render();
	bool shouldClose();
};
