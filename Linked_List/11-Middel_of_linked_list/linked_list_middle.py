
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
PROBLEM - Given a Head Node of the Linked List, return the middle node of the linked list, exact middle in case of odd length
and second middle in case of the even length.

BRUTE FORCE APPROACH
---------------------
LOGIC - Get the length first and then go to the middle node
Loop from the head, to the end of the linked list and update the count.
Then loop again n/2 times, and return the node.

TIME COMPLEXITY - O(N+(N/2)) = O(N) 
SPACE COMPLEXITY - O(1)
'''

def linked_list_middle_brute( head: Node ):
    if not head: return None

    length = 0
    mover = head

    while mover:
        length += 1
        mover = mover.next

    middle_position = length//2
    middle_node = head

    for i in range(0, middle_position):
        middle_node = middle_node.next

    return middle_node

'''
BETTER APPROACH
---------------------
LOGIC - When the count gets increased by 2 the middle node gets one step forward
Take a counter integer
Take a middle Node and initialize that with head
Take a mover Node and initialize that with head
Run a while loop till the mover is not nullptr and everytime increment the counter by 1.
Also in the loop, if the counter becomes even then move the middle node forward to it's next
When the loop will get over you will have your middle node in the middle node variable.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def linked_list_middle_better( head: Node ):
    if not head : return None

    length = 0
    middle_node = head
    mover = head

    while mover:
        length += 1
        if length % 2 : middle_node = middle_node.next
        mover = mover.next

    return middle_node
'''
OPTIMAL APPROACH
---------------------
LOGIC - Tortoise Hare Method
Take a front mover Node
Take a back mover Node
Loop till front is not null and the front's next is not null.
While in loop, every time
Move the front node two steps
Move the back node one step
When the loop ends you will have your middle node in the back node
This works on the same idea that the middle node moves forward one step every time the length of the sequence increases by two.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def linked_list_middle_optimal( head: Node ):
    if not head : return None

    front = head
    back = head

    while front and front.next:
        front = front.next.next
        back = back.next
    
    return back

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

middle = linked_list_middle_optimal(head)
print(f"Middle : {middle.data}")