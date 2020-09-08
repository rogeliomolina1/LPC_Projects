//============================================================================
// Name        : GraphImplementation.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Node;

struct Edge {
	double cost;  /// sometimes called "weight"
	Node * start;
	Node * ending;
};

struct Node {
	string name;
	set<Edge *> edges;
};

class Graph {
private:
	map<string, Node *> nodeMap;

public:
	bool FindPath(string origin, string destination) {
		Node* src = FindNode(origin);
		Node*dst = FindNode(destination);
		if (src == NULL || dst == NULL) {
			cout << "FindPath fail. Nonexistent node." << endl;
			return false;
		}
		set<Node*> visited;

		return (DFS(src, dst, visited));
	}

	void AddNode(string name) {
		Node * newNode = new Node;
		newNode->name = name;
		nodeMap[name] = newNode;
	}

	void AddEdge(string endpoint1, string endpoint2, double cost) {
		Node * node1 = FindNode(endpoint1);
		Node * node2 = FindNode(endpoint2);
		if (node1 == NULL || node2 == NULL) {
			cout << "AddEdge fail. Nonexistent node." << endl;
			return;
		}
		Edge * edge1 = new Edge;
		Edge * edge2 = new Edge;

		edge1->start = node1;
		edge1->ending = node2;

		edge2->start = node2;
		edge2->ending = node1;

		edge1->cost = cost;
		edge2->cost = cost;

		node1->edges.insert(edge1);
		node2->edges.insert(edge2);
	}
	void ListNeighbors(string name) {
		Node * node = FindNode(name);
		if (node == NULL) {
			cout << "ListNeighbors fail. Nonexistent node." << endl;
			return;
		}

		cout << name << " connects to: " << endl;
		for (set<Edge *>::iterator iter = node->edges.begin();
				iter != node->edges.end(); iter++) {
			Edge * e = (*iter);
			cout << "   " << e->ending->name << " (cost = " << e->cost << ")\n";
		}

	}

private:
	bool DFS(Node * n, Node * target, set<Node *> & visited) {
		cout << n->name << endl;
		if (n == target)
			return true;
		visited.insert(n);
		for (set<Edge *>::iterator iter = n->edges.begin();
				iter != n->edges.end(); iter++) {
			Node * otherEnd = (*iter)->ending;
			if (visited.find(otherEnd) == visited.end()) {
				if (DFS(otherEnd, target, visited) == true)
					return true;
			} else {
				cout << "Can't go to " << otherEnd->name << ", already tried. "
						<< endl;
			}
		}
		return false;
	}

	Node* FindNode(string name) {
		if (nodeMap.find(name) == nodeMap.end())
			return NULL;

		return nodeMap[name];
	}
};

int main() {
	Graph travel;

	travel.AddNode("Seattle");
	travel.AddNode("SF");
	travel.AddNode("LA");
	travel.AddNode("Livermore");
	travel.AddNode("Reno");
	travel.AddNode("Park City");
	travel.AddNode("Pheonix");

	travel.AddEdge("Seattle", "SF", 807);
	travel.AddEdge("Seattle", "Reno", 573);
	travel.AddEdge("SF", "Reno", 170);
	travel.AddEdge("SF", "Livermore", 36);
	travel.AddEdge("SF", "LA", 347);
	travel.AddEdge("LA", "Reno", 392);
	travel.AddEdge("Park City", "Pheonix", 497);

	cout << travel.FindPath("Seattle", "LA") << endl;
	cout << travel.FindPath("SF", "Park City") << endl;

	travel.ListNeighbors("LA");

	return 0;
}
