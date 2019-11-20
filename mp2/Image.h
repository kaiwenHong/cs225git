/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include "cs225/PNG.h"

using namespace cs225;

namespace cs225 {
  class Image : public cs225::PNG {

    public:

    Image(unsigned width, unsigned height) : cs225::PNG(width, height) {};
    Image() : cs225::PNG() {};
    void lighten();
    void lighten(double amount);
    void darken();
    void darken(double amount);
    void saturate();
    void saturate(double amount);
    void desaturate();
    void desaturate(double amount);
    void grayscale();
    void rotateColor(double degrees);
    void illinify();
    void scale(double factor);
    void scale(unsigned w, unsigned h);

  };
}
