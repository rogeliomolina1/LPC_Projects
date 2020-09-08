//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
//#include "lexicon.h"
using namespace std;

template<typename T>
struct BSTNode {
	T data;
	BSTNode<T> * left;
	BSTNode<T> * right;
	BSTNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

template<typename T>
class BST {
private:
	BSTNode<T> * root;
public:
	BST() {
		root = NULL;
	}

	void ShowTree(BSTNode<T> * ptr) {
		if (ptr != NULL) {
			cout << ptr->data << endl;
			ShowTree(ptr->left);
			ShowTree(ptr->right);
		}
	}

	void Print() {
		ShowTree(root);
	}

	void Insert(T key) {
		BSTNode<T> * newNode = new BSTNode<T>(key);

		if (root == NULL) {
			/// The tree is empty,
			///  so install the newNode at the root
			root = newNode;
		} else {
			BSTNode<T> * current = root;
			while (true) {
				if (key < current->data) {
					if (current->left == NULL) {
						current->left = newNode;
						return;
					} else
						current = current->left;
				} else {
					if (current->right == NULL) {
						current->right = newNode;
						return;
					} else
						current = current->right;
				}
			}
		}
	}

	BSTNode<T> * Find(T key) {
		BSTNode<T> * current = root;
		while (true) {
			if (current == NULL)
				return NULL;
			if (current->data == key)
				return current;
			if (key < current->data)
				current = current->left;
			else
				current = current->right;
		}
	}

	void Remove(T key) {
		/// DANGER
		/// HIGH VOLTAGE
	}

};

int main() {
	BST<string> people;

	people.Insert("Carl");
	people.Insert("Daniel");
	people.Insert("Bob");
	people.Insert("Carly");
	people.Insert("Elena");

	people.Print();

	while (true) {
		string who;
		cout << "Who to find? ";
		getline(cin, who);
		if (people.Find(who) == NULL)
			cout << "Nope!" << endl;
		else
			cout << "Ok, found " << people.Find(who)->data << endl;
	}

	return 0;
}
