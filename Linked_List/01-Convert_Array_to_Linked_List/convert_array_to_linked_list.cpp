#include "../Linked_List.h"
#include <iostream>
#include <vector>
using namespace std;

/*
APPROACH
---------

LOGIC - One by One Iterate over array and join into the linked list
Start by creating a temporary node (temp) with dummy data (-1). 
This serves as a placeholder to simplify insertion.
Use a mover pointer initialized to temp to track where new nodes should be added.
For each element in the array:
Create a new node with the current value.
Attach it to the next pointer of mover.
Move mover forward to the newly created node for the next insertion.
Once the iteration completes, the final linked list starts from temp->next, excluding the dummy node.
Using temp makes inserting nodes seamless, avoiding extra logic for handling the first node separately.

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
*/

Node* array_to_linked_list( vector<int> array ){
    Node *temp = new Node(-1);
    Node *mover = temp;
    for ( auto value : array ){
        mover -> next = new Node(value);
        mover = mover -> next;
    }
    return temp -> next;
}

int main() {
    vector<int> array = {1, 5, 10, 15, 20, 25};
    Node *head = array_to_linked_list(array);
    traverse_linked_list(head);

    vector<int> array2 = {};
    Node *head2 = array_to_linked_list(array2);
    traverse_linked_list(head2);
}  