#include "../Linked_List.h"
#include <iostream>
using namespace std;

/*
PROBLEM - Given the head node of the linkd list, remove the middle node and return the head of the new linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Counting the length
First count the length of the linked list
Then go one node before the "total length / 2" and delete that

TIME COMPLEXITY - O(N + N/2) N to count, N/2 to delete
SPACE COMPLEXITY - O(1) 
*/

Node *remove_middle_brute( Node *head ){
    if (!head || !head -> next) return nullptr;

    // Let's count the length
    int length = 0;
    Node *mover = head;
    while(mover) {
        length ++;
        mover = mover -> next;
    }

    int node_to_delete = length / 2;
    mover = head;
    for (int i = 1; i < node_to_delete; i++){
        mover = mover -> next;
    }

    Node *to_delete =  mover -> next;
    mover -> next = mover -> next -> next;
    delete to_delete;
    return head;
}

/*
BETTER APPROACH
---------------------
LOGIC - Little Observation - The middle node increases by one when the length increases by two.
Take a length counter
Take a prev node pointer
Take a mover node pointer
Move the mover while the mover does not become null
And in the loop, evertime the length becomes even, just move the prev pointer
At end of the loop, you will have your prev at the one node before the middle
Just delete that the normal process and return the head.

TIME COMPLEXITY - O(N/2)
SPACE COMPLEXITY - O(1) 
*/

Node *remove_middle_better( Node *head ){
    if (!head || !head -> next) return nullptr;

    int length = 0;
    Node *prev = nullptr;
    Node *middle = head;
    Node *mover = head;
    while (mover) {
        length++;
        if (length%2==0){
            prev = middle;
            middle = middle -> next;
        }
        mover = mover -> next;
    }

    prev -> next = prev -> next -> next;
    delete middle;
    return head;
}

/*
OPTIMAL APPROACH
---------------------
LOGIC - TORTOISE HARE ALGORITHM
Logic here is same that the middle moves one step when the length moves two step
but the implementation will be more simple and startight forward
take two node pointer variables fast and slow
run a while loop till the fast and the fast's next is not null
and in the loop move the fast two step and the slow one step
When the loop will end the slow is the middle node
but to remove the middle node we have to go one node before the middle
so we will also maintain a prev node pointer that will save the previous middle if the middle changes
and then we will remove the middle with normal procedure and then return the head

TIME COMPLEXITY - O(N/2)
SPACE COMPLEXITY - O(1) 
*/

Node *remove_middle_optimal( Node *head ){
    if (!head || !head -> next) return nullptr;

    Node *fast = head;
    Node *slow = head;
    Node *prev = nullptr;

    while ( fast && fast -> next ){
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
    }

    prev -> next = slow -> next;
    delete slow;
    return head;
}

int main() {
    Node *head = example_linked_list();
    head -> next = new Node(99, head -> next);
    traverse_linked_list(head);
    head = remove_middle_optimal(head);
    traverse_linked_list(head);
}