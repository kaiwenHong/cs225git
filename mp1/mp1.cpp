#include "cs225/PNG.h"
using cs225::PNG;

#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <string>
#include <stdlib.h>
#include <complex>
#include <cmath>

using namespace std;

void rotate(std::string inputFile, std::string outputFile) {
	
	PNG png;
	png.readFromFile(inputFile);
	
	PNG result = PNG(png.width(), png.height());
	
	for (unsigned x = 0; x < png.width(); x++) {
		for (unsigned y = 0; y < png.height(); y++) {
			
		        HSLAPixel & pixelInput = png.getPixel(x, y);
			HSLAPixel & pixelOutput = result.getPixel(png.width() - x - 1, png.height() - y - 1); 
		
			pixelOutput = pixelInput;

		}
	}

	result.writeToFile(outputFile);
	
  // TODO: Part 2
}

PNG myArt(unsigned int width, unsigned int height) {

  //Ensures the png file is a square.
  width = height;
  PNG png(width, width);
  
  //Rotation angle
  int a = rand() % 10;

  //Path
  int b = rand() % 50 + 30;

  //Radius
  double r;

  double color = rand() % 200;

  //T(Theta) -  Phase Angle
  for (double t = 0; t < b; t = t + 0.001) {

    //Calculate radius
    r = 100 * (exp(cos(t-a)) - 2 * cos(4*(t-a)) + pow(sin((t-a)/12), 5));

    complex<double> coord = polar(r, t);
    
    if ((int(real(coord)) > -400) && (int(real(coord)) < 400) && (int(imag(coord)) > -400) && (int(imag(coord)) < 400)) {

	HSLAPixel & pixel = png.getPixel(400 + int(real(coord)), 400 + int(imag(coord)));
	pixel.h = int(color);
 	pixel.s = 1;
	pixel.l = 0.5;
	pixel.a = 0.5;

    }

	color = color + 0.005;
  }
 
  return png;

}
