#include "frontmatter.hpp"
#include "nlohmann/json.hpp"
#include "yaml.hpp"
#include <cstddef>
#include <cstdio>
#include <string>
#include <tuple>

std::tuple<size_t, size_t> find_frontmatter(std::string input) {
  size_t first = input.find_first_of("---");
  size_t last = input.find_last_of("---");

  return std::make_tuple(first, last);
}

std::string strip_frontmatter(std::string input) {
  std::tuple<size_t, size_t> fm = find_frontmatter(input);

  size_t start = std::get<0>(fm);
  size_t end = std::get<1>(fm);

  // no idea if this works (probably not)
  return input.substr(end + 3);
}

nlohmann::json parse_frontmatter(std::string input) {
  nlohmann::json data;

  // get the starting and ending position of the frontmatter excluding the
  // dashes
  std::tuple<size_t, size_t> fm = find_frontmatter(input);

  size_t start = std::get<0>(fm) + 3;
  size_t end = std::get<1>(fm) - 5;
  //                            ^^^
  // POTENTIAL BUG: I have **NO** idea why I have to do - 5 here and not - 3

  std::string raw_yaml = input.substr(start, end);

  // parse yaml
  Yaml::Node yaml;
  Yaml::Parse(yaml, raw_yaml);

  for (auto it = yaml.Begin(); it != yaml.End(); it++) {
    // maybe we can make value support other data types?
    std::string key = (*it).first;
    std::string value = (*it).second.As<std::string>();

    data[key] = value;
  }

  return data;
}
