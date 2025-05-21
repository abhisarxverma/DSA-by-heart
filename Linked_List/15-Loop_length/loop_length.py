from typing import List

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

def create_loop( head: Node, position: int ):
    if not head or position < 1: return head

    loopstart = None
    counter = 1
    mover = head
    while mover.next:
        if counter == position: loopstart = mover
        mover = mover.next
        counter += 1

    mover.next = loopstart

    return head

'''
PROBLEM - Given a Head node of the linked list, return the length of the loop if there exists a loop
in the linked list else return 0

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a vector
We will first find the starting node of the loop
Take a vector
Take a counter varible which will count the total number of nodes we have moved till we found the loop
Traverse the linked list
Check if the current node is already present in the vector
if yes then, the loop length will be the counter - index of the starting node in vector
If not, then add the node to the vector and move on
Return 0, cause if the loop ends there exists no loop in the linked list.

TIME COMPLEXITY - O(N x N) Double looping in vector for every node
SPACE COMPLEXITY - O(N) vector
'''

def loop_length_brute( head: Node ) -> int :
    if not head : return 0

    vec = []
    mover = head
    counter = 0
    while mover:   
        for node in vec:
            if node == mover: return counter
        vec.append(mover)
        counter += 1
        mover = mover.next

    return 0
'''
BETTER APPROACH
---------------------
LOGIC - Using a Unordered Map ( O(1) lookup time )
We will first find the starting node of the loop
Take a unordered map
Take a counter = 0
Traverse the linked list
check if the node is already in the map
if yes return the "counter - node's value in the map"
else add the node in the map
If the loop gets over return 0, cause there is no loop

TIME COMPLEXITY - O(N) Unordered map has O(1) lookup
SPACE COMPLEXITY - O(N) unordered map
'''

def loop_length_better( head: Node ):
    if not head: return None

    map = {}
    mover = head
    counter = 0
    while mover:
        if mover in map:
            return counter - map[mover]
        map[mover] = counter
        counter += 1
        mover = mover.next

    return 0

'''
OPTIMAL APPROACH
---------------------
LOGIC - TORTOISE HARE APPROACH
Take two node pointer variables front and the back
But this time take a counter variable also
loop till the front is not null and the front's next is not null
While in the loop move the front two steps and move the back one step and update the counter every time
If there is a loop they will collide and when they collide, the number of the counter is the loop lenght
When the loop exists return 0 cause there is no loop int he linked list

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
'''

def loop_length_optimal( head: Node ):
    if not head: return 0

    # First we will check if the loop exists 
    fast = head
    back = head
    while fast and fast.next:
        fast = fast.next.next
        back = back.next
        if fast == back: 
            break

    if not fast or not fast.next: return 0  # The loop does not exists

    # Now we will take a counter and counte the loop length by moving a temp pointer till it reaches itself
    temp = back
    counter = 0
    while True:
        temp = temp.next
        counter += 1
        if temp == back : break

    return counter


head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)
traverse_linked_list(head)

head = create_loop(head, 3)
looplength = loop_length_optimal(head)
print(f"Loop Length: {looplength}")