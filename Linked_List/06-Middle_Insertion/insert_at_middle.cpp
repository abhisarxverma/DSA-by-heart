#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head Node, integer number and a positive integer which is the position number in the linked list at which to insert the number, insert and return the head of the new linked list.

APPROACH
---------
LOGIC - To insert a number at the given position, we will go to one node before the node at that position but before that
Check if the head passed is null, if yes then the linked list is empty, return null.
Check if the position entered is smaller to zero, if yes, print error message and return the head
And also cause in this approach we are going to the one node before the position to insert, if the user enter the 1, then this approach may fail, so handle that case seperately.
Take a mover pointer variable, move the mover forward using a for loop running "position - 2" times
Add a check in the for loop that if the mover becomes none print the error message if you want and return head
cause the user may enter the position which is more than the linked list size.
When the for loop finishes we will be at the one position before the position we want to insert new number
But we have to check here again, cause if the user enters the position 2 greater than the linked list size, the mover will become null but not in the for loop but after that
And then make a new node with the data equal to the number given, make the new node's next the mover's next and make the mover's next the new node
return the head

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
*/

Node *insert_at_middle( Node *head, int number, int position ){
    if (!head) {
        cout << "Linked List is empty!" << endl;
        return nullptr;
    }
    if (position < 1) {
        cout << "Position Invalid: Cannot be negative." << endl;
        return head;
    }

    if (position == 1) return new Node(number, head);
    
    Node *mover = head;
    for (int i = 1; i < position-1; i++){
        if (!mover){
            cout << "Invalid Position : More than linked list size." << endl;
            return head;
        }
        mover = mover -> next;
    }

    // Precaution check that mover is not nullptr
    if (!mover){
            cout << "Invalid Position : More than linked list size." << endl;
            return head;
        }

    Node *new_node = new Node(number, mover -> next);
    mover -> next = new_node;
    return head;
}

int main() {
    Node *head = example_linked_list();
    Node *new_head = insert_at_middle(head, 2, 8);
    traverse_linked_list(new_head);
}