#pragma once

#include "nlohmann/json.hpp"
#include <tuple>

std::tuple<size_t, size_t> find_frontmatter(std::string);

std::string strip_frontmatter(std::string);

nlohmann::json parse_frontmatter(std::string);
