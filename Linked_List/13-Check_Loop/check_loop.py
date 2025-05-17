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

'''
PROBLEM - Given a Head Node of the linked list, check if the linked list is looped, means that there is no end or the end is again pointing to any node in linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a vector
Take a vecor
Traverse the linked list, and for every node loop through the vector to find the node
if you find the node, return true
else put the node in the vector

TIME COMPLEXITY - O(N x N) Double looping in vector for every node
SPACE COMPLEXITY - O(N) vector
'''

def check_loop_brute( head: Node ):
    if not head: return False

    array = []

    mover = head
    while mover:
        if array:
            for node in array:
                if node == mover: return True

        array.append(mover)
        mover = mover.next
    
    return False

'''
BETTER APPROACH
---------------------
LOGIC - Using a unordered set (Built in Python)
Take a Unordered Set.
Traverse the linked list
While traversing for every node, put every node in the unordered set (hashset)
also while traversing, If you find any node already present in the set, return true

TIME COMPLEXITY - O(N) Unordered set has average case complexity of O(1) and worse case O(N) cause it rely on hashtable. 
SPACE COMPLEXITY - O(N) Unordered set
'''

def check_loop_better( head: Node ):
    if not head: return False

    unordered_set = set()
    mover = head
    while mover:
        if mover in unordered_set: return True
        unordered_set.add(mover)
        mover = mover.next

    return False

'''
OPTIMAL APPROACH
-----------------
LOGIC - TORTOISE HARE
Take two node pointers front and back
Initialize both with head
move the front pointer two step forward
move the back pointer one step forward
If the linked list is looped then the front and the back will meet.

If there is no loop, the fast pointer will eventually reach NULL and the function will return False (no cycle).
If a loop exists, both pointers will eventually enter the cycle.
Inside the cycle, the fast pointer moves twice as fast as the slow pointer.
Since they are moving at different speeds in a closed loop, the fast pointer must eventually catch up to the slow pointer—this confirms the presence of a cycle.

Why does the fast pointer eventually catch the slow pointer?
Imagine both are running on a circular track. The fast pointer effectively "laps" the slow pointer.
With each move, the fast pointer reduces the gap between itself and the slow pointer.
Eventually, the fast pointer will collide with the slow pointer, proving that a cycle exists.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
'''

def check_loop_optimal( head: Node ):
    if not head: return False

    front = head
    back = head
    while front and front.next:
        front = front.next.next
        back = back.next
        if front == back: return True
    
    return False

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

# Making the linked list looped by joining the last node to the third node
mover = head
while mover.next: mover = mover.next
mover.next = head.next.next

print("Linked List is looped !" if check_loop_optimal(head) else "Linked list is Just fine bro!")