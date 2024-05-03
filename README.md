# mksite
A tiny and portable static site generator.

## Philosophy
`mksite` follows Unix principles:
- it takes a markdown file as input through stdin
- it gives back the processed page as HTML through stdout

This means that *you* are responsible for the actual build process of the
website. More commonly, a tool like [GNU
make](https://www.gnu.org/software/make/manual/make.html) or
[mk](https://doc.cat-v.org/plan_9/4th_edition/papers/mk) is responsible for
running `mksite`. You can even use plain shell scripts.

`mksite` draws inspiration from [saait](https://git.codemadness.org/saait/),
with the main difference being that `mksite` is less opinionated

## Usage Example
```console
$ cat index.md
---
title: 'mksite'
---

# `mksite`
A tiny and portable static site generator

$ cat template.html
<!doctype html>
<html lang="en">
  <head>
    <title>{{ title }}</title>
  </head>
  <body>
    {{ content }}
  </body>
</html>

$ cat index.md | mksite --template template.html
<!doctype html>
<html lang="en">
  <head>
    <title>mksite</title>
  </head>
  <body>
    <h1><pre>mksite</pre></h1>
    <p>A tiny and portable static site generator</p>
  </body>
</html>
```

# Getting

## Binaries
Statically linked Binaries are published on
[GitHub](https://github.com/podikoglou/mksite/releases)

## Building from Source
`mksite` is written in C++17 and uses CMake as its build system. Here's a quick guide to helping you compile `mksite` from source:
```
git clone --recursive git@github.com:podikoglou/mksite.git
cd mksite
mkdir build
cd build
cmake ..
make -j $(nproc)
```
Your binary is at `./mksite`
