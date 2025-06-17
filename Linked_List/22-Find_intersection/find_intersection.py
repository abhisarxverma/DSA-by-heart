
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
PROBLEM - Given two head nodes of the two linked list, find and the intersection node if any else return None

BRUTE FORCE APPROACH
---------------------
LOGIC - Double Iteration
Traverse any of the two linked list
And for every iteration, traverse the other linked list to find the same node
If found return the node else return None

TIME COMPLEXITY - O(NxM) Double Iteration
SPACE COMPLEXITY - O(1) 
'''

def find_intersection_brute( head1: Node, head2: Node ):
    if not head1 or not head2: return None

    mover1 = head1

    while mover1:
        mover2 = head2

        while mover2:
            if mover1 == mover2: return mover1
            mover2 = mover2.next

        mover1 = mover1.next

    return None   

'''
BETTER APPROACH
---------------------
LOGIC - Using hashset
Take an unordered set [It uses hashing for O(1) lookup]
Traverse any of the two linked list
And in every iteration, insert the node into the set
then traverse the second linked list and check for the node in the set
return node if found else return None at last

TIME COMPLEXITY - O(N+M) N to put into the set and M to check the intesection
SPACE COMPLEXITY - O(N) hashset
'''

def find_intersection_better( head1: Node, head2: Node ):
    if not head1 or not head2: return None

    hashset = set()
    mover = head1

    while mover:
        hashset.add(mover)
        mover = mover.next

    mover = head2

    while mover:
        if mover in hashset: return mover
        mover = mover.next

    return None

'''
OPTIMAL APPROACH
-----------------
LOGIC - Continuous Looping
Take two node pointer variables which will be the mover of the both of the linked list
Run a while loop till both the movers become equal
in the loop move both the movers to their next
then check if both the movers are equal return any of the mover
the trick is here
if any of the mover becomes null, make that mover head node of the other linked list
In this way we are comparing every node in the two linked lists
If you think how will the loop end if there is no intersection in both linked list
The loop will end when both the movers will become null which will happen for sure if the intersection is not there


TIME COMPLEXITY - O(N + M)
SPACE COMPLEXITY - O(1) 
'''

def find_intersection_optimal( head1: Node, head2: Node ):
    if not head1 or not head2: return None

    mover1 = head1
    mover2 = head2

    while mover1 != mover2:
        mover1 = mover1.next
        mover2 = mover2.next
        if mover1 == mover2: return mover1
        if not mover1: mover1 = head2
        if not mover2: mover2 = head1

    return None

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

head2 = Node(23)
head2.next = Node(99)
head2.next.next = Node(37)
head2.next.next.next = head.next.next.next.next # Intersect bot the linked lists

print("List 1 : ", end="")
traverse_linked_list(head)
print("List 2 : ", end="")
traverse_linked_list(head2)

ans = find_intersection_optimal(head, head2)
print("Intersection: ", ans.data)