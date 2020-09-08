//============================================================================
// Name        : Heap.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LeftChildOf(n) (n*2+1)
#define RightChildOf(n) (n*2+2)
#define ParentOf(n) ((n-1)/2)

struct Entry {
	string item;
	int priority;
	int entryNumber;
};

class PQueue {
private:
	vector<Entry> heap;
	int total;

public:
	PQueue();
	void Enqueue(string item, int priority); /// lower #s = better priority
	string Dequeue();
	bool Empty();
	bool IsLighter(Entry first, Entry second);
};

PQueue::PQueue() {
	total = 0;
}

void PQueue::Enqueue(string item, int priority) {
	Entry added;
	added.item = item;
	added.priority = priority;
	added.entryNumber = total;
	total++;

	heap.push_back(added);

	/// As needed, swap the added entry upward in the heap.
	/// (Hint: Infinite while loop with a break.)
	int index = heap.size() - 1;
	while (true) {
		if (index == 0
				|| heap[ParentOf(index)].priority <= heap[index].priority) {
			break;
		} else {
			swap(heap[ParentOf(index)], heap[index]);
			index = ParentOf(index);
		}
	}

}

bool PQueue::IsLighter(Entry first, Entry second) {
	if (first.priority < second.priority) {
		return true;
	} else if (first.priority == second.priority) {
		return (first.entryNumber < second.entryNumber);
	} else {
		return false;
	}
}

string PQueue::Dequeue() {
	string result = heap[0].item;

/// Swap last element into root position (and shrink the vector)
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	total--;
/// As needed, swap that element downward.
/// (Hint: Infinite while loop with a break.)
	int index = 0;
	while (true) {

		if (LeftChildOf(index) >= heap.size()) {
			break;

		} else if (RightChildOf(index) >= heap.size()) {
			if (IsLighter(heap[LeftChildOf(index)], heap[index])) {
				swap(heap[LeftChildOf(index)], heap[index]);
				index = LeftChildOf(index);
			}
			break;

		} else if (IsLighter(heap[index], heap[LeftChildOf(index)])
				&& IsLighter(heap[index], heap[RightChildOf(index)])) {
			break;

		} else if (IsLighter(heap[LeftChildOf(index)], heap[index])
				&& IsLighter(heap[index], heap[RightChildOf(index)])) {
			swap(heap[LeftChildOf(index)], heap[index]);
			index = LeftChildOf(index);

		} else if (IsLighter(heap[RightChildOf(index)], heap[index])
				&& IsLighter(heap[index], heap[LeftChildOf(index)])) {
			swap(heap[RightChildOf(index)], heap[index]);
			index = RightChildOf(index);

		} else {

			if (IsLighter(heap[LeftChildOf(index)],
					heap[RightChildOf(index)])) {
				swap(heap[LeftChildOf(index)], heap[index]);
				index = LeftChildOf(index);

			} else {
				swap(heap[RightChildOf(index)], heap[index]);
				index = RightChildOf(index);
			}
		}
	}
	return result;
}

bool PQueue::Empty() {
	return (heap.empty());
}

int main() {
	PQueue q;

	q.Enqueue("A", 4);
	q.Enqueue("B", 5);
	q.Enqueue("C", 2);
	q.Enqueue("D", 4);
	q.Enqueue("E", 2);
	q.Enqueue("F", 1);
	q.Enqueue("G", 3);
	q.Enqueue("H", 1);

	cout << "Now serving: " << q.Dequeue() << endl;
	while (!q.Empty()) {
		cout << "Now serving: " << q.Dequeue() << endl;
	}
	return 0;
}
