#include "../Linked_List.h"
#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEM - Given the Head Node Object, and an integer to insert at start of the linked list, add and return the head of the new linked list.

APPROACH
---------
LOGIC - Make a New Node with the data equal to the number given
Make Head's next the New Node.
Make the Head the New Node.
Return the Head.

TIME COMPLEXITY - O(1) 
SPACE COMPLEXITY - O(1)
*/

Node* insert_at_start( Node *head, int number ){
    if (!head) {
        cout << "Linked List is Empty!" << endl;
        return head;
    }
    head = new Node(number, head);
    return head;
}