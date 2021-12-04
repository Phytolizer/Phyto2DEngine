#include "Engine/Window.hpp"
#include <stdexcept>

phyto::engine::Window::Window(const std::string& title, int width, int height)
{
	if (glfwInit() != GLFW_TRUE)
	{
		throw std::runtime_error{"GLFW initialization failed!"};
	}
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	m_handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (m_handle == nullptr)
	{
		throw std::runtime_error{"GLFW window creation failed!"};
	}
	glfwMakeContextCurrent(m_handle);
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == GL_FALSE)
	{
		throw std::runtime_error{"OpenGL loading failed!"};
	}
}
