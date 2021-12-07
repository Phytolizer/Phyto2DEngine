#pragma once

#include "Engine/Internal/Graphics.hpp"
#include <string>

namespace phyto::engine
{
class Window
{
	GLFWwindow* m_handle;
	int m_width;
	int m_height;

  public:
	Window(const std::string& title, int width, int height);
	bool shouldClose();
	void swapBuffers();
	int width() const;
	int height() const;
};
} // namespace phyto::engine
