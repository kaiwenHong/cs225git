/* Your code here! */
#pragma once

#include <vector>
using std::vector;

class DisjointSets{
	public:
		/**
		* addElements creates n unconnected root nodes at the end of the vector
		*
		* @param num the number of elements to add
		**/
		void addelements(int num);
		/**
		* find returns the root of the uptree that an element is in
		* elem is inside an uptree, and find returns the root of that uptree
		*
		* @param elem the index whose uptree-root you want to find
		* @return index of the root of the uptree that elem is in
		**/
		int find(int elem);
		/**
		* setUnion merges two disjoint sets by size
		* The smaller set is put inside of the larger set (so the smaller set points to the larger)
		* In the case of a tie, the second set passed in points to the first
		*
		* @param a the index of the first element whose set will be merged
		* @param b the index of the second element whose set will be merged
		**/
		void setunion(int a, int b);
		/**
		* size returns the size of the uptree containing an element
		*
		* @param elem the index whose uptree-size you want to find
		* @return number of nodes in the uptree that elem is in
		**/
		int size(int elem);
	private:
		vector<int> elements;
};
