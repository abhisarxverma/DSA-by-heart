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
PROBLEM - Given a Head Node, integer number and a positive integer which is the position number in the linked list at which to insert the number, insert and return the head of the new linked list.

APPROACH
---------
LOGIC - To insert a number at the given position, we will go to one node before the node at that position
Check if the position entered is smaller to zero, if yes, print error message and return the head
And also cause in this approach we are going to the one node before the position to insert, if the user enter the 1, then this approach may fail, so handle that case seperately.
Take a mover pointer variable, move the mover forward using a for loop running "position - 2" times
Add a check in the for loop that if the mover becomes none print the error message if you want and return head
cause the user may enter the position which is more than the linked list size.
When the for loop finishes we will be at the one position before the position we want to insert new number
But we have to check here again, cause if the user enters the position 2 greater than the linked list size, the mover will become null but not in the for loop but after that
And then make a new node with the data equal to the number given, make the new node's next the mover's next and make the mover's next the new node
return the head

TIME COMPLEXITY - O(Size of Array) 
SPACE COMPLEXITY - O(1)
'''

def insert_at_middle( head: Node, number: int, position: int ):
    if position < 1:
        print("Position Invalid: Cannot be less than 1")
        return head
    if position == 1: return Node(number, head)

    mover = head
    for i in range(1, position-1):
        if not mover:
            print("Position Invalid: More than array size")
            return head
        mover = mover.next

    if not mover:
        print("Position Invalid: More than array size")
        return head
    
    new_node = Node(number, mover.next)
    mover.next = new_node
    return head

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

inserted_head = insert_at_middle(head, 17, 8)
traverse_linked_list(inserted_head)
