#include <Engine/Primitives/Triangle.hpp>
#include <Engine/Shader.hpp>
#include <Engine/VertexArray.hpp>
#include <Engine/Window.hpp>

int main()
{
	auto window = phyto::engine::Window{"Test window", 800, 600};
	auto s = phyto::engine::Shader::fromFile("res/shaders/default.cglsl");
	phyto::engine::VertexArray vao;
	vao.bind();
	phyto::engine::primitives::Triangle t{std::array{
	    glm::vec3{-0.5f, -0.5f, 0.0f},
	    glm::vec3{0.5f, -0.5f, 0.0f},
	    glm::vec3{0.0f, 0.5f, 0.0f},
	}};
	t.setAttribute(0);

	while (!window.shouldClose())
	{
		glfwPollEvents();
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		s.bind();
		vao.bind();
		t.bind();
		t.draw();
		window.swapBuffers();
	}
	return 0;
}
