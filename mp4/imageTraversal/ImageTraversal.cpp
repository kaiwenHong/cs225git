#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_ = nullptr;
  current_ = Point(0, 0);
}

ImageTraversal::Iterator::Iterator(ImageTraversal * traversal, Point & start, double & tolerance, PNG & image) {
  traversal_ = traversal;
  start_ = start;
  tolerance_ = tolerance;
  image_ = image;
  current_ = traversal_->peek();
  visited.resize(image.width() * image.height(), false);
}

bool ImageTraversal::Iterator::isVisited(const Point & currPoint) const {
  return visited[currPoint.x + currPoint.y * image_.width()];
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if (!traversal_->empty()) {
    traversal_->pop();
    visited[current_.x + current_.y * image_.width()] = true;

    Point right_ = Point(current_.x + 1, current_.y);
    Point below_ = Point(current_.x, current_.y + 1);
    Point left_ = Point(current_.x - 1, current_.y);
    Point above_ = Point(current_.x, current_.y - 1);

    while (!traversal_->empty() && isVisited(Point(traversal_->peek().x, traversal_->peek().y))) current_ = traversal_->pop();

    if (right_.x < image_.width() && right_.y < image_.height()) {
      if (calculateDelta(image_.getPixel(right_.x, right_.y), image_.getPixel(start_.x, start_.y)) <= tolerance_ && !isVisited(right_)) {
        traversal_->add(right_);
      }
    }
    if (below_.x < image_.width() && below_.y < image_.height()) {
      if (calculateDelta(image_.getPixel(below_.x, below_.y), image_.getPixel(start_.x, start_.y)) <= tolerance_ && !isVisited(below_)) {
        traversal_->add(below_);
      }
    }
    if (left_.x < image_.width() && left_.y < image_.height()) {
      if (calculateDelta(image_.getPixel(left_.x, left_.y), image_.getPixel(start_.x, start_.y)) <= tolerance_ && !isVisited(left_)) {
        traversal_->add(left_);
      }
    }
    if (above_.x < image_.width() && above_.y < image_.height()) {
      if (calculateDelta(image_.getPixel(above_.x, above_.y), image_.getPixel(start_.x, start_.y)) <= tolerance_ && !isVisited(above_)) {
        traversal_->add(above_);
      }
    }
    if (!traversal_->empty()) current_ = traversal_->peek();
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal_ == nullptr) thisEmpty = true;
  if (other.traversal_ == nullptr) otherEmpty = true;

  if (!thisEmpty) thisEmpty = traversal_->empty();
  if (!otherEmpty) otherEmpty = other.traversal_->empty();

  if (thisEmpty && otherEmpty) return false;

  return true;

}
