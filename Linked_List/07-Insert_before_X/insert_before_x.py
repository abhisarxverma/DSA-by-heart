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
PROBLEM - Given a Head Node, an integer number to insert and an integer place_number before which you have to insert the number
insert the number and then return the head of the new linked list.

APPROACH
---------
LOGIC - Two Pointers
To insert a new node before a number that already exists in linked list, we have to take our mover to the one node before that number.
We will first check if head if null, if yes this means that the linked list is empty.
We will check that whether the number before which we have to insert is the head itself, if yes simply do the insertion at start method and return the new node
We will take two pointer variables, one front and one back, and initialize them with the head.
And in a while loop which will run till the front pointer becomes null, we will move both the pointers one one step
So here the front pointer is acting as a searcher that will search the number before which we have to insert the new number
And the when the front pointer will find the number before which we have to insert, then the back pointer will be the one node before
So we will everytime in loop check, that the front pointer's data is equal to the nubmer we are finding, if yes then
Make a new node, make the back pointer's next to the new node and new node's next to the front pointer. 
Insertion done return the head
If the front pointer becomes null, then this means that the number does not exist in the linked list.

TIME COMPLEXITY - O(Size of Linked List) 
SPACE COMPLEXITY - O(1)
'''

def insert_before_x( head: Node, number_to_insert: int, number_before_to_insert: int ) -> Node:
    if not head:
        print("Linked List is Empty!")
        return head
    if head.data == number_before_to_insert: return Node(number_to_insert, head)

    front_mover = head
    back_mover = front_mover

    while front_mover:
        if front_mover.data == number_before_to_insert:
            back_mover.next = Node(number_to_insert, front_mover)
            return head
        back_mover = front_mover
        front_mover = front_mover.next

    print(f"{number_before_to_insert} does not exist in the linked list.")
    return head