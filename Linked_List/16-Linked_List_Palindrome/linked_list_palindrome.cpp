#include "../Linked_List.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
PROBLEM - Given a head node of the linked list, check if the linked list is palindrome and accordingly return True or False.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a Stack [But we have to before hand know the linked list data type]
Take a stack
Traverse the linked list
PUt the elements in the stack
Traverse the linked list again and every time check for the top element in the stack
the moment it is not the same, return false
At last return true

TIME COMPLEXITY - O(2N) First loop to put elements, second loop to compare
SPACE COMPLEXITY - O(N) Stack
*/

bool linked_list_palindrome_brute( Node * head ){
    if (!head) return false;

    stack <int> st;
    Node *mover = head;
    while (mover) {
        st.push(mover -> data);
        mover = mover -> next;
    }

    mover = head;
    while(mover) {
        if (mover -> data != st.top()) return false;
        st.pop();
        mover = mover -> next;
    }

    return true;
}

/*
BETTER APPROACH
---------------------
LOGIC - Using a vector
Take a vector
Traverse the linked list, put the elements in the vector
Then check if the vector is palindrome using the optimal method which takes O(N/2) time
And return according to the result

TIME COMPLEXITY - O(N + (N/2)) N for putting the elements in vector and N/2 for checking
SPACE COMPLEXITY - O(N) vector
*/

bool linked_list_palindrome_better( Node *head ){
    if (!head) return false;

    vector <int> vec;
    Node *mover = head;
    while (mover) {
        vec.push_back(mover -> data);
        mover = mover -> next;
    }

    int n = vec.size();
    int front = 0;
    int back = n-1;
    while (front < back){
        if (vec[front] != vec[back]) return false;
        front++;
        back--;
    }
    return true;
}

/*
OPTIMAL APPROACH
---------------------
LOGIC - Tortoise Hare approach
Take two node pointer variables fast and slow
First we will get to the middle node of the linked list using the tortoise hare method of moving the fast two steps and slow one step till the fast is null
Then we will reverse the linked list after the middle node using the link changing method by taking the front and back
Then we will take a first and the second node pointer and move them simultaneously till the second becomes null
Why second? Cause in case of even length both the linked list will end at same time and in case of odd the second will end first so we will check till that only
And while traversing both we will compare them and if we find not equal then we will return false
But before that, we cannot leave the linked list distorted, it's unprofessional, so we will reverse back the linked list after the middle
And the linked list will be back to original, you may think that is there not need to joing back the left and the middle ?
No, there is no need cause, the left part that is the middle has it's next pointed to it's next from starting to end even after reversing, just the linked list after middle got reversed and then we reversed it back and that's why there is not need for that
And this is also one of the reason that while comparing we go till the second becomes null, cause the first is not distorted and it is referencing to the middle's next node all the time.
And finally, we will return true;

TIME COMPLEXITY - O(N/2 + N/2) = O(N)
SPACE COMPLEXITY - O(1)
*/

// HELPER FUNCTION TO REVERSE THE LINKED LIST
Node *reverse_linked_list( Node * head){
    Node *front = nullptr;
    Node *back = nullptr;
    Node *mover = head;
    while(mover){
        Node *front = mover -> next;
        mover -> next = back;
        back = mover;
        mover = front;
    }
    return back;
}

bool linked_list_palindrome_optimal( Node *head ){
    if (!head) return false;

    Node *fast = head;
    Node *slow = head;
    while(fast && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    Node *reversed_head = reverse_linked_list(slow -> next);
    
    Node *first = head;
    Node *second = reversed_head;
    while(second) {
        if (first -> data != second -> data){
            Node *middle = reverse_linked_list(reversed_head);
            return false;
        }
        first = first -> next;
        second = second -> next;
    }
    return true;
}

int main() {
    Node *head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next = new Node(1);
    traverse_linked_list(head);
    bool ans = linked_list_palindrome_optimal(head);
    if (ans){
        cout << "Yes the linked list is palindrome!";
    }
    else {
        cout << "No the linked list is not palindrome!";
    }
}