add_rules("mode.debug", "mode.release")

add_requires("cmark")
add_requires("inja")

-- binary target
target("mksite")

set_kind("binary")
set_languages("c++17")

add_files("src/*.cpp")
add_includedirs("include/")
add_packages("cmark")
add_packages("inja")

target_end()
