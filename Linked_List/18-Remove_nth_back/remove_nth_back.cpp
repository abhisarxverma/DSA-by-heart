#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given the head node of the linked list and an integer n, remove the nth node from the back and return the head of the result linked list

BRUTE FORCE APPROACH
---------------------
LOGIC - Getting the length of the linked list
Take a counter to 0
traverse the linked list and update the counter every time
now we got the length of the linked list
now we have to remove the nth from back, so we have to go to the total - n - 1
one before to remove the node and join it's next.
using the mover we will go to total - n - 1 node
when we got there we will simply make the current node's next the current node's next's next
And we will free the current node's next
and return the head

TIME COMPLEXITY - O(2N) First loop to get the length and the second to remove the node
SPACE COMPLEXITY - O(1)
*/

Node* remove_nth_back_brute( Node *head, int n ){
    if (!head) return nullptr;
    if (n < 1) {
        cout << " n cannot be negative. " << endl;
        return head;
    }
    
    int length = 0;
    Node *mover = head;
    while (mover) {
        length++;
        mover = mover -> next;
    }
   
    int node_to_remove = length - n;

    // What if the user passes the n more than the length?
    if (node_to_remove < 0) {
        cout << "n cannot be more than the length of the linked list." << endl;
        return head;
    }

    // What if the user passes the n which is equal to the linked list's length, which means they want to delete the first node, 
    // but our approach is to go one node before, but head has no node before, so we have to handle that separately.
    if (node_to_remove == 0){
        Node *new_head = head -> next;
        delete head;
        return new_head;
    }

    int moves = node_to_remove - 1; // to go to one node before we have to move the mover node's number - 1 times.
    mover = head;
    for (int i = 1; i <= moves; i++){
        mover = mover -> next;
    }

    // Now we are at the node one before to the node we want to remove
    Node *to_delete = mover -> next;
    mover -> next = mover -> next -> next;
    delete to_delete;
    return head;
}

/*

OPTIMAL APPROACH
---------------------
LOGIC - Clever Approach
Take a node pointer variable "front" and initialize that with the head
take the front to the nth from the front by moving it n-1 times
then take another node pointer variable "back" and initialize that with the head
now we have the back at head and the front at the nth from the front
now move both the nodes simultaneously until the the front's next becomes null
and when that happens the back will be at one node before the node to delete

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

Node *remove_nth_back_optimal( Node *head, int n ){
    Node *back = head;
    Node *front = head;
    for (int i = 0; i < n; i++){
        front = front -> next;
        if ( !front ){
            cout << "Invalid N : more than the total length." << endl;
            return head;
        }
    }
    while (front -> next){
        back = back -> next;
        front = front -> next;
    }
    back -> next = back -> next -> next;
    return head;
}

int main() {
    Node *head = example_linked_list();
    traverse_linked_list(head);
    head = remove_nth_back_optimal(head, 3);
    traverse_linked_list(head);
}