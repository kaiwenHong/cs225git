/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <math.h>
#include "kdtree.h"

using namespace std;

/**
* smallerDimVal returns whether the first point is smaller than the second point with respect to the given dimension.
* In the case of a tie, use the provided operator< from the Point class to break it.
**/
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const {
    /**
     * @todo Implement this function!
     */
    if (first[curDim] < second[curDim]) return true; // compare dimensions
    if (first[curDim] > second[curDim]) return false;
    return (first < second); // Use operator< if there's a tie
}

/**
* shouldReplace returns whether a potential point should replace the currentBest point as the closest point.
* First, calculate and compare the distances from currentBest to target and potential to target.
* Again, in the case of a tie, use operator< to break it.
**/
template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const {
    /**
     * @todo Implement this function!
     */
     double currentDistance = 0.0;
     double potentialDistance = 0.0;
     for (int i = 0; i < Dim; i++) { // calculate distances
       currentDistance += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
       potentialDistance += (potential[i] - target[i]) * (potential[i] - target[i]);
     }
     if (potentialDistance < currentDistance) return true; // see whether potential is closer
     if (potentialDistance > currentDistance) return false;
     return (potential < currentBest); // use operator< to break tie
}

/**
* The KDTree constructor makes a kd-tree based on the provided points.
* We push all newPoints to private helper instance variable points, then call helper functions.
**/
template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints) {
    /**
     * @todo Implement this function!
     */
     for (size_t i = 0; i < newPoints.size(); i++) { // initialize helper variable points
       points.push_back(newPoints[i]);
     }
     root = makeTree(0, newPoints.size() - 1, 0);
}

/**
* makeTree is a helper function that uses the quickselect algorithm to rearrange points and find the median.
* A new subroot node is created with the point at the calculated median.
* Then, we recurse to make the left and right subtrees.
**/
template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::makeTree(int left, int right, int dimension) {
     if (right < left) return nullptr; // returns after leaf node
     int median = (left + right) / 2;
     select(left, right, median, dimension); // quickselect on points vector to find the median
     // points[median] is now median, new subroot and create left/right subtrees in next dimension
     KDTreeNode *subroot = new KDTreeNode(points[median]);
     subroot->left = makeTree(left, median - 1, (dimension + 1) % Dim);
     subroot->right = makeTree(median + 1, right, (dimension + 1) % Dim);
     return subroot;
}

/**
* swap is a helper function that swaps 2 points in a vector, just in case the std library is not allowed.
**/
template <int Dim>
void KDTree<Dim>::swap(int index1, int index2) {
	   Point<Dim> temp = points[index1];
	   points[index1] = points[index2];
	   points[index2] = temp;
}

/**
* partition is a helper function for the quickselect algorithm.
* More details can be found on Wikipedia, but some comments are provided here to demonstrate mastery.
**/
template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int dimension) {
     Point<Dim> pivotValue = points[pivotIndex];
     swap(pivotIndex, right); // move the pivot to the right
     int storeIndex = left;
     // iterate and if current point is smaller than pivot with respect to current dimension, move to left
     for (int i = left; i < right; i++) {
	      if (smallerDimVal(points[i] , pivotValue, dimension)) {
	         swap(storeIndex, i);
           storeIndex += 1;
        }
	   }
     swap(right, storeIndex); // move pivot to proper position
     return storeIndex; // return the new location of the pivot
}

/**
* select is the quickselect algorithm used in makeTree.
* More details can be found on Wikipedia, but some comments are provided here to demonstrate mastery.
**/
template <int Dim>
void KDTree<Dim>::select(int left, int right, int k, int dimension) {
     if (right < left) return;
     int pivotIndex = (left + right) / 2; // choose the middle of the range to use as pivot
     int newIndex = partition(left, right, pivotIndex, dimension); // move pivot to proper position
     // compare pivot (in proper position) to the median (k) we want to find; recurse if not found yet
     if (k == newIndex) return;
     else if (k < newIndex) select(left, newIndex - 1, k, dimension); // if pivot is larger, recurse left
     else select(newIndex + 1, right, k, dimension); // if pivot is smaller, recurse right
}

/**
* KDTree copy constructor copies over the points, then makes the tree with the given points.
**/
template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   points = other.points;
   root = makeTree(root, 0, points.size() - 1, 0);
}

/**
* KDTree operator= deletes this, then copies over the contents with the copy constructor
**/
template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
    if(this != &rhs){
      delete *this;
      this = new KDTree(rhs);
    }
    return *this;
}

/**
* clean is a helper function that frees up all the dynamically-allocated nodes in a tree
**/
template <int Dim>
void KDTree<Dim>::clean(KDTreeNode *subroot) {
    if (!subroot) return;
    clean(subroot->left);
    clean(subroot->right);
    delete subroot;
}

/**
* KDTree destructor frees all memory associated with the tree by calling the clean helper function.
**/
template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   clean(root);
}

/**
* distance is a helper function that calculates the distance between two points.
**/
template <int Dim>
double KDTree<Dim>::distance(const Point<Dim>& first, const Point<Dim>& second) const {
    double currentDistance = 0.0;
    for (int i = 0; i < Dim; i++) currentDistance += (first[i] - second[i]) * (first[i] - second[i]);
    return currentDistance;
}

/**
* findNearestNeighbor finds the nearest neighbor to the passed-in point.
* It calls a helper function that takes in more parameters to allow for easier recursion.
**/
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const {
    /**
     * @todo Implement this function!
     */
     return findNearest(root, query, root->point, 0);
}

/**
* findNearest is a recursive function that finds the nearest neighbor to target.
* We first recurse to a leaf node, the backtraverse to find the closest point.
**/
template <int Dim>
Point<Dim> KDTree<Dim>::findNearest(KDTreeNode *subroot, const Point<Dim> target, Point<Dim> currentBest, int dimension) const {
    if (!subroot->left && !subroot->right) return subroot->point; // return if leaf node
    bool searchLeft = false; // flag to indicate which direction we went in
    // if target < point, recurse left with next dimension
    if (smallerDimVal(target, subroot->point, dimension)) {
      if (subroot->left) {
        currentBest = findNearest(subroot->left, target, currentBest, (dimension + 1) % Dim);
        searchLeft = true;
      }
      else {
        currentBest = findNearest(subroot->right, target, currentBest, (dimension + 1) % Dim);
      }
    }
    // if target > point, recurse right with next dimension
    else {
      if (subroot->right) currentBest = findNearest(subroot->right, target, currentBest, (dimension + 1) % Dim);
      else{
        currentBest = findNearest(subroot->left, target, currentBest, (dimension + 1) % Dim);
        searchLeft = true;
      }
    }

    /* BACKTRAVERSAL */
    // Check if the current point we're on is closer than previous nearest of opposite direction-nearest
    if (shouldReplace(target, currentBest, subroot->point)) currentBest = subroot->point;
    double currentDistance = distance(target, currentBest); // radius of the hypersphere
    // 1D-distance of current plane (radius of splitting-plane)
    double splitting = ((subroot->point)[dimension] - target[dimension]) * ((subroot->point)[dimension] - target[dimension]);
    // If current splitting-plane's distance is within radius, look for closer points in opposite direction
    if (splitting <= currentDistance) {
      if (searchLeft) {
        if (subroot->right) {
          Point<Dim> nearest = findNearest(subroot->right, target, currentBest, (dimension + 1) % Dim);
          if (shouldReplace(target, currentBest, nearest)) currentBest = nearest;
        }
      }
      else {
        if (subroot->left) {
          Point<Dim> nearest = findNearest(subroot->left, target, currentBest, (dimension + 1) % Dim);
          if (shouldReplace(target, currentBest, nearest)) currentBest = nearest;
        }
      }
    }
    return currentBest;
}
