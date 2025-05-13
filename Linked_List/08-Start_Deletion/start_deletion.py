
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
PROBLEM - Given a Head node, delete the first node and return the new head.

APPROACH
---------
LOGIC - 
In python, the not used space is freed automatically, so we do not have to free that manually
We will just move the head to it's next pointer
return new head

TIME COMPLEXITY - O(1) 
SPACE COMPLEXITY - O(1)
'''

def start_deletion( head: Node ):
    if not head:
        print("Linked List is Empty!")
        return None
    
    head = head.next 
    return head