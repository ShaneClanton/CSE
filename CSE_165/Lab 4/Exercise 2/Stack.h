#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	struct Link {
		void* data;
		Link* next;
		
		void initialize(void* dat, Link* nxt) {
			data = dat;
			next = nxt;
		}
	}* head;
	
	void initialize() {
		head = 0;
	}
	
	void push(void* dat) {
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	void* peek() {
		if (head == 0) {
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	
	void* pop() {
		if(head == 0)
			return 0;
		
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
	
	void cleanup() {
		if (head == 0){
			std::cout << "Stack is empty";
		}
		else {
			std::cout << "Stack is not empty";
		}
	}
};

#endif


// The LinkedList class has a single data member, which is a pointer to the first 
// Link in the list, called head. The constructor of the LinkedList class takes a 
// double pointer d and an int value val. It initializes the head pointer to NULL 
// and then creates a new Link node with the data pointer pointing to the d argument, 
// and the next pointer set to NULL.

// The add method takes a Link pointer l and an integer n as input. 
// It creates a new Link node for each value of i from 0 to n-1, 
// initializes the data pointer to point to a new double containing i, 
// and sets the next pointer of the previous node to point to the new node.

// The print method traverses the linked list, starting from head, 
// and prints the double values stored in each Link node.

// The cleanup method is currently empty, but it could be used to deallocate 
// the memory used by the Link nodes.