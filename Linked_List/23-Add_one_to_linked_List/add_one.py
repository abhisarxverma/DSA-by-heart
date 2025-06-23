
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

'''
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
'''

def reverse_linked_list(head: Node):
    if not head or not head.next: return head

    reversed_head = reverse_linked_list(head.next)

    head.next.next = head
    head.next = None
    
    return reversed_head

def add_one_brute(head: Node):
    if not head: return None

    reversed = reverse_linked_list(head)

    carry = 1
    prev = None
    mover = reversed
    
    while mover:
        sum = mover.data + carry
        mover.data = sum % 10
        carry = sum // 10
        prev = mover
        mover = mover.next

    if carry: prev.next = Node (1)
    return reverse_linked_list(reversed)

'''
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
'''

def get_remaining(temp: Node):
    if not temp: return 1
    carry = get_remaining(temp.next)
    temp.data += carry
    if temp.data < 10:
        return 0
    else:
        temp.data = 0
        return 1
    
def add_one_optimal(head: Node):
    if not head: return None

    carry = get_remaining(head)
    if carry: return Node(1, head)
    return head

head = Node(1, Node(2, Node(3, Node(4, Node(9)))))
traverse_linked_list(head)
head = add_one_optimal(head)
traverse_linked_list(head)