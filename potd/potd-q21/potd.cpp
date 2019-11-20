#include "potd.h"
#include <algorithm>

using namespace std;

/** Returns the sum of elements between start to end.
	The value at start is included, while the value at end is not.
	*/
double sum(vector<double>::iterator start, vector<double>::iterator end) {
  double count = 0;
  for (vector<double>::iterator it = start ; it != end; ++it) {
    count += *it;
  }
  return count;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
  vector<double>::iterator max = start;
  for (vector<double>::iterator it = start ; it != end; ++it) {
    if (*it > *max) max = it;
  }
  return max;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
  for (vector<double>::iterator it = start ; it != end; ++it) {
    iter_swap(it, max_iter(it, end));
  }
}
