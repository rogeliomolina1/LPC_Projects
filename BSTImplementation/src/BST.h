/*
 * BST.h
 *
 *  Created on: Nov 17, 2016
 *      Author: rogel
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
using namespace std;

template<typename T>
struct BSTNode {
	T key;
	BSTNode<T> * left;
	BSTNode<T> * right;
	BSTNode(T key) {
		this->key = key;
		left = right = NULL;
	}
	bool IsLeaf() {
		///return !left && !right;
		return !left && !right;
	}
	bool OnlyHasLeftChild() {
		return !right;
	}

	bool OnlyHasRightChild() {
		return !left;
	}

	void SetChildPointer(bool setLeftSide, BSTNode<T> * newValue) {
		/// Set either the left or right pointer to the given newValue.
		if (setLeftSide) {
			left = newValue;
		} else {
			right = newValue;
		}

	}
};

template<typename T>
class BST {
private:
	BSTNode<T> * root;
	BSTNode<T> * FindNode(BSTNode<T> * p, T key) {
		/// **RECURSIVELY** search for node matching the given key,
		/// starting with the node pointed to by p.
		/// THIS SHOULD BE A PRIVATE METHOD.
		if (p == NULL) {
			return NULL;
		}
		if (p->key == key) {
			return p;
		}
		if (key < p->key) {
			return FindNode(p->left, key);
		}
		if (key > p->key) {
			return FindNode(p->right, key);
		} else
			return NULL;

	}
	void InsertNode(BSTNode<T> * p, T key) {
		/// **RECURSIVELY** insert a new node with the given key into the correct position
		/// in the tree.
		BSTNode<T> * newNode = new BSTNode<T>(key);
		if (root == NULL) {
			/// The tree is empty,
			///  so install the newNode at the root
			root = newNode;
		} else if (p == NULL) {
			p = newNode;
		} else {
			if (key < p->key) {
				if (p->left == NULL) {
					p->left = newNode;
					return;
				} else {
					InsertNode(p->left, key);
				}
			} else {
				if (p->right == NULL) {
					p->right = newNode;
					return;
				} else {
					InsertNode(p->right, key);
				}
			}
		}
	}
	BSTNode<T> * RemoveLargestDescendant(BSTNode<T> * p) {
		/// Find the largest descendant of p,
		/// then remove it (but DO NOT deallocate it) and return a pointer to it.
		/// THIS SHOULD BE A PRIVATE METHOD.
		BSTNode<T> * temp = p;
		if (p == NULL)
			return NULL;
		if (p->right != NULL) {
			if (p->right->right == NULL) {
				temp = p->right;
				p->right = p->right->left;
				return temp;
			} else {
				return RemoveLargestDescendant(p->right);
			}
		}
		if (p->left != NULL) {
			if (p->left->right == NULL) {
				temp = p->left;
				p->left = p->left->left;
				return temp;
			} else {
				return RemoveLargestDescendant(p->left);
			}
		}
		return NULL;

	}
	void TraverseTree(BSTNode<T> * p) {
		/// **RECURSIVELY** use in-order traversal to print out the keys in the tree.
		if (p == NULL)
			return;
		TraverseTree(p->left);
		cout << p->key << endl;
		TraverseTree(p->right);
	}
public:
	BST() {
		root = NULL;
	}
	void PrintAll() {
		/// Call TraverseTree using the root of the tree
		TraverseTree(root);
	}

	BSTNode<T> * Find(T key) {
		/// Call FindNode using the root of the tree.
		return FindNode(root, key);
	}
	BSTNode<T> * ParentNode(BSTNode<T> * pRoot, T key) {
		if (pRoot == NULL)
			return NULL;

		if (pRoot->left == NULL && pRoot->right == NULL)
			return NULL;

		if ((pRoot->left != NULL && pRoot->left->key == key)
				|| (pRoot->right != NULL && pRoot->right->key == key))
			return pRoot;

		if (pRoot->key > key)
			return ParentNode(pRoot->left, key);

		if (pRoot->key < key)
			return ParentNode(pRoot->right, key);

		return NULL;
	}
	void Insert(T key) {
		/// Call InsertNode using the root of the tree.
		InsertNode(root, key);

	}
	BSTNode<T> * RemoveLargestValue() {
		/// Call RemoveLargestDescendant() using the root of the tree.
		return RemoveLargestDescendant(root);
	}
	void Remove(T key) {
		if (FindNode(root, key) == NULL) {
			return;
		}
		BSTNode<T>*victim = FindNode(root, key);
		BSTNode<T>*parent = ParentNode(root, key);
		if (victim != root) {
			///Case A: The victim has only one child or no children
			if (victim->right == NULL) {

				///make parent point to child of victim
				if (key > parent->key) {
					parent->right = victim->left;
				} else if (key < parent->key) {
					parent->left = victim->left;
				}
				victim->left = NULL;
				delete victim;
				return;
			}
			if (victim->left == NULL) {

				///make parent point to child of victim
				if (key > parent->key) {
					parent->right = victim->right;
				} else if (key < parent->key) {
					parent->left = victim->right;
				}
				victim->right = NULL;
				delete victim;
				return;
			}
			if (victim->left == NULL && victim->right == NULL) {

				//make parent point to NULL instead of victim
				if (key > parent->key) {
					parent->right = NULL;
				} else if (key < parent->key) {
					parent->left = NULL;
				}
				delete victim;
				return;
			}

			///Case B: The victim has two children

			if (victim->left != NULL && victim->right != NULL) {
				BSTNode<T> *leftsubtree = victim;
				BSTNode<T> *tempright = victim->right;
				leftsubtree->right = NULL;
				BSTNode<T> *temp = RemoveLargestDescendant(leftsubtree);
				temp->left = victim->left;
				temp->right = tempright;
				if (key > parent->key) {
					parent->right = temp;
				} else if (key < parent->key) {
					parent->left = temp;
				}
				victim->left = NULL;
				victim->right = NULL;
				delete victim;
				return;
			}
		}
		if (victim == root) {

			///Case C: The node being removed is the root so it has not parent
			if (victim->right == NULL) {
				root = victim->left;
				victim->left = NULL;
				delete victim;
				return;
			} else if (victim->left == NULL) {
				root = victim->right;
				victim->right = NULL;
				delete victim;
				return;
			} else if (victim->left == NULL && victim->right == NULL) {
				root = NULL;
				delete victim;
				return;
			} else if (victim->left != NULL && victim->right != NULL) {
				BSTNode<T> *leftsubtree = victim;
				BSTNode<T> *tempright = victim->right;
				leftsubtree->right = NULL;
				BSTNode<T> *temp = RemoveLargestDescendant(leftsubtree);
				temp->left = victim->left;
				temp->right = tempright;
				root = temp;
				victim->left = NULL;
				victim->right = NULL;
				delete victim;
				return;
			}
		}
	}
};

#endif /* BST_H_ */
