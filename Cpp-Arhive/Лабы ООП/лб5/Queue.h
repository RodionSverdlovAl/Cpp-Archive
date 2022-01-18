#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
struct QueueNode
{
	T value;
	QueueNode* next = nullptr;
};


template <class T>
class Queue
{
private:
	QueueNode<T>* head;
	int size;
public:
	Queue()
	{
		size = 0;
		head = nullptr;
	}

	~Queue()
	{
		deleteQueue();
	}

	void popFront();

	void pushFront(const T value);

	void deleteQueue();
	void showQueue();
	void findByValue(const T value);

	int getSize();

	bool operator == (const Queue& other);
	friend ostream& operator << (ostream&, Queue&);
};