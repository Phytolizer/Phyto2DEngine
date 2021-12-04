#pragma once

#include "CGLSL/ShaderSource.hpp"
#include <string_view>

namespace cglsl
{
class Parser
{
  public:
	ShaderSource parse(std::string_view shaderPath);
};
} // namespace cglsl