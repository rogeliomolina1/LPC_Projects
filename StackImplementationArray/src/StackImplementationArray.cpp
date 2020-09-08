//============================================================================
// Name        : StackImplementationArray.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define USE_ARRAY 0

#if !USE_ARRAY
template<typename T>
struct Node {
	T data;
	Node<T> * next;
};
#endif

template<typename T>
class CS20Stack {
private:
#if USE_ARRAY
	T * elements;
	int top;
	int arraySize;
#else
	Node<T> * top;
#endif // USE_ARRAY

public:
	CS20Stack() {
#if USE_ARRAY
		cout << "Array implementation active." << endl;
		arraySize = 8;
		top = 0;
		elements = new T[arraySize];
#else
		top = NULL;
#endif // USE_ARRAY
	}
	void Push(T item) {
#if USE_ARRAY
		elements[top++] = item;
		/// Check if our current "slots" are used up
		if (top == arraySize)
		{
			/// reallocate and copy!
			arraySize *= 2;
			T * newArray = new T[arraySize];
			for (int i = 0; i < arraySize/2; i++)
			{
				newArray[i] = elements[i];
			}
			delete[] elements;
			elements = newArray;
		}
#else
		Node<T> * newNode = new Node<T>;
		newNode->data = item;
		newNode->next = top;
		top = newNode;

#endif
	}
	void Pop() {
#if USE_ARRAY
		if (top > 0)
		top--;
#else
		Node<T> * victim = top;
		top = victim->next;
		delete victim;
#endif
	}
	T Peek() {
#if USE_ARRAY
		return elements[top-1];
#else
		return top->data;
#endif
	}
	bool Empty() {
#if USE_ARRAY
		return (top == 0);
#else
		return (top == NULL);
#endif
	}
};

int main() {
	CS20Stack<string> nameStack;

	nameStack.Push("Alice");
	nameStack.Push("Brett");
	nameStack.Push("Cindy");
	nameStack.Push("Diego");

	cout << "Current top: " << nameStack.Peek() << endl;

	nameStack.Pop();

	cout << "Popping all remaining elements... " << endl;

	while (!nameStack.Empty()) {
		cout << nameStack.Peek() << endl;
		nameStack.Pop();
	}
	return 0;
}
