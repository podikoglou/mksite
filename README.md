# mksite
A tiny and portable static site generator

## Philosophy
`mksite` follows Unix principles:
- it takes a markdown file as input through stdin
- it gives back the processed page as HTML through stdout

This means that *you* are responsible for the actual build process of the
website. More commonly, a tool like [GNU
make](https://www.gnu.org/software/make/manual/make.html) or
[mk](https://doc.cat-v.org/plan_9/4th_edition/papers/mk) is responsible for
running `mksite`. You can even use plain shell scripts.

## Usage Example
```
$ cat index.md
---
title: 'mksite'
---

# `mksite`
A tiny and portable static site generator

$ cat index.md | mksite
<!doctype html>
<html lang="en">
  <head>
    <title>mksite</title>
  </head>
  <body>
    <h1><pre>mksite</pre></h1>
    <p>
      <A tiny and portable static site generator
    </p>
  </body>
</html>
```

# Getting

## Binaries
Binaries are published on
[GitHub](https://github.com/podikoglou/mksite/releases)

## Building from Source
mksite is written in C++ and uses [xmake](https://xmake.io) as its build
system.

Thankfully, xmake has the ability to generate the appropriate CMakeLists.txt,
which I commit to the repository, so you don't need to have xmake on your
system to build mksite.
