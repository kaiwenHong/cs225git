#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>
using std::unordered_map;
using std::list;
using std::string;
/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::size() const {
  // TODO: Part 2
	// number of entries in dictionary
	return vertexMap.size();
}


/**
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
	// number of elements in entry in adjacency list
	return adjList.at(v.key()).size();
}


/**
* Inserts a Vertex into the Graph by adding it to the Vertex map and adjacency list
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
	V & v = *(new V(key));
	vertexMap.insert( {key, v} ); // add to vertex map
	adjList.insert({key, std::list<edgeListIter>()}); // add to list
	return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
	// remove incident edges
	for(auto e : adjList.at(key)){
		// *e = value at iterator - edgeref | (*e).get = edge
		string dest = (*e).get().dest().key();
		// to account for undirected edges
		if(dest == key) dest = (*e).get().source().key(); // undirected
		if(isAdjacent(dest, key)){ // if destination adj source
			// i = iterator to iterator list | *i = iterator | **i = value at iterator (edgeref)
			auto i = adjList.at(dest).begin();
			while((**i).get().dest().key() != key && (**i).get().source().key() != key){ 
				// look for adj edge to key
				i++;
			}
			if(typeid(E) != typeid(Edge)) edgeList.erase(*i);
			adjList.at(dest).erase(i); // remove from adj list
		}
		edgeList.erase(e); // remove from edge list
	}

	if(typeid(E) != typeid(Edge)){
		auto e = edgeList.begin();
		while(e != edgeList.end() && !edgeList.empty()){
			// *e = value at iterator - edgeref | (*e).get = edge
			if((*e).get().source().key() == key || (*e).get().dest().key() == key){
				removeEdge(e);
			}
			e++;
		}
	} 

	while(!adjList.at(key).empty())
		adjList.at(key).erase(adjList.at(key).begin()); // delete adj list
	vertexMap.erase(key); // remove vertex
}


/**
* Inserts an Edge into the adjacency list
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
	E & e = *(new E(v1, v2));
	// Rahul said you can push directly he better be right
	edgeList.push_front(e); // insert to front of edge list
	adjList.at(v1.key()).push_front(edgeList.begin()); // since we know new edge is first
	if(typeid(E) == typeid(Edge)) adjList.at(v2.key()).push_front(edgeList.begin()); // if undirected
	return e;
}


/**
* Removes an Edge from the Graph
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {  
  // TODO: Part 2
	for(auto e = edgeList.begin(); e != edgeList.end(); e++){
		// find and remove from edge list
		// e is iterator to edgeRef | *e is edgeref | (*e).get = edge
		bool undir = (*e).get().dest().key() == key1 && (*e).get().source().key() == key2;
		undir = undir && typeid(E) == typeid(Edge);
		if(((*e).get().source().key() == key1 && (*e).get().dest().key() == key2) || undir){
			// find and remove from adj list
			for(auto a = adjList.at(key1).begin(); a != adjList.at(key1).end(); a++){
				if((**a).get().dest().key() == key2 || (**a).get().source().key() == key2){
					adjList.at(key1).erase(a);
					break;
				}
			}
			// undirected
			if(isAdjacent(key2, key1) && typeid(E) == typeid(Edge)){
				for(auto a = adjList.at(key2).begin(); a != adjList.at(key2).end(); a++){
					if((**a).get().dest().key() == key1 || (**a).get().source().key() == key1){
						adjList.at(key2).erase(a);
						break;
					}
				}
			}
			edgeList.erase(e);
			break;
		}
	}
}


/**
* Removes an Edge from the adjacency list at the location of the given iterator
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
	string key1 = (*it).get().source().key();
	string key2 = (*it).get().dest().key();
	for(auto a = adjList.at(key1).begin(); a != adjList.at(key1).end(); a++){
		if((**a).get().dest().key() == key2 || (**a).get().source().key() == key2){
			adjList.at(key1).erase(a);
			break;
		}
	}
	// undirected
	if(isAdjacent(key2, key1)){
		for(auto a = adjList.at(key2).begin(); a != adjList.at(key2).end(); a++){
			if((**a).get().dest().key() == key1 || (**a).get().source().key() == key1){
				adjList.at(key2).erase(a);
				break;
			}
		}
	}
	edgeList.erase(it);
}


/**
* @param key The key of an arbitrary Vertex "v"
* @return The list edges (by reference) that are adjacent to "v"
*/
template <class V, class E>  
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
	std::list<std::reference_wrapper<E>> edges;
	for(auto i : adjList.at(key)){ // adjList = all outbound edges (key is source)
		edges.push_back((*i)); // *i = value of iterator (edgeref)
	}
	return edges;
}


/**
* Return whether the two vertices are adjacent to one another
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
	for(auto i : adjList.at(key1)){ // adjacent = key1 (source) to key2 (dest) exists
		if((*i).get().dest().key() == key2) return true;
		if(typeid(E) == typeid(Edge) && (*i).get().source().key() == key2) return true;
	}
	return false;
}
