#include "inja/inja.hpp"
#include <string>

#pragma once

class Page {
public:
  Page(std::string, inja::Template templ);

  std::string render();

private:
  std::string m_input;
  inja::Template m_template;

  inja::json m_pageData;
};
