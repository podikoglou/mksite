#pragma once

#include "inja/inja.hpp"
#include "page.hpp"
#include <string>

std::string render_markdown(std::string);
std::string render_template(std::string, inja::Template, PageData);
