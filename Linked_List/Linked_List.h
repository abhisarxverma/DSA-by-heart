#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;

    public:
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void traverse_linked_list( Node *head ){
    if (!head) {
        cout << "Linked List is empty!" << endl;
        return;
    }
    Node *mover = head;
    while (mover) {
        cout << mover -> data;
        if (mover -> next) cout << " -> ";
        else cout << endl;
        mover = mover -> next;
    }
}

Node * insert_at_end( Node *head, int number ){
    if (!head){
        cout << "Linked List is Empty!" << endl;
        return head;
    }
    Node *mover = head;
    while (mover -> next){
        mover = mover -> next;
    }
    mover -> next = new Node(number);
    return head;
}

// Returns already created example linked list
Node *example_linked_list() {
    
    // Example Linked list
    Node *head = new Node(10);
    head -> next = new Node(15);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(25);
    head -> next -> next -> next -> next = new Node(30);
    head -> next -> next -> next -> next -> next = new Node(35);
    head -> next -> next -> next -> next -> next -> next = new Node(40);

    return head;
}

#endif