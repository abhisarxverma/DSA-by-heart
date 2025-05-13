
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def tarverse_linked_list( head: Node ):
    """Traverse and print the data of the linked list."""
    if not head: print("Linked List is Empty.")
    else:
        mover = head
        while mover:
            print(mover.data, end=" -> " if mover.next else "\n")
            mover = mover.next


'''
PROBLEM - Given head (Node object) of Linked List, return the length of the linked list.

APPROACH
---------
LOGIC - Traverse the Linked List and calculate the length
Take a counter variable "length"
Take a mover pointer variable, move the mover to it's next till the mover becomes None and increment the count ever time.

TIME COMPLEXITY - O(Size of Linked List) 
SPACE COMPLEXITY - O(1)
'''

def linked_list_length( head: Node ):
    length = 0
    mover = head
    while mover:
        length += 1
        mover = mover.next

    return length