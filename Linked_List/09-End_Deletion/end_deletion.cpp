#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head node, delete the last node and return the new head.

APPROACH
---------
LOGIC - 
To delete the last node we will have to go to the last second node
When reached the last second node, save the last node in another variable to free later
make the last second's node's next pointer to nullptr
Free the last node saved in another variable
return the head

TIME COMPLEXITY - O(Size of the array) 
SPACE COMPLEXITY - O(1)
*/

Node *end_deletion(Node *head){
    if (!head) {
        cout << "Linked List is Empty!" << endl;
        return nullptr;
    }
    if (!head -> next) return nullptr;

    Node *mover = head;
    while (mover -> next -> next){
        mover = mover -> next;
    }
    Node *to_free = mover -> next;
    mover -> next = nullptr;
    delete to_free;
    return head;
}
