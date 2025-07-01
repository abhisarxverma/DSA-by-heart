
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def traverse_linked_list( head: Node ):
    """Traverse and print the data of the linked list."""
    if not head: print("Linked List is Empty.")
    else:
        mover = head
        while mover:
            print(mover.data, end=" -> " if mover.next else "\n")
            mover = mover.next

def example_linked_list() -> Node :
    head = Node(10)
    head.next = Node(15)
    head.next.next = Node(20)
    head.next.next.next = Node(25)
    head.next.next.next.next = Node(30)
    head.next.next.next.next.next = Node(35)
    head.next.next.next.next.next.next = Node(40)

    return head

'''
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
'''

def reverse_linked_list(head: Node):
    if not head: return None
    front = None
    back = None
    mover = head
    while mover:
        front = mover.next
        mover.next = back
        back = mover
        mover = front

    return back


def reverse_in_k_group_brute( head: Node , k: int ):
    if not head or k == 1: return head

    main_vec = []
    short_vec = []

    temp = head
    while temp:
        for i in range(k):
            if temp:
                short_vec.append(temp)
                temp = temp.next
            else: break
        
        if len(short_vec) < k:
            main_vec += short_vec
        
        else:
            main_vec += reversed(short_vec)

        short_vec = []

    dummy = Node(-1)
    dummyTail = dummy

    for node in main_vec:
        dummyTail.next = Node(node.data)
        dummyTail = dummyTail.next

    dummyTail.next = None

    return dummy.next


'''
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
'''

def find_kth_node( head: Node, k: int ):
    k -= 1
    while head and k:
        k -= 1
        head = head.next
    
    return head

def reverse_in_k_group_optimal(head: Node, k: int):
    if not head or k <= 1:
        return head

    dummy = Node(-1)
    dummy.next = head
    prevGroupEnd = dummy

    while True:
        groupStart = prevGroupEnd.next
        groupEnd = find_kth_node(groupStart, k)
        if not groupEnd:
            break

        nextGroupStart = groupEnd.next
        groupEnd.next = None

        reversedHead = reverse_linked_list(groupStart)

        prevGroupEnd.next = reversedHead
        groupStart.next = nextGroupStart

        prevGroupEnd = groupStart

    return dummy.next


head = example_linked_list()
traverse_linked_list(head)
ans = reverse_in_k_group_optimal(head, 2)
traverse_linked_list(ans)