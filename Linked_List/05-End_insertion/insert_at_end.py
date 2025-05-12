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
PROBLEM - Given a Head Node and an integer to insert at the end of the linked list, insert and return the head of the new linked list.

APPROACH
---------
LOGIC - Take a mover pointer variable with the value head.
mover the mover forward, till the next node of the mover becomes null.
Now the mover is the last node of the linked list.
Make a new node with the data equal to the number given, and make it next to the mover
return the head.

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
'''

def insert_at_end( head: Node, number: int ):
    mover = head
    while mover.next:
        mover = mover.next

    mover.next = Node(number)
    return head