#include "../Linked_List.h"
#include <iostream>
using namespace std;

// PROBLEM - Given head (Node object) of Linked List, return the length of the linked list.

/*
APPROACH
---------

LOGIC - Traverse the Linked List and calculate the length
Take a counter variable "length"
Take a mover pointer variable, move the mover to it's next till the mover becomes None and increment the count ever time.

TIME COMPLEXITY - O(Size of Linked List) 
SPACE COMPLEXITY - O(1)
*/

int linked_list_length( Node *head ){
    int length = 0;
    Node *mover = head;
    while (mover) {
        length++;
        mover = mover -> next;
    }
    return length;
}