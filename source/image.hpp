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

#pragma once

#include "interfaces.hpp"

#include <ImageMagick-7/Magick++.h>
#include <ImageMagick-7/MagickCore/magick-type.h>
#include <ImageMagick-7/Magick++/Geometry.h>
#include <ImageMagick-7/Magick++/Color.h>

class ImageProcessor
{

  private:
    Magick::Image image;

  public:

    Colour colour;

    ImageProcessor ( const std::string &, const char *[]);

};

ImageProcessor::ImageProcessor ( const std::string & path, const char * argv[])
{

  Magick::InitializeMagick(*argv);

  image.read(path);

  image.resize( Magick::Geometry(1, 1, 1, 1) );

  Magick::Color colour = image.pixelColor( 0, 0 );

  this->colour.red   = colour.quantumRed() * 255 * QuantumScale;
  this->colour.green = colour.quantumGreen() * 255 * QuantumScale;
  this->colour.blue  = colour.quantumBlue() * 255 * QuantumScale;

}
