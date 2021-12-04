#pragma once

#include <string_view>
#include <string>

namespace io
{
std::string readEntireFile(std::string_view path);
}
