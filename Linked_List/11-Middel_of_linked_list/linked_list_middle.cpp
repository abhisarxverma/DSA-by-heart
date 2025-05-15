#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given a Head Node of the Linked List, return the middle node of the linked list, in case of odd length
and first middle in case of the even length.

BRUTE FORCE APPROACH
---------------------
LOGIC - Get the length first and then go to the middle node
Loop from the head, to the end of the linked list and update the count.
Then loop again n/2 times, and return the node.

TIME COMPLEXITY - O(N+(N/2)) = O(N) 
SPACE COMPLEXITY - O(1)
*/

Node *linked_list_middle_brute(Node *head){
    if (!head) return nullptr;
    int length = 0;
    Node *mover = head;
    while (mover){
        length++;
        mover = mover -> next;
    }
    int middle = length/2;
    Node *middle_node = head;
    for (int i = 1; i < middle; i++) middle_node = middle_node -> next;
    return middle_node;
}

/*
BETTER APPROACH
---------------------
LOGIC - When the count gets increased by 2 the middle node gets one step forward
Take a counter integer
Take a middle Node and initialize that with head
Take a mover Node and initialize that with head
Run a while loop till the mover is not nullptr and everytime increment the counter by 1.
Also in the loop, if the counter becomes even then move the middle node forward to it's next
When the loop will get over you will have your middle node in the middle node variable.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

Node *linked_list_middle_better( Node *head ){
    if (!head) return nullptr;
    int count = 0;
    Node *middle = head;
    Node *mover = head;
    while(mover){
        count++;
        if (count>2 && count%2) middle = middle -> next;
        mover = mover -> next;
    }
    return middle;
}

/*
OPTIMAL APPROACH
---------------------
LOGIC - Tortoise Hare Method
Take a front mover Node
Take a back mover Node
Loop till front's next is not nullptr or the front's next's next is not nullptr
While in loop, every time
Move the front node two steps
Move the back node one step
When the loop ends you will have your middle node in the back node
This works on the same idea that the middle node moves forward one step every time the length of the sequence increases by two.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

Node *linked_list_middle_optimal( Node *head ){
    if (!head) return nullptr;
    Node* front = head;
    Node* back = head;
    while ( front->next && front->next->next ){
        front = front -> next -> next;
        back = back -> next;
    }
    return back;
}

int main() {
    Node *head = example_linked_list();
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 75);
    traverse_linked_list(head);
    Node *middle = linked_list_middle_optimal(head);
    cout << "Middle : " << middle -> data << endl;
}