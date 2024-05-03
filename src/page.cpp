#include "page.hpp"
#include "rendering.hpp"
#include <string>

Page::Page(std::string input, inja::Template templ) {
  this->m_input = input;
  this->m_template = templ;
  this->m_pageData = PageData();

  // parse pagedata from the frontmatter on the input + remove the frontmatter
  // from the input
}

std::string Page::render() {
  std::string output;

  output = render_markdown(this->m_input);
  output = render_template(output, this->m_template, this->m_pageData);

  return output;
}
