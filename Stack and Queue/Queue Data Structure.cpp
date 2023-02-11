#include <iostream>
using namespace std;

class Queue {
	
	int* arr;
	int front = -1;
	int rear = -1;
	int capacity;

public:

	Queue() {}

	Queue(int c) {
		arr = new int[c];
		capacity = c;
	}

	bool isEmpty() {
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}
	
	bool isFull() {
		return (rear == capacity);
	}

	void Enqueue(int value) {
		if (isFull())
			cout << "Queue Overflow!";
			
		else {
			if (front == -1)     
				front = 0;         //To increase the index to 0 if the queue is empty
			rear++;                //Rear will be incremented where ever it is locating and the value is inserted
			arr[rear] = value;
		}
	}

	void Dequeue() {
		if (isEmpty())
			cout << "Queue Underflow..";
		else
			front++;          //It will remove the first element of queue
	}

	void printQueue() {
		if (isEmpty()) {
			cout << "Queue is Empty!";
		}
		else {
			for (int i = front; i <= rear; i++) {
				cout << arr[i] << " ";
			}
		}
	}
};

int main() {	
	Queue q(5);
	cout << "Queue: " << endl;
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.printQueue();

	q.Dequeue();
	cout << endl << "After Deleting element: " << endl;
	q.printQueue();

	return 0;
}

