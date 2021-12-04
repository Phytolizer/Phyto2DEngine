#include <Engine/Shader.hpp>
#include <Engine/Window.hpp>

int main()
{
	auto window = phyto::engine::Window{"Test window", 800, 600};
	auto s = phyto::engine::Shader::fromFile("res/shaders/default.cglsl");
	return 0;
}
