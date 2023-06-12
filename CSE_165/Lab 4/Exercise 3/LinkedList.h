#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

struct LinkedList {      
    struct Link { 
        void* data;
        Link* next;
        
        void initialize(void* dat, Link* nxt = NULL) {
            data = dat;
            next = nxt;
        } 
    }* head;   
    LinkedList(double* val, std::nullptr_t){ //std::nullptr_t is used to represent a null pointer
        head = 0;
        head = new Link;
        head->initialize(val, NULL);
    }
    
    void add(LinkedList::Link* l, int n){ 
        Link* link;
        for (int i = 0; i < n; i++){
            link = new Link();
            link->initialize(new double(i)); 
            link->next = l->next;
            l->next = link;
            l = link;
        }   
    }
    
    void print(){
        Link* link = head;
        while(link != NULL){ 
            cout << *(double*)link->data << endl;
            link = link->next;
        }
    }
    
    void cleanup() {
        Link* current = head;
        Link* nextLink;
        while (current != NULL) {
            nextLink = current->next;
            delete(int*)current->data;
            delete current;
            current = nextLink;
        }
	}
};
#endif