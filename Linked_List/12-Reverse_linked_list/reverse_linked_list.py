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
'''

def reverse_linked_list_brute1( head: Node ):
    if not head: return None

    array = []

    mover = head
    while mover:
        array.append(mover.data)
        mover = mover.next
    
    array = array[::-1]

    mover = head
    i = 0
    while mover:
        mover.data = array[i]
        i += 1
        mover = mover.next
    
    return head

'''
BRUTE FORCE APPROACH 2
----------------------
LOGIC - Using Stack
Take a stack
Travese the linked list and put the data in the stack
Travese the linked list again but this time update the data by popping from data from the stack everytime
Cause stack will give you the data entered last, so the last data of the linked list will be added first
return the head

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(N)
'''

def reverse_linked_list_brute2( head: Node ):
    if not head: return None

    stack = []
    mover = head
    while mover:
        stack.append(mover.data)
        mover = mover.next

    mover = head
    while mover:
        mover.data = stack.pop(-1)
        mover = mover.next

    return head

'''
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
'''

def reverse_linked_list_better( head: Node ):
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

'''
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
'''

def reverse_linked_list_optimal( head: Node ):
    if not head or not head.next : return head

    reversed_head = reverse_linked_list_optimal(head.next)
    head.next.next = head
    head.next = None
    return reversed_head

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

traverse_linked_list(head)
head = reverse_linked_list_optimal(head)
traverse_linked_list(head)