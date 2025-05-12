#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given Head Node of the linked list and a number to find in the interger, return true if found else return false

APPROACH
---------

LOGIC - Complete Linked List iteration
Take a mover pointer variable, and using that traverse the linked list while checking the mover's data 
if found the number return True else return False

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
*/

bool search_linked_list( Node *head, int number ){
    Node *mover = head;
    while (mover) {
        if (mover -> data == number) return true;
        mover = mover -> next;
    }
    return false;
}