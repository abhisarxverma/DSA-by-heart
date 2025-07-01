#include "../Linked_List.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
PROBLEM - Given the head node of the linked list, and an integer K, reverse the nodes of the linked list in the k group and return the head of the new linked list.

BRUTE FORCE APPROACH
------------------------------
LOGIC - Using a Vector
Traverse the linked list using a temp pointer.
Collect nodes in a short_vec for every group of k.
If temp becomes nullptr, stop collecting and don’t add null to the vector.
After collecting up to k nodes:
If short_vec.size() < k, append as-is to main_vec.
Else, reverse short_vec and add to main_vec.
Repeat until entire list is processed.
Reconstruct the final linked list from main_vec using a dummy node.
Return dummy->next as the head of the new list.

TIME COMPLEXITY - O(2N) - O(N) to put into the main vector + O(N) to turn the main vector back into the linked list
SPACE COMPLEXITY - O(N)+O(K) 
*/


Node * reverse_in_k_group_brute(Node *head, int k) {
    if (!head) return head;

    vector<Node *> main_vec;
    vector<Node *> short_vec;

    Node *temp = head;

    while (temp) {
        for (int i = 0; i < k; i++) {
            if (temp) {
                short_vec.push_back(temp);
                temp = temp->next;
            } else break;
        }
        if (short_vec.size() < k)
            main_vec.insert(main_vec.end(), short_vec.begin(), short_vec.end());
        else {
            reverse(short_vec.begin(), short_vec.end());
            main_vec.insert(main_vec.end(), short_vec.begin(), short_vec.end());
        }
        short_vec.clear();
    }

    Node *dummy = new Node(-1);
    Node *dummyTail = dummy;
    
    for (auto node : main_vec) {
        dummyTail -> next = new Node(node -> data);
        dummyTail = dummyTail -> next;
    }
    
    dummyTail -> next = nullptr;
    
    return dummy -> next;
    
}

/*
OPTIMAL APPROACH
------------------------------
LOGIC - Changing Links
Use a dummy node to simplify edge handling at the head.
Loop through the list, processing k nodes at a time.
For each group:
Use find_kth_node to check if a complete group exists.
Temporarily detach the group using groupEnd->next = nullptr.
Reverse the isolated group with reverse_linked_list.
Reconnect the reversed group to the previous and next sections.
Move prevGroupEnd forward to process the next group.
Return the updated head via dummy.next.

TIME COMPLEXITY - O(2N) - O(N) for main traversal + O(N) cause reversal of the k groups in worst case can take O(N) like in case of k = 1  
SPACE COMPLEXITY - O(1) In place changing links and reversing 
*/


Node *find_kth_node(Node *head, int k) {
    k--;
    while (head && k){
        head = head -> next;
        k--;
    }
    return head;
}

Node* reverse_in_k_group_optimal(Node* head, int k) {
    if (!head || k == 1) return head;

    Node dummy(0);
    dummy.next = head;
    Node* prevGroupEnd = &dummy;

    while (true) {
        Node* groupStart = prevGroupEnd->next;
        Node* groupEnd = find_kth_node(groupStart, k);
        if (!groupEnd) break;

        Node* nextGroupStart = groupEnd->next;
        groupEnd->next = nullptr;

        Node* reversedHead = reverse_linked_list(groupStart);

        prevGroupEnd->next = reversedHead;
        groupStart->next = nextGroupStart;

        prevGroupEnd = groupStart;
    }

    return dummy.next;
}


int main() {
    Node *head = example_linked_list();
    traverse_linked_list(head);
    Node *ans = reverse_in_k_group_brute(head, 2);
    traverse_linked_list(ans);
}