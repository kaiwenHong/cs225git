#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using std::unordered_map;
using std::vector;
using std::queue;
#include <iostream>
/**
 * Returns an std::list of vertex keys that creates some shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
	std::list<std::string> path;

	// no Dijkstra :(
	// initialization
	queue<string> q;
	unordered_map<string, bool> labels; // {vertex, flag}
	unordered_map<string, string> prev; // {vertex, previous vertex}
	labels[start] = true;
	q.push(start);
	while(!q.empty()){
		string v = q.front();
		q.pop();
		for(auto e : incidentEdges(v)){
			string w = e.get().dest().key();
			string source = e.get().source().key(); // something else is the source of adj
			if(labels.find(w) == labels.end()){ // unexplored
				labels[w] = true; // set to explored (discovery)
				prev[w] = v; // keep track of previous
				q.push(w); // add to queue
			}
			if(isAdjacent(source, v) && labels.find(source) == labels.end()){ // undirected
				labels[source] = true; // set to explored (discovery)
				prev[source] = v; // keep track of previous
				q.push(source); // add to queue
			}
			if(labels.find(end) != labels.end()){ // reached end vertex
				path.push_front(end); // add to path in reverse order
				string p = prev.at(end);
				while(p != start){
					path.push_front(p);
					p = prev.at(p);
				}
				path.push_front(start);
				return path;
			}

		}
	}
	return path;
}
