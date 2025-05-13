#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head Node and an integer to insert at the end of the linked list, insert and return the head of the new linked list.

APPROACH
---------
LOGIC - To insert at the end of the linked list, we will go to the last node, but before that
Check if the head given is itself null, if yes, this means that the linked list is empty, return null
Take a mover pointer variable with the value head.
mover the mover forward, till the next node of the mover becomes null.
Now the mover is the last node of the linked list.
Make a new node with the data equal to the number given, and make it next to the mover
return the head.

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
*/

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