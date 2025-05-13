#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head node, delete the first node and return the new head.

APPROACH
---------
LOGIC - 
We will save the head in another varaible, cause if we directly move the head forward, then there will be memory leak
After saving, then move the head forward
Free the space of the previous head
return new head

TIME COMPLEXITY - O(1) 
SPACE COMPLEXITY - O(1)
*/

Node *start_deletion( Node *head ){
    if (!head) {
        cout << "Linked List is Empty!" << endl;
        return nullptr;
    }
    Node *to_free = head; // Save the head in another pointer variable
    head = head -> next;  // make the head it's next
    delete to_free;       // delete or free the node
    return head;
}
