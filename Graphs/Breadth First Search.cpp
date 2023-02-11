#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int V = 8;  //Vertices
//Method: Array of Vectors - vector<int> graph[V]

class Graph {
public:

	void addEdge(vector<int> graph[V], int source, int destination) {
		graph[source].push_back(destination);
		graph[destination].push_back(source);
	}

	void BFS(vector<int> graph[V], vector<bool> &visited, int currentNode) {
		queue<int> q;
		q.push(currentNode);            //Push the initial Node into the Queue
		visited[currentNode] = true;    //Mark the Node true which has been visited

		while (!q.empty()) {
			currentNode = q.front();       //To take out the front element of the queue
			q.pop();                            //Also Dequeue that element so that it won't be repeated

			cout << currentNode << " ";
			
			for (int neighbour : graph[currentNode]) {
				if (!visited[neighbour]) {            //If the neighbour is not visited push that
					q.push(neighbour);				  //into queue
				}
				visited[neighbour] = true;         //Mark the neighbour Node which has been visited
			}
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
	g1.addEdge(graph, 2, 4);
	g1.addEdge(graph, 2, 5);
	g1.addEdge(graph, 3, 6);
	g1.addEdge(graph, 7, 6);

	vector<bool> visited(V, false);    //Initailly mark the nodes false

	cout << "BFS: " << endl;
	int currentNode = 0;
	g1.BFS(graph, visited, currentNode);
}
