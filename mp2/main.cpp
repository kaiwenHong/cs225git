#include "Image.h"
#include "StickerSheet.h"

int main() {

  Image base, wade, word_up, word_down, hi;
  base.readFromFile("stickers/kim.png");
  wade.readFromFile("stickers/waf.png");
  wade.scale(2);

  word_up.readFromFile("stickers/word_up.png");
  word_up.scale(610, 100);
  word_down.readFromFile("stickers/word_down.png");
  word_down.scale(729, 100);

  hi.readFromFile("stickers/hi.png");
  hi.scale(50, 50);

  StickerSheet output(base, 4);
  output.addSticker(wade, 335, 30);
  output.addSticker(word_up, 170, 10);
  output.addSticker(word_down, 100, 500);
  output.addSticker(hi, 285, 130);


  Image outputImage = output.render();
  outputImage.writeToFile("myImage.png");

  return 0;

}
