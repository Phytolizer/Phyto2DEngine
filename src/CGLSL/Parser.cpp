#include "CGLSL/Parser.hpp"
#include <IO/IO.hpp>
#include <fstream>

cglsl::ShaderSource cglsl::Parser::parse(std::string_view shaderPath)
{
	std::string shaderSource = io::readEntireFile(shaderPath);
}