#include "../Linked_List.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
PROBLEM - Given a Head node of the linked list, return the length of the loop if there exists a loop
in the linked list else return 0

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a vector
We will first find the starting node of the loop
Take a vector
Take a counter varible which will count the total number of nodes we have moved till we found the loop
Traverse the linked list
Check if the current node is already present in the vector
if yes then, the loop length will be the counter - index of the starting node in vector
If not, then add the node to the vector and move on
Return 0, cause if the loop ends there exists no loop in the linked list.

TIME COMPLEXITY - O(N x N) Double looping in vector for every node
SPACE COMPLEXITY - O(N) vector
*/

int loop_length_brute( Node*head ){
    if (!head) return 0;

    vector<Node*> vec;
    int counter = 0;
    Node *mover = head;
    while(mover) {
        for (int i = 0; i < counter; i++){
            if (vec[i] == mover){
                return counter - i;
            }
        }
        vec.push_back(mover);
        counter++;
        mover = mover -> next;
    }

    return 0;
}

/*
BETTER APPROACH
---------------------
LOGIC - Using a Unordered Map ( O(1) lookup time )
We will first find the starting node of the loop
Take a unordered map
Take a counter = 0
Traverse the linked list
check if the node is already in the map
if yes return the "counter - node's value in the map"
else add the node in the map
If the loop gets over return 0, cause there is no loop

TIME COMPLEXITY - O(N) Unordered map has O(1) lookup
SPACE COMPLEXITY - O(N) unordered map
*/

int loop_length_better( Node *head ){
    if (!head) return 0;

    unordered_map<Node*, int> mpp;
    int counter = 0;
    Node *mover = head;
    while(mover) {
        if (mpp.find(mover) != mpp.end()) return counter - mpp[mover];
        mpp[mover] = counter;
        counter++;
        mover = mover -> next;
    }

    return 0;
}

/*
OPTIMAL APPROACH
---------------------
LOGIC - TORTOISE HARE APPROACH
Take two node pointer variables front and the back
But this time take a counter variable also
loop till the front is not null and the front's next is not null
While in the loop move the front two steps and move the back one step and update the counter every time
If there is a loop they will collide and when they collide, the number of the counter is the loop lenght
When the loop exists return 0 cause there is no loop int he linked list

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int loop_length_optimal(Node *head) {
    if (!head) return 0;

    Node *front = head;
    Node *back = head;

    // Step 1: Detect loop using Floyd’s Cycle Detection
    while (front && front->next) {
        front = front->next->next;
        back = back->next;

        if (front == back) {  // Collision → Loop exists
            break;
        }
    }

    if (!front || !front->next) return 0;  // No loop detected

    // Step 2: Find loop length
    int counter = 0;
    Node *temp = back;
    
    do {
        temp = temp->next;
        counter++;
    } while (temp != back);  // Stop when we complete one cycle

    return counter;  // Correct loop length
}


int main() {
    Node* head = example_linked_list();
    traverse_linked_list(head);
    head = create_loop(head, 5);
    int loop_length = loop_length_optimal(head);
    cout << "Loop Length : " << loop_length << endl;
}