/**
The MIT License (MIT)

Copyright (c) 2022 BeyondMagic

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
**/

#include <fmt/core.h>
#include <fmt/color.h>
#include <filesystem>

#include "rae.hpp"

int main ( const int argc, const char ** argv)
{

  if (argc not_eq 2)
  {
    fmt::print(stderr, fg(fmt::color::red), "[{}] You need to pass only a single argument for the application, the image path.\n", "Args");

    exit(1);
  }

  if (!std::filesystem::exists(argv[1]))
  {

    fmt::print(stderr, fg(fmt::color::red), "[{}] File not found in the system.\n", "Args");

    exit(1);

  }

  ImageProcessor p(argv[1], argv);

  ColourProcessor c( p.colour );

  fmt::print("rgb({},{},{})\n",
    std::ceil(p.colour.red),
    std::ceil(p.colour.green),
    std::ceil(p.colour.blue)
  );

  const auto gray = std::ceil( c.gray() );

  fmt::print("rgb({},{},{})\n", gray, gray, gray);

}
