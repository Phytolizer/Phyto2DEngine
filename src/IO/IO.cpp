#include "IO/IO.hpp"
#include <sstream>

std::string io::readEntireStream(std::istream stream)
{
	std::ostringstream ss;
	ss << stream.rdbuf();
	return ss.str();
}
