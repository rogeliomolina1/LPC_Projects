//============================================================================
// Name        : StackNode.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct StackNode {
	string data;
	StackNode*nextPtr;
};

class Stack {
private:
	StackNode*top;
public:
	Stack();
	bool IsEmpty() const;
	string Peek() const;
	void Push(string item);
	void Pop();
};

Stack::Stack() {
	top = NULL;
}

bool Stack::IsEmpty() const {
	return (top == NULL);
}

string Stack::Peek() const {
	return (top->data);
}

void Stack::Push(string item) {
	StackNode* ptr = new StackNode();
	ptr->data = item;
	ptr->nextPtr = top;
	top = ptr;
}

void Stack::Pop() {
	StackNode*temp = top;
	top = top->nextPtr;
	delete temp;
}

int main() {
	Stack myStack;
	myStack.Push("cat");
	myStack.Push("dog");
	myStack.Push("narwhal");
	while (myStack.IsEmpty() == false) {
		cout << "Current top: " << myStack.Peek() << endl;
		myStack.Pop();
	}
	cout << "Done!" << endl;
	return 0;
}
