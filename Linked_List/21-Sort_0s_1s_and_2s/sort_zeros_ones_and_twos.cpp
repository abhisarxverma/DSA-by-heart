#include "../Linked_List.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
PROBLEM - Given the head node of the linked list which have numbers 0s, 1s and 2s, sort the linked list and return the head of the sorted linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using Vector
Take all the data of the linked list in an array
Sort the array then put the data back in the linked list.

TIME COMPLEXITY - (3N log N) - O(N) to put the data in array + O(N Log N) Sorting + O(N) To put the data back in linked list
SPACE COMPLEXITY - O(N) array
*/

Node *sort_zeros_ones_and_twos_brute( Node *head ){
    if (!head || !head -> next) return head;

    vector<int> array;
    Node *mover = head;
    while( mover ) {
        array.push_back(mover -> data);
        mover = mover -> next;
    }

    sort(array.begin(), array.end());

    mover = head;
    for (auto num: array){
        mover -> data = num;
        mover = mover -> next;
    }

    return head;

}

/*
BETTER APPROACH
---------------------
LOGIC - Counting the occurences
Traverse the linked list
While traversing update the count of the 0s 1s and 2s
after getting count traverse the linked list again putting the values according to the occurences
return the head

TIME COMPLEXITY - O(2N) - O(N) To get the counts + O(N) To put the data in sorted way
SPACE COMPLEXITY - O(1)
*/

Node *sort_zeros_ones_and_twos_better( Node *head ){
    if (!head || !head -> next) return head;

    int zeros_count = 0;
    int ones_count = 0;
    int twos_count = 0;

    Node *mover = head;
    while (mover) {
        int num = mover -> data;
        if (num < 1) zeros_count++;
        else if (num == 1) ones_count++;
        else twos_count++;
    }

    mover = head;
    while (mover) {
        if (zeros_count){
            mover -> data = 0;
            zeros_count--;
        }
        else if (ones_count){
            mover -> data = 1;
            ones_count--;
        }
        else {
            mover -> data = 2;
            twos_count--;
        }
        mover = mover -> next;
    }

    return head;
}

/*
OPTIMAL APPROACH
---------------------
1. Create Three Dummy Nodes
One dummy node each for:
0s list
1s list
2s list
Let’s call them:
zeroHead, oneHead, twoHead
Initialize each with a dummy value (e.g., -1 or any placeholder)
These dummy nodes make list handling easy and clean.

2. Create Three Tails (Moving Pointers)
These will help us append elements to the correct list:
zeroTail, oneTail, twoTail
Initially, point them to their respective dummy nodes.

3. Traverse Original Linked List
For each node in the list:
If it's 0: append it to the 0s list using zeroTail
If it's 1: append to the 1s list
If it's 2: append to the 2s list
After appending, move the corresponding tail forward.

4. Link the Three Lists
We now have:
A dummy-headed list of 0s
A dummy-headed list of 1s
A dummy-headed list of 2s

Now we join them:
Set twoTail->next = nullptr to avoid loops.
Join:
oneTail->next = twoHead->next (skip dummy)
Join:
zeroTail->next = oneHead->next (or twoHead->next if 1s list is empty)
🧠 What If Some Lists Are Empty?
If 1s are missing:
oneTail == oneHead → .next will point directly to 2s
If 0s are missing:
zeroTail == zeroHead → .next will point to 1s or 2s
This chain ensures the result is always correct.

TIME COMPLEXITY - O(2N) - O(N) To get the counts + O(N) To put the data in sorted way
SPACE COMPLEXITY - O(1)
*/

Node *sort_zeros_ones_and_twos_optimal( Node *head ){

    if (!head || !head->next) return head; 

    Node *zeroHead = new Node(-1), *zeroTail = zeroHead;
    Node *oneHead = new Node(-1), *oneTail = oneHead;
    Node *twoHead = new Node(-1), *twoTail = twoHead;

    Node* mover = head;

    // Separate the nodes into three linked lists
    while (mover) {
        if (mover->data == 0) {
            zeroTail->next = mover;
            zeroTail = mover;
        } else if (mover->data == 1) {
            oneTail->next = mover;
            oneTail = mover;
        } else {
            twoTail->next = mover;
            twoTail = mover;
        }
        mover = mover->next;
    }

    // Connecting the lists
    twoTail->next = nullptr;  // Ensures last node doesn't point to old references
    oneTail->next = twoHead->next;
    zeroTail->next = oneHead->next ? oneHead->next : twoHead->next;

    // Return the new sorted list
    head = zeroHead->next;  

    // Free dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}