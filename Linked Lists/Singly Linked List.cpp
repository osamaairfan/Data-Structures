#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
};

class SinglyLinkedList {
public:
	Node* head;

	SinglyLinkedList() {
		head = NULL;
	}

	/*Insertion at the beginning*/
	void insertBeg(int data) {                  
		if (head == NULL) {
			Node* current = new Node;
			current->data = data;
			current->next = NULL;
			head = current;
		}
		else {
			Node* current = new Node;
			current->data = data;
			current->next = head;
			head = current;
		}
	}

	/*Insertion in the Middle*/
	void insertMiddle(int addAfter, int data) {
		Node* temp = head;
		while (temp->data != addAfter) {
			temp = temp->next;
		}
		Node* current = new Node;
		current->data = data;
		current->next = temp->next;
		temp->next = current;
	}

	/*Insertion at the End*/
	void insertEnd(int data) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node* current = new Node;
		temp->next = current;
		current->data = data;
		current->next = NULL;
	}

	/*Deletion at the beginning*/
	void delBeg() {
		Node* temp = head;
		head = temp->next;
		delete temp;
	}

	/*Deletion in the Middle*/
	void delMiddle(int data) {
		Node* current = head;
		Node* prev = current;
		while (current->next != NULL) {
			if (current->data == data)
				break;
			prev = current;
			current = current->next;
		}
	
		prev->next = current->next;
		delete current;
	}

	/*Deletion at the End*/
	void delEnd() {
		Node* current = head;
		Node* prev = current;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		delete current;
	}

	/*Traverse and Display*/
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	Node* head = NULL;
	SinglyLinkedList l1;

	l1.insertBeg(2);
	l1.insertBeg(3);
	l1.insertBeg(4);
	l1.display();
	cout << endl << "Insert in the Middle: " << endl;
	l1.insertMiddle(3, 1);
	l1.display();
	cout << endl << "Insert at the End: " << endl;
	l1.insertEnd(5);
	l1.display();
	cout << endl << "Deletion at the Beginning: " << endl;
	l1.delBeg();
	l1.display();
	cout << endl << "Deletion int the Middle: " << endl;
	l1.delMiddle(1);
	l1.display();
	cout << endl << "Deletion at the End: " << endl;
	l1.delEnd();
	l1.display();
	return 0;
}