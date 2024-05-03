#include "page.hpp"
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // read markdown file from stdin
  std::string input, linebuf;

  while (!std::cin.eof()) {
    std::getline(std::cin, linebuf);

    input += linebuf + "\n";
  }

  // create and render the page
  Page page(input);

  printf("%s", page.render().c_str());

  return 0;
}
