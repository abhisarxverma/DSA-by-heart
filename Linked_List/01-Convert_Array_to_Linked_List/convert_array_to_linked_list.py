from typing import List

# Linked List Node Implementation
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
APPROACH
---------

LOGIC - One by One Iterate over array and join into the linked list
Start by creating a temporary node (temp) with dummy data (-1). 
This serves as a placeholder to simplify insertion.
Use a mover pointer initialized to temp to track where new nodes should be added.
For each element in the array:
Create a new node with the current value.
Attach it to the next pointer of mover.
Move mover forward to the newly created node for the next insertion.
Once the iteration completes, the final linked list starts from temp->next, excluding the dummy node.
Using temp makes inserting nodes seamless, avoiding extra logic for handling the first node separately.

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
'''

def array_to_linked_list( array: List[int] ):
    temp = Node(-1)
    mover = temp
    for value in array:
        mover.next = Node(value)
        mover = mover.next
    
    return temp.next


array = {1, 5, 10, 15, 20, 25}
head = array_to_linked_list(array)
traverse_linked_list(head)

array2 = {}
head2 = array_to_linked_list(array2)
traverse_linked_list(head2)