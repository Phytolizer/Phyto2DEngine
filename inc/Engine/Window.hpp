#pragma once

#include "Engine/Internal/graphics.hpp"
#include <string>

namespace phyto::engine
{
class Window
{
	GLFWwindow* m_handle;

  public:
	Window(const std::string& title, int width, int height);
	bool shouldClose();
	void swapBuffers();
};
} // namespace phyto::engine
