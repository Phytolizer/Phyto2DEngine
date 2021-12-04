#pragma once

#include <string>

namespace cglsl
{
struct ShaderSource
{
	std::string originatingFile;
	std::string vertex;
	std::string fragment;
};
} // namespace cglsl