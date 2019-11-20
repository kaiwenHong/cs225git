/* Your code here! */
#include "dsets.h"
#include <iostream>
using std::cout;
using std::endl;

void DisjointSets::addelements(int num) {
	for (int i = 0; i < num; i++) {
		elements.push_back(-1); // initialize as -1
	}
}

int DisjointSets::find(int elem) {
	if (elements[elem] < 0) return elem; // base case - reach a negative number/root
	else {
		int root = find(elements[elem]); // go up the uptree to find root
		elements[elem] = root; // path compression
		return root;
	}
}

void DisjointSets::setunion(int a, int b) {
	int root1 = find(a); // find the roots of the indices passed in
	int root2 = find(b);
	if (root1 == root2) return; // do nothing already in same union
	int newSize = elements[root1] + elements[root2];
	if (elements[root1] <= elements[root2]) { // if first is larger or same size...
		elements[root2] = root1; // have second tree point to first
		elements[root1] = newSize; // first is now bigger
	} else { // if second is larger
		elements[root1] = root2; // have first point to second
		elements[root2] = newSize; // second is now bigger
	}
}

int DisjointSets::size(int elem) {
	return -elements[find(elem)]; // root index contains negative size
}
