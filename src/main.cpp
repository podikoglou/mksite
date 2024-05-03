#include "page.hpp"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

int main(int argc, char **argv) {
  // read cli arguments (in a horrible way)
  if (argc <= 1 || std::strcmp(argv[1], "--template") != 0) {
    printf("usage: %s [--template TEMPLATE]\n", argv[0]);
    return 1;
  }

  std::string template_path = argv[2];

  // make sure the template file exists
  std::ifstream template_file(template_path);

  if (!template_file.good()) {
    printf("error: couldn't open %s\n", template_path.c_str());

    template_file.close();
    return 1;
  }

  template_file.close();

  // create template environment and parse the template
  inja::Environment environment;
  inja::Template templ = environment.parse_template(template_path);

  // read markdown file from stdin
  std::string input, linebuf;

  while (!std::cin.eof()) {
    std::getline(std::cin, linebuf);

    input += linebuf + "\n";
  }

  // create and render the page
  Page page(input, templ);

  printf("%s", page.render().c_str());

  return 0;
}
