#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head Node, and an integer which is the position of the node to delete in the linked list
Delete the node and return the new head.

APPROACH
---------
LOGIC - To delete a node at the particular position in the linked list we have to go to one node before that position
We will handle the case in which the position given is 1 cause there is no node before that
We will run a for loop from 1 to position - 1 times, with moving the mover to it's next we will also do one check in loop
That if the mover becomes nullptr, then this means the position entered is out of the linked list, we will return head
When we come out of the loop there, the mover should be the one before node, so we will do deletion
We will save the mover's next node which is the node to delete, and connect the mover's next the mover's next's next skipping the middle node
now we will free the node
But there is an edge case that you can miss, which is that if the user enters the position which is one more than the length of linked list
then the mover will be at last node, and there's no next node, and if we try to reach the mover's next's next we will get error
So after the loop completion, we will do one more check, if the mover or the mover's next is null, if yes, we will return the head cause this is also case of out of bound position.
return the head

TIME COMPLEXITY - O(Size of Linked List) 
SPACE COMPLEXITY - O(1)
*/

Node *middle_deletion( Node *head, int position ){
    if (!head) {
        cout << "Linked List is Empty!" << endl;
        return nullptr;
    }
    if (position < 1) {
        cout << "Position Invalid : Cannot less than 1." << endl;
        return head;
    }
    if (position == 1) {
        Node *to_free = head;
        head = head -> next;
        delete to_free;
        return head;
    }
    Node *mover = head;
    for (int i = 1; i < position-1; i++){
        if (!mover) {
            cout << "Position Invalid : More than Linked List size." << endl;
            return head;
        }
        mover = mover -> next;
    }

    if (!mover || !mover -> next) {
        cout << "Position Invalid : More than the Linkd List size." << endl;
        return head;
    }
    Node *to_free = mover -> next;
    mover -> next = mover -> next -> next;
    delete to_free;
    return head;
}

int main() {
    Node *head = example_linked_list();
    traverse_linked_list(head);
    Node *new_head = middle_deletion(head, 3);
    traverse_linked_list(new_head);
}