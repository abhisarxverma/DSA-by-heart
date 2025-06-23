#include "../Linked_List.h"
#include <iostream>
#include <unordered_set>
using namespace std;

/*
PROBLEM - Given the head node of a linked list having integers as datatype, return the new linked list that will be formed if 1 is added to the number forming after combining the data of the linked list.

BRUTE FORCE APPROACH
------------------------------
LOGIC - Reversing Linked List
Reverse the linked list to process digits from least to most significant.
Initialize two pointers: – mover to traverse the list – prev to track the last non-null node (for possible carry node insertion)
Start with carry = 1 and loop through the list:
Add the carry to mover->data
If the sum is less than 10, update the node and break (no more carry)
Else, set node to 0, keep carry = 1, and move forward
If carry remains after the loop, append a new node with value 1 using prev.
Reverse the list again and return the updated head.

TIME COMPLEXITY - O(3N) - O(N) to reverse + O(N) to traverse + O(N) to reverse again to return 
SPACE COMPLEXITY - O(N) Because we are using recursive reversal, can be O(1) if we use the iterative reversal 
*/

Node* reverse_linked_list_optimal(Node* head) {
    if (!head || !head->next) return head;

    Node* reversed_head = reverse_linked_list_optimal(head->next);
    head->next->next = head;
    head->next = nullptr;

    return reversed_head;
}

Node* add_one_brute(Node* head) {
    if (!head) return nullptr;

    Node* reversed = reverse_linked_list_optimal(head);

    Node* curr = reversed;
    Node* prev = nullptr;
    int carry = 1;

    while (curr) {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        prev = curr;
        curr = curr->next;
    }

    if (carry) {
        prev->next = new Node(carry);
    }

    return reverse_linked_list_optimal(reversed);
}

/*
OPTIMAL APPROACH
------------------------------
LOGIC - Recursion
Use recursion to reach the last node (least significant digit).
Add 1 at the base case, and propagate carry back through the stack:
If the sum is less than 10, update the node and return 0 (no carry).
If the sum is 10, set the node to 0 and return 1 (carry over).
In the main function, call the recursive helper:
If it returns 0, you're done—return the head.
If it returns 1, insert a new node with value 1 at the head (carry overflow).
Return the updated head of the list.

TIME COMPLEXITY - O(N) Recursive calls for every node in linked list
SPACE COMPLEXITY - O(N) Recursive call stacks
*/

int get_remaining(Node *temp) {
    if (!temp) return 1;
    int carry = get_remaining(temp -> next);
    temp -> data += carry;
    if (temp -> data < 10){
        return 0;
    }
    else {
        temp -> data = 0;
        return 1;
    }
}

Node *add_one_optimal(Node *head) {
    if (!head) return nullptr;

    int carry = get_remaining(head);
    if (carry) return new Node(1, head);
    return head;
}

int main() {
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(9)))));
    traverse_linked_list(head);
    head = add_one_optimal(head);
    traverse_linked_list(head);
}