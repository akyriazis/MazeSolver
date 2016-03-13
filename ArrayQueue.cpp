#ifndef _ARRAYQUEUESOLN_CPP
#define _ARRAYQUEUESOLN_CPP

//ArrayQueueSoln.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfMazeStates
ArrayQueue::ArrayQueue() : head(0), tail(0)
{
	array = new MazeState*[INIT_SIZE]();
	capacity = INIT_SIZE;
}

void ArrayQueue::add(MazeState *elem)
{
	if ((tail+1) % (capacity) == head) {
		// queue is full
		ensure_capacity(capacity+1); // ensure_capacity makes grows the array.
	}

	array[tail] = elem;
	tail = (tail + 1) % capacity;
}

MazeState *ArrayQueue::remove()
{
	// TODO: implement remove method
	assert(!is_empty());
	MazeState *temp = array[head];
	head = (head + 1) % (capacity);
	return temp;
}

bool ArrayQueue::is_empty()
{
  // TODO: implement is_empty method
  return (head==tail);
}

// TODO: implement ensure_capacity (but leave this to last.. just start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
	if (capacity < n) {
		// Make plenty of room.
		int target_capacity = (n > 2 * capacity + 1) ? n : (2 * capacity + 1);
		MazeState **oldarray = array;
		array = new MazeState*[target_capacity]();

		int i = 0;
		while ((i + head) % capacity != tail) {
			array[i] = oldarray[(i + head) % capacity];
			i++;
		}
		head = 0;
		tail = i;

		capacity = target_capacity;

		delete[] oldarray;
	}
}


ArrayQueue::~ArrayQueue()
{
	delete[] array;
}

#endif
