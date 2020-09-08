//============================================================================
// Name        : TreeNode.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct TreeNode {
	string data;
	vector<TreeNode *> children;
	TreeNode(string data) {
		this->data = data;
	}
};

TreeNode* AddChild(TreeNode * ptr, string item);

void ListChildren(TreeNode * ptr);

void ListDescendants(TreeNode * ptr);

void RemoveChild(TreeNode * ptr, string item);

void RemoveAllChildren(TreeNode * ptr);

int main() {
	TreeNode * foods = new TreeNode("foods");
	TreeNode * desserts = AddChild(foods, "desserts");
	TreeNode * snacks = AddChild(foods, "snacks");
	TreeNode * entrees = AddChild(foods, "entrees");

	TreeNode * pie = AddChild(desserts, "pie");
	TreeNode * cake = AddChild(desserts, "cake");

	TreeNode * pumpkin = AddChild(pie, "pumpkin pie");
	TreeNode * apple = AddChild(pie, "apple pie");

	cout << "Children:\n";
	ListChildren(foods);
	cout << endl;
	cout << "Descendants:\n";
	ListDescendants(foods);

	cout << endl;
	cout << endl;

	RemoveChild(foods, "desserts");

	cout << "Children:\n";
	ListChildren(foods);
	cout << endl;
	cout << "Descendants:\n";
	ListDescendants(foods);
}

TreeNode* AddChild(TreeNode * ptr, string item) {
	TreeNode * newnode = new TreeNode(item);
	ptr->children.push_back(newnode);
	return newnode;
}

void ListChildren(TreeNode * ptr) {
	for (unsigned int i = 0; i < ptr->children.size(); i++) {
		cout << ptr->children[i]->data << endl;
	}
}

void ListDescendants(TreeNode * ptr) {
	for (unsigned int i = 0; i < ptr->children.size(); i++) {
		cout << ptr->children[i]->data << endl;
		ListDescendants(ptr->children[i]);
	}
}

void RemoveChild(TreeNode * ptr, string item) {
	/// remove child and all descendants
	for (unsigned int i = 0; i < ptr->children.size(); i++) {
		if (ptr->children[i]->data == item) {
			RemoveAllChildren(ptr->children[i]);
			delete ptr->children[i];
			ptr->children.erase(ptr->children.begin() + i);
			break;
		}
	}
}

void RemoveAllChildren(TreeNode * ptr) {
	for (unsigned int i = 0; i < ptr->children.size(); i++) {
		RemoveAllChildren(ptr->children[i]);
		delete ptr->children[i];
	}
	ptr->children.clear();
}
