#include "Game.hpp"
#include <stb_image.h>

int main()
{
	int width;
	int height;
	int nChannels;
	GLubyte* data = stbi_load("res/images/awesomeface.png", &width, &height, &nChannels, 0);
	Game game{width, height, data};

	while (!game.shouldClose())
	{
		glfwPollEvents();
		game.render();
	}
	return 0;
}
