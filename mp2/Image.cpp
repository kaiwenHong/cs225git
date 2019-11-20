#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <algorithm>
#include <iostream>

using cs225::PNG;
using cs225::HSLAPixel;
using namespace std;

void Image::lighten() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.l += 0.1;
      if (pixel.l > 1) pixel.l = 1;
    }
  }
}

void Image::lighten(double amount) {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.l += amount;
      if (pixel.l > 1) pixel.l = 1;
    }
  }
}

void Image::darken() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.l -= 0.1;
      if (pixel.l < 0) pixel.l = 0;
    }
  }
}

void Image::darken(double amount) {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.l -= amount;
      if (pixel.l < 0) pixel.l = 0;
    }
  }
}

void Image::saturate() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s += 0.1;
      if (pixel.s > 1) pixel.s = 1;
    }
  }
}

void Image::saturate(double amount) {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s += amount;
      if (pixel.s > 1) pixel.s = 1;
    }
  }
}

void Image::desaturate() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s -= 0.1;
      if (pixel.s < 0) pixel.s = 0;
    }
  }
}

void Image::desaturate(double amount) {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s -= amount;
      if (pixel.s < 0) pixel.s = 0;
    }
  }
}

void Image::grayscale() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.s = 0;
    }
  }
}

void Image::rotateColor(double degrees) {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      pixel.h += degrees;
      while (pixel.h > 360) {
	pixel.h -= 360;
      }
      while (pixel.h < 0) {
	pixel.h += 360;
      }
    }
  }
}

void Image::illinify() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel & pixel = getPixel(x, y);
      if ((pixel.h > 113) && (pixel.h < 294)) {
          pixel.h = 216;
      } else {
          pixel.h = 11;
      }
    }
  }
}

void Image::scale(double factor) {
  if (factor > 1) {
    resize(width() * factor, height() * factor);
      for (int x = width() - 1; x >= 0; x--) {
        for (int y = height() - 1; y >= 0; y--) {
          HSLAPixel & newPixel = getPixel((unsigned)x, (unsigned)y);
          HSLAPixel & oldPixel = getPixel((unsigned)x / factor, (unsigned)y / factor);
          newPixel = oldPixel;
        }
      }
  }
  if (factor < 1) {
    for (unsigned x = 0; x < width() * factor; x++) {
      for (unsigned y = 0; y < height() * factor; y++) {
        HSLAPixel & newPixel = getPixel(x, y);
        HSLAPixel & oldPixel = getPixel(x / factor, y / factor);
        newPixel = oldPixel;
      }
    }
    resize(width() * factor, height() * factor);
  }
}

void Image::scale(unsigned w,unsigned h) {
  double widthFactor = (double) w / (double) width();
  double heightFactor = (double) h / (double) height();
  double factor = std::min(widthFactor, heightFactor);
  scale(factor);
}
