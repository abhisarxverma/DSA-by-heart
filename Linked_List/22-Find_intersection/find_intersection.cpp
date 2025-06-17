#include "../Linked_List.h"
#include <iostream>
#include <unordered_set>
using namespace std;

/*
PROBLEM - Given two head nodes of the two linked list, find and the intersection node if any else return None

BRUTE FORCE APPROACH
---------------------
LOGIC - Double Iteration
Traverse any of the two linked list
And for every iteration, traverse the other linked list to find the same node
If found return the node else return None

TIME COMPLEXITY - O(NxM) Double Iteration
SPACE COMPLEXITY - O(1) 
*/

Node *find_intersection_brute( Node *head1, Node *head2 ){
    if (!head1 || !head2) return nullptr;

    Node *mover = head1;
    while (mover) {
        Node *mover2 = head2;
        while (mover2) {
            if (mover2 == mover) return mover;
            mover2 = mover2 -> next;
        }
        mover = mover -> next;
    }

    return nullptr;
}

/*
BETTER APPROACH
---------------------
LOGIC - Using hashset
Take an unordered set [It uses hashing for O(1) lookup]
Traverse any of the two linked list
And in every iteration, insert the node into the set
then traverse the second linked list and check for the node in the set
return node if found else return None at last

TIME COMPLEXITY - O(N+M) N to put into the hashset and M to check for intersection
SPACE COMPLEXITY - O(N) hashset
*/

Node *find_intersection_better( Node *head1, Node *head2 ){
    if ( !head1 || !head2 ) return nullptr;

    unordered_set <Node*> set;

    Node *mover = head1;
    while (mover){
        set.insert(mover);
        mover = mover -> next;
    }

    mover = head2;
    while (mover) {
        if (set.find(mover) != set.end()) return mover;
        mover = mover -> next;
    }

    return nullptr;
}

/*
OPTIMAL APPROACH
-----------------
LOGIC - Continuous Looping
Take two node pointer variables which will be the mover of the both of the linked list
Run a while loop till both the movers become equal
in the loop move both the movers to their next
then check if both the movers are equal return any of the mover
the trick is here
if any of the mover becomes null, make that mover head node of the other linked list
In this way we are comparing every node in the two linked lists
If you think how will the loop end if there is no intersection in both linked list
The loop will end when both the movers will become null which will happen for sure if the intersection is not there


TIME COMPLEXITY - O(N + M)
SPACE COMPLEXITY - O(1) 
*/

Node *find_intersection_optimal( Node *head1, Node *head2 ){
    if (!head1 || !head2) return nullptr;
    
    Node *mover1 = head1;
    Node *mover2 = head2;
    while (mover1 != mover2){
        mover1 = mover1 -> next;
        mover2 = mover2 -> next;
        if (mover1 == mover2) return mover1;
        if (!mover1) mover1 = head2;
        if (!mover2) mover2 = head1;
    }

    return nullptr;
}

int main() {
    Node *head = example_linked_list();
    Node *head2 = new Node(3);
    head2 -> next = new Node(99);
    head2 -> next -> next = new Node(150);
    head2 -> next -> next -> next = head -> next -> next -> next -> next;
    cout << "List 1 : ";
    traverse_linked_list(head);
    cout << "List 2 : ";
    traverse_linked_list(head2);
    Node *ans = find_intersection_optimal(head, head2);
    cout << "Intersection : " << ans -> data << endl;

}