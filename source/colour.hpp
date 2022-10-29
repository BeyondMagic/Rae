#pragma once

#include "interfaces.hpp"

#include <cmath>

class ColourProcessor
{

  private:

    inline static constexpr double rY = 0.212655;
    inline static constexpr double gY = 0.715158;
    inline static constexpr double bY = 0.072187;

    Colour colour;

  public:

    [[nodiscard]] auto gam_sRGB_inverse(int) -> double;
    [[nodiscard]] auto gam_sRGB(double) -> double;
    [[nodiscard]] auto gray() -> double;
    ColourProcessor ( Colour & );

};

double ColourProcessor::gam_sRGB_inverse (int c)
{

  double ic = c/255.0;
  if ( ic <= 0.04045 )
    return ic/12.92;
  else
    return std::pow( ( (ic+0.055) / (1.055) ), 2.4 );

}

double ColourProcessor::gam_sRGB ( double v )
{

  if (v <= 0.0031308)
    v *= 12.92;
  else
    v = 1.055 * std::pow(v, 1.0/2.4) - 0.055;

  return v * 255 + 0.5;

}
  
double ColourProcessor::gray()
{

  return gam_sRGB(
      rY * gam_sRGB_inverse(colour.blue) +
      gY * gam_sRGB_inverse(colour.green) +
      bY * gam_sRGB_inverse(colour.blue)
  );

}

ColourProcessor::ColourProcessor ( Colour & color )
{

  this->colour.red   = color.red;
  this->colour.green = color.green;
  this->colour.blue  = color.blue;

}
