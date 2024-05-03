cmake_minimum_required(VERSION 3.5)
project(mksite)

# cmake properties
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)
set(ENABLE_TESTING OFF)
set(BUILD_TESTING OFF)

# add libraries
add_subdirectory(thirdparty/cmark)
add_subdirectory(thirdparty/inja)

# setup executable
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/page.cpp
  src/rendering.cpp
  src/frontmatter.cpp
  src/yaml.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  include/
)

# link libraries
target_link_libraries(${PROJECT_NAME}
  cmark -static
  inja -static
)
