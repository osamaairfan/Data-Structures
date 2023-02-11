#include <iostream>
#include <vector>
using namespace std;

const int V = 4;

class Graph {
public:
	void addEdge(vector<int> graph[], int source, int destination) {
		graph[source].push_back(destination);
		graph[destination].push_back(source);
	}

	void DFS(vector<int> graph[], vector<bool> &visited, int currentNode) {
		cout << currentNode << endl;

		visited[currentNode] = true;      // Mark the Node true which has been visited

		for (int neighbour : graph[currentNode]) {
			if (!visited[neighbour]) {
				DFS(graph, visited, neighbour);        //Recursively calling DFS to visit the unvisited 
			}										   //neighbours
		}
	}

};

int main() {
	//Declares adjacency list
	vector<int> graph[V];

	Graph g1;
	g1.addEdge(graph, 0, 1);
	g1.addEdge(graph, 0, 2);
	g1.addEdge(graph, 0, 3); 
	g1.addEdge(graph, 1, 2);

	vector<bool> visited(V, false); //Initially mark every Node false

	cout << "DFS Search: " << endl;
	int currentNode = 2;            //Node to start traversal from    
	g1.DFS(graph, visited, currentNode);
}