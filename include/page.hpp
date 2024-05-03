#include <string>

#pragma once

class Page {
public:
  Page(std::string);

  std::string render();

private:
  std::string m_input;

  std::string m_template;
};
