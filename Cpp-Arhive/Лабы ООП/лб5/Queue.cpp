#include "Queue.h"

template <class T>
void Queue<T>::pushFront(const T value)
{
	if (this->head == nullptr)
	{
		this->head = new QueueNode<T>;
		this->head->value = value;
	}
	else
	{
		QueueNode<T>* temp = new QueueNode<T>;
		temp->value = value;
		
		temp->next = this->head;
		this->head = temp;
	}

	size++;
}

template <class T>
void Queue<T>::popFront()
{
	if (this->head == nullptr)
	{
		return;
	}
	else if (this->head->next == nullptr)
	{
		delete this->head;
		this->head = nullptr;
	}
	else
	{
		QueueNode<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}

	size--;
}

template <class T>
void Queue<T>::showQueue()
{
	if (this->head == nullptr)
	{
		cout << "Односвязный список пуст!" << endl;
		return;
	}

	QueueNode<T>* current = this->head;

	while (current != nullptr)
	{
		cout << current->value << setw(3);
		current = current->next;
	}
	cout << endl;
}

template <class T>
void Queue<T>::deleteQueue()
{
	if (this->head == nullptr)
	{
		return;
	}

	QueueNode<T>* current = this->head;

	while (this->head != nullptr)
	{
		popFront();
	}

	this->head = nullptr;
}

template <class T>
void Queue<T>::findByValue(const T value)
{
	if (this->head == nullptr)
	{
		cout << "Односвязный список пуст!" << endl;
		return;
	}
	else
	{
		QueueNode<T>* current = this->head;
		int counter = 0;

		while (current != nullptr)
		{
			if (current->value == value)
			{
				cout << "Элемент " << value << " содержится в односвязном списке на " << counter + 1 << " месте" << endl;
				return;
			}

			current = current->next;
			counter++;
		}

		cout << "Данного элемента в односвязном списке нет!" << endl;
	}
}

template <class T>
bool Queue<T>::operator == (const Queue<T>& other)
{
	if (this->getSize() == other.getSize())
		return true;
	else
		return false;
}

template <class T>
ostream& operator << (ostream& out, Queue<T>& obj)
{
	out << obj.showQueue();
	return out;
}

template <class T>
int Queue<T>::getSize()
{
	return this->size;
}