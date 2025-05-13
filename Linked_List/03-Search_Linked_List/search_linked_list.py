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
PROBLEM - Given Head Node of the linked list and a number to find in the interger, return true if found else return false

APPROACH
---------

LOGIC - Complete Linked List iteration
Take a mover pointer variable, and using that traverse the linked list while checking the mover's data 
if found the number return True else return False

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
'''

def search_linked_list( head: Node, number: int ):
    if not head:
        print("Linked List is Empty!")
        return head
    mover = head
    while mover:
        if mover.data == number: return True
        mover = mover.next

    return False