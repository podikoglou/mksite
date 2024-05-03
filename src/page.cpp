#include "page.hpp"
#include "frontmatter.hpp"
#include "inja/inja.hpp"
#include "rendering.hpp"
#include <string>

Page::Page(std::string input, inja::Template templ) {
  this->m_input = strip_frontmatter(input);
  this->m_template = templ;
  this->m_pageData = parse_frontmatter(input);
}

std::string Page::render() {
  std::string output;

  output = render_markdown(this->m_input);
  output = render_template(output, this->m_template, this->m_pageData);

  return output;
}
