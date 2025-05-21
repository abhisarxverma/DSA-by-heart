#include "../Linked_List.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
PROBLEM - Given a Head Node of the linked list, find and return the starting node of the loop in the linked list if the loop exists else return null.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a vector to store the visited nodes
Take a vector
Traverse the linked list, put the node in the vector
And in every loop check if the node is already present in the vector by looping
If yes return the node, else move on
At last return Nullptr.

TIME COMPLEXITY - O(N x N) Double looping in vector for every node
SPACE COMPLEXITY - O(N) vector
*/

Node* loop_starting_node_brute( Node *head ){
    if (!head) return nullptr;

    vector<Node*> vec;

    Node *mover = head;
    while(mover){
        for (auto node: vec){
            if (node == mover) return mover;
        }
        vec.push_back(mover);
        mover = mover -> next;
    }
    return nullptr;
}

/*
BETTER APPROACH
---------------------
LOGIC - Using a unordered set for O(1) lookup
Take a unordered set
traverse the linked list
first check the set if it have the current node
if yes return the mover
if not put the mover in the set
at last return the nullptr

TIME COMPLEXITY - O(N) Unorderet set has O(1) lookup due to hashing
SPACE COMPLEXITY - O(N) Unordered set
*/

Node *loop_starting_node_better(Node *head){
    if (!head) return nullptr;

    unordered_set<Node*> set;

    Node *mover = head;
    while (mover) {
        if ( set.find(mover) != set.end() ) return mover;
        set.insert(mover);
        mover = mover -> next;
    }
    return nullptr;
}

/*
OPTIMAL APPROACH
---------------------
LOGIC - TORTOISE HARE METHOD
Take two node pointer variables - front and back
Initialize both of them with the head;
loop till the front if not null and the front's next is not null
in the loop move the front two setps and back one step
If the loop ends return the nullptr casue the linked list is not looped
But if the linked list is looped, then they both will meet 
And at the node in which they meet, you have to perform a simple loop to get the starting node of loop
we will take a new node pointer and initialize that also with the head
And with a loop, we will move the new and the front pointer together everytime
And at the point they both meet, that is the starting node of the loop.

🔹 Why Do Front and the Back Pointer Meet?
Think of a running track:
The slow pointer moves one step at a time.
The fast pointer moves two steps at a time.
If there's a loop, the fast pointer will keep moving in circles until it catches up to the slow pointer.
Since the fast pointer closes the gap with every step, it will eventually meet the slow pointer inside the cycle.

🔹 Why Is the Distance the Same?
Let’s define:
D = Distance from head to loop start
X = Distance from the front to the back in the loop
The Idea here is that when the front and the back start moving, and when the back reaches the starting node (we are assuming that we know which one is starting node), let that distance between the head and the starting node be D.
So when the back will be standing at the starting node, the front will be at double the distance of the head and the start, so the distance from the back to front will also be D
And then the distance from the front to back let's take X
So to collide the back pointer moved X distance to meet the front, and let's say they are now at same node.
so if the back moved X distance to meet the front from the starting node, then the remaining distance from the collision node to the starting node will be D. cause Loop length = D + X
And D is nothing but the distance from the head to the starting node of the loop
That's how the distance from the head to the start and the distance from the collision node to the start is the same.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

Node *loop_starting_node_optimal( Node *head ){
    Node* front = head; // Fast pointer (moves 2 steps)
    Node* back = head;  // Slow pointer (moves 1 step)

    // Step 1: Detect loop by checking if front and back pointers meet
    while (front && front->next) {
        front = front->next->next; // Move fast pointer two steps
        back = back->next;         // Move slow pointer one step

        if (front == back) { // Collision point inside the loop
            break;
        }
    }

    // If no loop exists, return nullptr
    if (!front || !front->next) return nullptr;

    /**
     * Step 2: Find the loop start
     * The distance from head to the loop start (D)
     * is equal to the distance from the collision node to the loop start (D)
     */
    Node* newPointer = head;

    // Move both pointers one step at a time until they meet at loop start
    while (newPointer != back) {
        newPointer = newPointer->next;
        back = back->next;
    }

    return newPointer; // This is the loop starting node
}

int main() {
    Node *head = example_linked_list();
    traverse_linked_list(head);
    head = create_loop(head, 3);
    Node *start_node = loop_starting_node_optimal(head);
    cout << "Starting node of the loop : " << start_node -> data << endl;
    return 0;
}