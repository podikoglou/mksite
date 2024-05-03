add_rules("mode.debug", "mode.release")

add_requires("cmark")

-- binary target
target("mksite")

set_kind("binary")
set_languages("c++11")

add_files("src/*.cpp")
add_includedirs("include/")
add_packages("cmark")

target_end()
