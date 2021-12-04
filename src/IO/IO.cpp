#include "IO/IO.hpp"
#include <fstream>
#include <sstream>

std::string io::readEntireFile(std::string_view path)
{
	std::ifstream stream{std::string{path}};
	std::ostringstream ss;
	ss << stream.rdbuf();
	return ss.str();
}
