#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	int size;
	void(*deletecb)(void* pt);
	struct Link {
		void* data;
		Link* next;
		
		void initialize(void* dat, Link* nxt){
			data = dat;
			next = nxt;
		}
	}* head;
	
	void initialize(){
		head = 0;
		size = 0;
	}
	
	void push(void* dat){
		size++;
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	void* peek(){
		if (head == 0){
			std::cout << "Stack is empty";
		}
		if(head != 0){
			std::cout << "Stack is not empty";
		}
		return head->data;
	}
	
	void* pop(){
		size--;
		if(head == 0)
			return 0;
		
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
	
	void cleanup(){
		int tempsize = size;
		for (int i = 0; i < tempsize; i++)
		{
			deletecb(pop());
		}
		
		if (head == 0){
			std::cout << "Stack is empty";
		}
		if (head != 0) {
			std::cout << "Stack is not empty";
		}
	}

	void setDeleteCallback(void (*del_func_ptr)(void* pt)){
		deletecb = del_func_ptr;
	}
};
#endif