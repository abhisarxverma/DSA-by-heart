
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
PROBLEM - Given the Head Node Object, and an integer to insert at start of the linked list, add and return the head of the new linked list.

APPROACH
---------
LOGIC - Make a New Node with the data equal to the number given
Make Head's next the New Node.
Make the Head the New Node.
Return the Head.

TIME COMPLEXITY - O(1) 
SPACE COMPLEXITY - O(1)
'''

def insert_at_start( head: Node, number: int ) -> Node :
    head = Node(number, head)
    return head