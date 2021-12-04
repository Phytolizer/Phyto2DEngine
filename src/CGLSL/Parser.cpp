#include "CGLSL/Parser.hpp"
#include "CGLSL/internal/PCRE.hpp"
#include <IO/IO.hpp>
#include <array>
#include <sstream>
#include <stdexcept>

enum class ShaderType
{
	NONE,
	VERTEX,
	FRAGMENT,
};

cglsl::ShaderSource cglsl::Parser::parse(std::string_view shaderPath)
{
	std::string shaderSource = io::readEntireFile(shaderPath);

	static pcre2_code* typePatternCode = nullptr;
	if (typePatternCode == nullptr)
	{
		int errorCode;
		size_t errorOffset;
		typePatternCode = pcre2_compile((PCRE2_SPTR)(R"(^#type\s+(\w+)$)"), PCRE2_ZERO_TERMINATED, 0, &errorCode,
		                                &errorOffset, nullptr);
		if (typePatternCode == nullptr)
		{
			std::ostringstream message;
			std::array<PCRE2_UCHAR8, 256> pcreMessage{'\0'};
			pcre2_get_error_message(errorCode, pcreMessage.data(), pcreMessage.size());
			message << "[FATAL] PCRE2 regex compilation failed when it really shouldn't with the following message: "
			        << pcreMessage.data();
			throw std::runtime_error{message.str()};
		}
	}

	auto prevType = ShaderType::NONE;
	pcre2_match_data* matchData = pcre2_match_data_create_from_pattern(typePatternCode, nullptr);
	size_t offset = 0;
	ShaderSource result;

	while (true)
	{
		int matchResult = pcre2_match(typePatternCode, (PCRE2_SPTR)shaderSource.c_str(), shaderSource.size(), offset, 0,
		                              matchData, nullptr);
		if (matchResult == PCRE2_ERROR_NOMATCH)
		{
			break;
		}
		if (matchResult < 0)
		{
			std::array<PCRE2_UCHAR8, 256> pcreMessage{'\0'};
			pcre2_get_error_message(matchResult, pcreMessage.data(), pcreMessage.size());
			std::ostringstream message;
			message << "[FATAL] PCRE2 regex matching failed with the following message: " << pcreMessage.data();
			throw std::runtime_error{message.str()};
		}

		size_t* ovector = pcre2_get_ovector_pointer(matchData);
		switch (prevType)
		{
		case ShaderType::NONE:
			break;
		case ShaderType::VERTEX:
			result.vertex = std::string{shaderSource.begin() + (long)offset, shaderSource.begin() + (long)ovector[0]};
			break;
		case ShaderType::FRAGMENT:
			result.fragment = std::string{shaderSource.begin() + (long)offset, shaderSource.begin() + (long)ovector[0]};
			break;
		}

		std::string_view matchedGroup{shaderSource.begin() + (long)ovector[2], shaderSource.begin() + (long)ovector[3]};
		if (matchedGroup == "vertex")
		{
			prevType = ShaderType::VERTEX;
		}
		else if (matchedGroup == "fragment")
		{
			prevType = ShaderType::FRAGMENT;
		}
		else
		{
			std::ostringstream message;
			message << "Unknown shader type: " << matchedGroup;
			throw std::runtime_error{message.str()};
		}
		offset = ovector[1];
	}

	switch (prevType)
	{
	case ShaderType::NONE:
		break;
	case ShaderType::VERTEX:
		result.vertex = std::string{shaderSource.begin() + (long)offset, shaderSource.end()};
		break;
	case ShaderType::FRAGMENT:
		result.fragment = std::string{shaderSource.begin() + (long)offset, shaderSource.end()};
		break;
	}

	return result;
}