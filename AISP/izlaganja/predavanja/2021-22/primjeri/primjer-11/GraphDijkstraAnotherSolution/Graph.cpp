#include <iostream>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <string>
#include <new> // nothrow
#include <utility> // std::pair

#include "List.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

void Graph::print() {
	List<Vertex>::iterator i;
	cout << "\nGraph: " << endl;
	for (i = vertices.begin(); i != vertices.end(); i++) {
		cout << i->name << ": "; // prints name, since operator<< is overloaded
		for (auto j : i->neighbors) {
			cout << "(" << i->name << ", " << j->first->name << ") = " << j->second << "\t";
		}
		cout << "\n";      
	}
	cout << endl;
}

// debug functions - start
template<typename T>
void printQueue(T q) {
	std::cout << "Priority queue:\n";
	for (auto i : q) std::cout << "(" << i.first->name << ", " << i.second << ") ";
	std::cout << endl;
}
// debug functions - end


// Dijkstra's algorithm: find the shortest path from the starting vertex to all other vertices in the graph
// For each vertex: print the shortest path + the total distance from the starting vertex
void Graph::Dijkstra(Vertex& start) {
   
	// lambda
	auto CustomCompare = [](const pair<Vertex*, dist_t>& lhs, const pair<Vertex*, dist_t>& rhs) { return lhs.second > rhs.second; };
	// an alternative: a function CustomCompare
	//bool CustomCompare(const pair<Vertex*, dist_t>& lhs, const pair<Vertex*, dist_t>& rhs) { return lhs.second > rhs.second; };

	unordered_map<string, dist_t> distances; // later change string to Vertex to be consistent?? ; (name, dist)
	unordered_map<string, string> paths; // (name, path)

	// (1) initialize all distances to infinity (i.e. max value), except for the starting vertex
	for (auto v : vertices) {
		if (v->name == start.name) { // start node
			distances[v->name] = 0;
			v->visited = true;
			paths[v->name] = v->name; // storing the complete shortest path, not just the previous vertex
		}
		else { // all other vertices: the distances are initally set to infinity (here: max int)
			distances[v->name] = numeric_limits<float>::max();
		}
	}
      
	// (2) find the minimal distance from the current node to all its neighbors (using minheap)
	vector<pair<Vertex*, dist_t>> priorityQueue; // the container for the priority queue will be vector
	for (auto v : vertices) {
		priorityQueue.push_back({ v, distances[v->name] });
	}
	make_heap(priorityQueue.begin(), priorityQueue.end(), CustomCompare);
	printQueue(priorityQueue);
   
	while (!priorityQueue.empty()) {
		// find the vertex with the minimal distance
		pop_heap(priorityQueue.begin(), priorityQueue.end()); // // moves the smallest to the end
		pair<Vertex*, dist_t> next = priorityQueue.back(); // gets the smallest element
		priorityQueue.pop_back();  // actually removes the largest element
		Vertex *v = next.first;
		v->visited = true;

		for (auto n: v->neighbors) { 
			// check unvisited vertices
			Vertex *vNew = (*n).first;
			if (!vNew->visited) {
				if (distances[vNew->name] > distances[v->name] + (*n).second) { // update distances
					distances[vNew->name] = distances[v->name] + (*n).second;
					paths[vNew->name] = paths[v->name] + " --> " + vNew->name;
				}
			}			
		}
		// update distances in the priority queue
		for (auto& el : priorityQueue) {
			el.second = distances[el.first->name];
		}
		make_heap(priorityQueue.begin(), priorityQueue.end(), CustomCompare);
		printQueue(priorityQueue);
	}

	// (3) print results: the shortest paths to all vertices and the total distances
	cout << "\nShortest paths:\n";
	for (auto& d : distances) {
		cout << d.first << " >> " << paths[d.first] << " (" << d.second << ")\n";
	}
	cout << endl;	
}

