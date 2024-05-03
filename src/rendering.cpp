#include "rendering.hpp"
#include "cmark.h"
#include "inja/inja.hpp"
#include <string>

std::string render_markdown(std::string input) {
  char *rendered_c =
      cmark_markdown_to_html(input.c_str(), input.length(), CMARK_OPT_DEFAULT);

  // convert the result into a c++ string and free the raw c string
  std::string rendered(rendered_c);
  free(rendered_c);

  return rendered;
}

std::string render_template(std::string input, inja::Template templ,
                            PageData data) {
  inja::json json_data;

  json_data["title"] = data.title;
  json_data["content"] = input;

  return inja::render(templ.content, json_data);
}
