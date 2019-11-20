#include "StickerSheet.h"
#include "Image.h"

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
  baseSheet = picture;
  maxStickers = max;
  imageSheet = new Image*[maxStickers];
  positionX = new unsigned[maxStickers];
  positionY = new unsigned[maxStickers];
  for (unsigned i = 0; i < max; i++) {
    imageSheet[i] = nullptr;
  }
}

StickerSheet::~StickerSheet() {
  Clear();
}

void StickerSheet::Clear() {
  delete[] positionX;
  positionX = nullptr;
  delete[] positionY;
  positionY = nullptr;
  delete[] imageSheet;
  imageSheet = nullptr;
}

StickerSheet::StickerSheet(const StickerSheet & other) {
  baseSheet = other.baseSheet;
  maxStickers = other.maxStickers;
  imageSheet = new Image*[maxStickers];
  positionX = new unsigned[maxStickers];
  positionY = new unsigned[maxStickers];
  for (unsigned i = 0; i < maxStickers; i++) {
    if(other.imageSheet[i] != nullptr) {
      imageSheet[i] = other.imageSheet[i];
    } else {
      imageSheet[i] = nullptr;
    }
    positionX[i] = other.positionX[i];
    positionY[i] = other.positionY[i];
  }
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
  Clear();
  baseSheet = other.baseSheet;
  maxStickers = other.maxStickers;
  imageSheet = new Image*[maxStickers];
  positionX = new unsigned[maxStickers];
  positionY = new unsigned[maxStickers];
  for (unsigned i = 0; i < other.maxStickers; i++) {
    if(other.imageSheet[i] != nullptr) {
      imageSheet[i] = other.imageSheet[i];
    } else {
      imageSheet[i] = nullptr;
    }    positionX[i] = other.positionX[i];
    positionY[i] = other.positionY[i];
  }
  return *this;
}

void StickerSheet::changeMaxStickers(unsigned max) {
  if (max == maxStickers) {
    return;
  } else {
    Image **tempImgSheet = new Image*[max];
    unsigned *tempPosX = new unsigned[max];
    unsigned *tempPosY = new unsigned[max];
    for (unsigned i = 0; i < max; i++) {
      tempImgSheet[i] = imageSheet[i];
      tempPosX[i] = positionX[i];
      tempPosY[i] = positionY[i];
    }
    if (max > maxStickers) {
      for (unsigned i = maxStickers; i < max; i++) tempImgSheet[i] = nullptr;
    }
    Clear();
    imageSheet = tempImgSheet;
    positionX = tempPosX;
    positionY = tempPosY;
    maxStickers = max;
  }
}

int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
  for (unsigned i = 0; i < maxStickers; i++) {
    if (imageSheet[i] == nullptr) {
      imageSheet[i] = &sticker;
      positionX[i] = x;
      positionY[i] = y;
      return i;
    }
  }
  return -1;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
  if (imageSheet[index] == nullptr || index >= maxStickers) {
    return false;
  } else {
    positionX[index] = x;
    positionY[index] = y;
    return true;
  }
}

void StickerSheet::removeSticker(unsigned index) {
  if (index < maxStickers && imageSheet[index] != nullptr) {
    imageSheet[index] = nullptr;
    delete imageSheet[index];
  }
}

Image * StickerSheet::getSticker(unsigned index) const {
  if (imageSheet[index] == nullptr) return nullptr;
  if (index > maxStickers) return nullptr;
  return imageSheet[index];
}

Image StickerSheet::render() const {

  unsigned w_ = 0;
  unsigned h_ = 0;
  for (unsigned i = 0; i < maxStickers; i++) {
    if (imageSheet[i] != nullptr) {
      w_ = (positionX[i] + imageSheet[i]->width() > baseSheet.width()) ? positionX[i] + imageSheet[i]->width() : baseSheet.width();
      h_ = (positionY[i] + imageSheet[i]->height() > baseSheet.height()) ? positionY[i] + imageSheet[i]->height() : baseSheet.height();
    }
  }

  if (w_ == 0 || h_ == 0) {
    return baseSheet;
  }

  Image returnImage(w_, h_);

  for (unsigned x = 0; x < w_; x++) {
    for (unsigned y = 0; y < h_; y++) {
      HSLAPixel & pixel = returnImage.getPixel(x, y);
      pixel = baseSheet.getPixel(x, y);
    }
  }

  for (unsigned i = 0; i < maxStickers; i++) {
    if (imageSheet[i] != nullptr) {
      for (unsigned x = 0; x < imageSheet[i]->width(); x++) {
        for (unsigned y = 0; y < imageSheet[i]->height(); y++) {
          HSLAPixel & basePixel = returnImage.getPixel(positionX[i] + x, positionY[i] + y);
          HSLAPixel & stickerPixel = imageSheet[i]->getPixel(x, y);
          if (stickerPixel.a != 0) {
            basePixel = stickerPixel;
          }
        }
      }
    }
  }
  return returnImage;
}
