#pragma once

#include "CGLSL/Internal/PCRE.hpp"
#include "CGLSL/ShaderSource.hpp"
#include <string_view>

namespace cglsl
{
class Parser
{
	pcre2_code* m_typePatternCode;
	void cleanup() const;

  public:
	Parser();
	~Parser();
	Parser(const Parser&) = delete;
	Parser& operator=(const Parser&) = delete;
	Parser(Parser&& other) noexcept;
	Parser& operator=(Parser&& other) noexcept;
	ShaderSource parse(std::string_view shaderPath);
};
} // namespace cglsl