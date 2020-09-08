//============================================================================
// Name        : LinkedList.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct ListNode {
	string data;
	ListNode * nextPtr;
};

class LinkedList {
private:
	ListNode * front;
	ListNode * back;
	int numElements;
public:
	LinkedList();
	/// Accessors
	bool IsEmpty() const;
	void Print() const;
	string Get(int k) const;

	/// Mutators
	void Push(string item);
	void Append(string item);
	void Insert(string item, int k);
	void Remove(int k);

};

LinkedList::LinkedList() {
	front = NULL;
	back = NULL;
	numElements = 0;
}

bool LinkedList::LinkedList::IsEmpty() const {
	return (front == NULL);
}

void LinkedList::Push(string item) {
	ListNode * ptr = new ListNode;
	ptr->data = item;
	ptr->nextPtr = front;
	front = ptr;
	if (back == NULL) /// list was empty, I just added one thing
		back = front;
	numElements++;
}

void LinkedList::Append(string item) {
	ListNode * ptr = new ListNode;
	ptr->data = item;
	ptr->nextPtr = NULL;
	if (back != NULL) {
		back->nextPtr = ptr;
		back = ptr;
	} else /// list is empty
	{
		front = ptr;
		back = ptr;
	}
	numElements++;
}

void LinkedList::Print() const {
	ListNode * current = front;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->nextPtr;
	}
}

string LinkedList::Get(int k) const {
	ListNode * ptr;
	ptr = front;
	/// Advance ptr forward by k steps
	for (int i = 0; i < k; i++) {
		/// failsafe: return "" if k is out of range
		if (ptr == NULL)
			return "";

		/// Advance ptr forward 1 step
		ptr = ptr->nextPtr;
	}
	/// now return the data in the current node
	return ptr->data;
}

void LinkedList::Insert(string item, int k) {
	if (k == 0)
		Push(item);
	else if (k >= numElements)
		Append(item);
	else {
		/// Create the new node, ptr points to it
		ListNode * ptr = new ListNode;
		ptr->data = item;

		ListNode * current = front;
		/// current needs to advance (k-1) times
		for (int i = 0; i < (k - 1); i++) {
			current = current->nextPtr;
		}

		ptr->nextPtr = current->nextPtr;
		current->nextPtr = ptr;

		numElements++;
	}
}

void LinkedList::Remove(int k) {
	if (numElements == 0) /// compensate for user error
		return;

	if (k == 0) {
		ListNode * victimPtr = front;
		front = victimPtr->nextPtr;
		delete victimPtr;
		numElements--;
	} else {
		if (k >= numElements)  /// compensate for user error
			k = numElements - 1;

		ListNode * assassinPtr = front;
		/// assassinPtr needs to advance (k-1) steps
		for (int i = 0; i < (k - 1); i++) {
			assassinPtr = assassinPtr->nextPtr;
		}
		/// assassinPtr is set correctly now, so make a victimPtr
		ListNode * victimPtr = assassinPtr->nextPtr;
		assassinPtr->nextPtr = victimPtr->nextPtr;
		delete victimPtr;

		if (assassinPtr->nextPtr == NULL) /// we just removed the last node
			back = assassinPtr;

		numElements--;
	}

	if (numElements == 0)
		back = NULL;

}

int main() {
	LinkedList things;
	things.Push("chair");
	things.Append("potato");
	things.Append("table");
	things.Insert("steak", 2);
	things.Insert("plate", 1);
	things.Insert("salad", 4);
	things.Print();

	while (true) {
		int n;
		cout << "Remove from what index #? ";
		cin >> n;
		things.Remove(n);
		things.Print();
	}
	return 0;
}
