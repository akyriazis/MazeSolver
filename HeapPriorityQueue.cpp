//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
	int index = (int) heap.size();
	heap.push_back(elem);
	while (!is_root(index) && heap[parent(index)]->getBadness() > heap[index]->getBadness()) {
		std::swap(heap[index], heap[parent(index)]);
		index = parent(index);
	}
}

MazeState * HeapPriorityQueue::remove() {

	assert(!is_empty());

	MazeState* temp = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();

	int index = 0;
	while (num_children(index) != 0) {

		int newIndex;
		int childIndex = first_child(index);

		if (num_children(index) == 2) {
			if (heap[childIndex]->getBadness() < heap[childIndex + 1]->getBadness()) {
				newIndex = childIndex;
			} else {
				newIndex = childIndex + 1;
			}
		}else{ //only one child (must be first child)
			newIndex = childIndex;
		}
		if (heap[newIndex]->getBadness() > heap[index]->getBadness()) { break; }
		std::swap(heap[index], heap[newIndex]);
		index = newIndex;
	}
	return temp;
}


bool HeapPriorityQueue::is_empty() {
	return heap.empty();
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
