#include "../Linked_List.h"
#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEM - Given the head node of the linked list, you have to group the nodes at the odd index and the nodes at
the even indexes and put the odd ones first and then the evens and return the head of the new linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using the Vector
Take a vector
Traverse only the odd index nodes and add them in the vector
Traverse only the even index nodes and add them in the vector
Traverse the whole linked list again and put the data from the vector to the linked list as the vector is alreay grouped 
Cause we first put the data at the odd and then the evens.

TIME COMPLEXITY - O(2N) First loop to put the data and second loop to put the grouped data
SPACE COMPLEXITY - O(N) Vector
*/

Node *group_brute(Node * head){
    if (!head || !head->next) return head;

    vector<int> vec;
    Node *odd_mover = head;
    while (odd_mover && odd_mover -> next){
        vec.push_back(odd_mover -> data);
        odd_mover = odd_mover -> next -> next;
    }

    Node *even_mover = head -> next;
    while (even_mover && even_mover -> next){
        vec.push_back(even_mover -> data);
        even_mover = even_mover -> next -> next;
    }

    Node *mover = head;
    for (int i = 0; i < vec.size(); i++){
        mover -> data = vec[i];
        mover = mover -> next;
    }

    return head;
}


/*
OPTIMAL APPROACH
---------------------
LOGIC - Linking the odds to odds and evens to evens
Take two node pointers odd and even, and also do not forget to save the even head that we have to link the odd to evens
Run a while loop till the even and even's next is not null
While in the loop
Connect the odd to the odd's next's next
Connect the even to the even's next's next
Move the odd to it's new next which will also be the odd one cause we have connected it before
Move the even to it's new next like odd
When the loop get's over, we have grouped the odds and evens but we still need to join them
So make the odd's next to the even head that we have saved earlier
yes odd will have the last node of the odd group

TIME COMPLEXITY - O(N) Single iteration
SPACE COMPLEXITY - O(1)
*/

Node * group_optimal( Node *head ){
    if (!head || !head -> next) return head;

    Node *odd = head;
    Node *even = head -> next;
    Node *even_head = head -> next;

    while (even && even -> next){
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;
        odd = odd -> next;
        even = even -> next;
    }

    odd -> next = even_head;
    return head;
}

int main() {
    Node * head = example_linked_list();
    traverse_linked_list(head);
    head = group_optimal(head);
    traverse_linked_list(head);
}