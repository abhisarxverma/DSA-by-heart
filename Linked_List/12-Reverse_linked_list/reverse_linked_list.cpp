#include "../Linked_List.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/*
PROBLEM - Given a Head Node of the linked list, reverse the linked list and return the new head.

(But for using both the brute force, we have to know beforehand what type of the data is in the linked list, 
cause while initializing the vector or the stack of the queue, we have to premention the type.
For example I assumed that the linked list will have the integer data, but that can be of any type.)

BRUTE FORCE APPROACH 1
----------------------
LOGIC - Using a vector 
Take a vector "v"
Traverse the whole linked list and add the data in the vector
Now loop over the vector in the backward order and update the data sequence in the linked list
return the head

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(N)
*/

Node *reverse_linked_list_brute1( Node * head ){
    if (!head) return nullptr;

    vector<int> v;

    Node * mover = head;
    while (mover){
        v.push_back(mover -> data);
        mover = mover -> next;
    }

    reverse(v.begin(), v.end());

    mover = head;
    int i = 0;
    while (mover){
        mover -> data = v[i++];
        mover = mover -> next;
    }

    return head;
}

/*
BRUTE FORCE APPROACH 2
----------------------
LOGIC - Using Stack
Take a stack
Travese the linked list and put the data in the stack
Travese the linked list again but this time update the data by popping from data from the stack everytime
return the head

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(N)
*/

Node *reverse_linked_list_brute2( Node *head ){
    if (!head) return nullptr;
    stack <int> st;

    Node *mover = head;
    while (mover) {
        st.push(mover->data);
        mover = mover -> next;
    }

    mover = head;
    while (mover) {
        mover -> data = st.top();st.pop();
        mover = mover -> next;
    }
    return head;
}
/*
BETTER APPROACH
----------------------
LOGIC - Three Pointer Approach
Take three Node pointers - front, back and the mover
Initialize the front and the back node pointer with the nullptr
Initialize the mover node pointer with the head node
Run a while loop till the mover is not nullptr
And in the loop, we will do a simple thing, we will just take the one step back node and make it the current mover's next node
But the catch is that if we directly, make the current mover's next to the back, then how will we move forward?
So we will first save the next node of the mover in the front node pointer variable
And after saving, we will make the mover's next node the back node
Then we will make the back node, the current mover, cause this mover will be the back node for the next node
Then at last we will move the mover to the front node, which we saved earlier for this point.
When the loop ends, means the mover becomes nullptr, in the last iteration the mover (last node) was saved in the back
Now the back will be the head of the reversed linked list.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

Node *reverse_linked_list_better( Node *head ){
    if (!head) return nullptr;

    Node *front = nullptr;
    Node *back = nullptr;
    Node *mover = head;
    while (mover) {
        front = mover -> next;
        mover -> next = back;
        back = mover;
        mover = front;
    }
    return back;
}

/*
OPTIMAL APPROACH
----------------------
LOGIC - USING THE RECURSION
Base Case: If the list is empty (head == nullptr) or only has one node (head->next == nullptr), return the original list.
Recursive Case:
    Recursively call the function on the rest of the list (head->next).
    Move the current node two steps forward (head = head->next->next).
    Set the next pointer of the current node to nullptr to break the link.
    Return the reversed list starting from the new head (reversed_head).

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(N) Recursion call stack
*/

Node *reverse_linked_list_optimal( Node *head ){
    if (!head || !head->next) return head;
    Node *reversed_head = reverse_linked_list_optimal(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return reversed_head;
}

int main() {
    Node *head = example_linked_list();
    traverse_linked_list(head);
    head = reverse_linked_list_better(head);
    traverse_linked_list(head);
}