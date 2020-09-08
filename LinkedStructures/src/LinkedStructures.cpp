//============================================================================
// Name        : LinkedStructures.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
struct ListNode {
	T data;
	ListNode<T> * next;

	ListNode() {
		data = T();
		next = NULL;
	}
};

template<typename T>
class LinkedList {
private:
	ListNode<T> * head;

public:
	LinkedList() {
		head = new ListNode<T>;
	}

	void InsertFront(T item) {
		ListNode<T> * newNode = new ListNode<T>;
		newNode->data = item;
		newNode->next = head->next;
		head->next = newNode;
	}

	void Print() const {
		ListNode<T> * current = head->next;
		while (current != NULL) {
			cout << current->data << endl;
			current = current->next;
		}

	}

	T Get(int i) const {
		ListNode<T> * current = head->next;
		if (current == NULL) {
			cout << "*** Fatal error: List is empty" << endl;
			exit(-1);
		}

		for (int k = 0; k < i; k++) {
			if (current->next == NULL) {
				cout << "*** Fatal error: List size is < " << (i + 1) << endl;
				exit(-1);
			}
			current = current->next;
		}

		return current->data;
	}

	void DeleteItem(T target) {
		ListNode<T> * assassin = head;

		while (assassin->next != NULL && assassin->next->data != target) {
			assassin = assassin->next;
		}

		if (assassin->next != NULL) {
			ListNode<T> * victim = assassin->next;
			assassin->next = victim->next;
			delete victim;
		}
	}

	void InsertItem(T item, int i) {
		/// Insert a NEW node with the given data
		/// *before* item #i.

		/// (If i is beyond the end of the list, just add to the end of the list)

		ListNode<T> * prior = head;
		int counter = 0;

		while (prior->next != NULL && counter < i) {
			prior = prior->next;
			counter++;
		}

		ListNode<T> * newnode = new ListNode<T>;
		newnode->data = item;

		newnode->next = prior->next;
		prior->next = newnode;

	}

};

int main() {
	LinkedList<string> names;
	names.InsertFront("Alice");
	names.InsertFront("Bob");
	names.InsertFront("Carol");
	names.InsertFront("Dave");

	while (true) {
		names.Print();
		string who;
		cout << "Who to delete? ";
		getline(cin, who);
		if (who == "")
			break;
		names.DeleteItem(who);
		cout << endl;
	}

	cout << endl;

	while (true) {
		names.Print();
		string who;
		cout << "Who to add? ";
		getline(cin, who);
		if (who == "")
			break;
		int index;
		cout << "What index number? ";
		cin >> index;
		cin.ignore(32768, '\n');
		names.InsertItem(who, index);
		cout << endl;

	}
}
