#include "../Linked_List.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
PROBLEM - Given a Head Node of the linked list, check if the linked list is looped, means that there is no end or the end is again pointing to any node in linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a vector
Take a vecor
Traverse the linked list, and for every node loop through the vector to find the node
if you find the node, return true
else put the node in the vector

TIME COMPLEXITY - O(N x N) Double looping in vector for every node
SPACE COMPLEXITY - O(N) vector
*/

bool check_loop_brute( Node*head ){
    if (!head) return false;
    vector<Node*> vec;
    Node *mover = head;
    while(mover){
        if (!vec.empty()){
            for (auto node: vec){
                if (node == mover) return true;
            }
        }
        vec.push_back(mover);
        mover = mover -> next;
    }
    return false;
}

/*
BETTER APPROACH
---------------------
LOGIC - Using a unoredered set
Take a hashmap
Traverse the linked list
While traversing for every node, put every node in the unordered set (hashset)
also while traversing, If you find any node already present in the set, return true

TIME COMPLEXITY - O(N) Unordered set has average case complexity of O(1) and worse case O(N) cause it rely on hashtable. 
SPACE COMPLEXITY - O(N) Unordered set
*/

bool check_loop_better( Node *head ){
    if (!head) return false;
    unordered_set <Node*> set;
    Node *mover = head;
    while (mover){
        if (set.find(mover) != set.end()) return true;
        else set.insert(mover);
        mover = mover -> next;
    }
    return false;
}

/*
OPTIMAL APPROACH
-----------------
LOGIC - TORTOISE HARE
Take two node pointers front and back
Initialize both with head
move the front pointer two step forward
move the back pointer one step forward
If the linked list is looped then the front and the back will meet.

If there is no loop, the fast pointer will eventually reach NULL and the function will return False (no cycle).
If a loop exists, both pointers will eventually enter the cycle.
Inside the cycle, the fast pointer moves twice as fast as the slow pointer.
Since they are moving at different speeds in a closed loop, the fast pointer must eventually catch up to the slow pointer—this confirms the presence of a cycle.

Why does the fast pointer eventually catch the slow pointer?
Imagine both are running on a circular track. The fast pointer effectively "laps" the slow pointer.
With each move, the fast pointer reduces the gap between itself and the slow pointer.
Eventually, the fast pointer will collide with the slow pointer, proving that a cycle exists.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

bool check_loop_optimal( Node *head ){
    if (!head) return false;

    Node *front = head;
    Node *back = head;

    while (front && front->next){
        if (front == back) return true;
        front = front -> next -> next;
        back = back -> next;
    }
    
    return false;
}

int main() {
    Node *head = example_linked_list();
    Node *mover = head;
    while (mover->next) mover = mover -> next;
    mover -> next = head -> next;
    bool is_looped = check_loop_optimal(head);
    if (is_looped) cout << "Linked list is looped !" << endl;
    else cout << "Linked list is not looped !" << endl;
}