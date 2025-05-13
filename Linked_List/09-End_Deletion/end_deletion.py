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
PROBLEM - Given a Head node, delete the last node and return the new head.

APPROACH
---------
LOGIC - 
To delete the last node we will have to go to the last second node
When we reach the last second node, we just have to make that node's next to None
Cause python's garbage collection automatically free the not used space.
return the head

TIME COMPLEXITY - O(Size of the array) 
SPACE COMPLEXITY - O(1)
'''

def end_deletion( head: Node ):
    if not head:
        print("Linked List is Empty!")
        return head
    if not head.next: return None

    mover = head
    while mover.next.next:
        mover = mover.next

    mover.next = None
    return head