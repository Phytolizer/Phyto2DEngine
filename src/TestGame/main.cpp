#include "Engine/Primitives/Quad.hpp"
#include <Engine/Primitives/Triangle.hpp>
#include <Engine/Shader.hpp>
#include <Engine/VertexArray.hpp>
#include <Engine/Window.hpp>
#include <cmath>

int main()
{
	auto window = phyto::engine::Window{"Test window", 800, 600};
	auto s = phyto::engine::Shader::fromFile("res/shaders/default.cglsl");
	phyto::engine::VertexArray vao;
	vao.bind();
	//	phyto::engine::primitives::Triangle t{std::array{
	//	    glm::vec3{-0.5f, -0.5f, 0.0f},
	//	    glm::vec3{0.5f, -0.5f, 0.0f},
	//	    glm::vec3{0.0f, 0.5f, 0.0f},
	//	}};
	//	t.setPositionAttribute(0);

	phyto::engine::primitives::Quad q{std::array{
	    glm::vec3{0.5f, 0.5f, 0.0f},
	    glm::vec3{0.5f, -0.5f, 0.0f},
	    glm::vec3{-0.5f, -0.5f, 0.0f},
	    glm::vec3{-0.5f, 0.5f, 0.0f},
	}};
	q.setPositionAttribute(0);

	while (!window.shouldClose())
	{
		glfwPollEvents();
		glClearColor(0, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		float greenValue = sinf((float)glfwGetTime()) / 2.0f + 0.5f;
		s.uploadUniform("uColor", {0.0f, greenValue, 0.0f, 1.0f});
		s.bind();
		vao.bind();
		q.draw();
		window.swapBuffers();
	}
	return 0;
}
