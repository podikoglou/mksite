#include "page.hpp"
#include "cmark.h"
#include <string>

Page::Page(std::string input) { this->m_input = input; }

std::string Page::render() {
  // render markdown into html using cmark
  char *rendered_c = cmark_markdown_to_html(
      this->m_input.c_str(), this->m_input.length(), CMARK_OPT_DEFAULT);

  // convert the result into a c++ string and free the raw c string
  std::string rendered(rendered_c);
  free(rendered_c);

  // TODO: pass through template engine

  return rendered;
}
