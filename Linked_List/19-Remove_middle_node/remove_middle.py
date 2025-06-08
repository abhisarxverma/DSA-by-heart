
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
PROBLEM - Given the head node of the linkd list, remove the middle node and return the head of the new linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Counting the length
First count the length of the linked list
Then go one node before the "total length / 2" and delete that

TIME COMPLEXITY - O(N + N/2) N to count, N/2 to delete
SPACE COMPLEXITY - O(1) 
'''

def remove_middle_brute( head: Node ):
    if not head or not head.next : return None

    length = 0
    mover = head
    while mover:
        length += 1
        mover = mover.next

    node_to_delete = length//2
    mover = head
    for i in range(1, node_to_delete):
        mover = mover.next

    mover.next = mover.next.next
    return head

'''
BETTER APPROACH
---------------------
LOGIC - Little Observation - The middle node increases by one when the length increases by two.
Take a length counter
Take a prev node pointer
Take a mover node pointer
Move the mover while the mover does not become null
And in the loop, evertime the length becomes even, just move the prev pointer
At end of the loop, you will have your prev at the one node before the middle
Just delete that the normal process and return the head.

TIME COMPLEXITY - O(N/2)
SPACE COMPLEXITY - O(1)
'''

def remove_middle_better( head: Node ):
    if not head or not head.next: return None

    length = 0
    prev = None
    mover = head
    middle = head
    while mover:
        length += 1
        if length % 2 == 0:
            prev = middle
            middle = middle.next
        mover = mover.next

    prev.next = middle.next
    return head

'''
OPTIMAL APPROACH
---------------------
LOGIC - TORTOISE HARE ALGORITHM
Logic here is same that the middle moves one step when the length moves two step
but the implementation will be more simple and startight forward
take two node pointer variables fast and slow
run a while loop till the fast and the fast's next is not null
and in the loop move the fast two step and the slow one step
When the loop will end the slow is the middle node
but to remove the middle node we have to go one node before the middle
so we will also maintain a prev node pointer that will save the previous middle if the middle changes
and then we will remove the middle with normal procedure and then return the head

TIME COMPLEXITY - O(N/2)
SPACE COMPLEXITY - O(1)
'''

def remove_middle_optimal( head: Node ):
    if not head or not head.next: return None

    fast = head
    slow = head
    prev = None

    while fast and fast.next:
        fast = fast.next.next
        prev = slow
        slow = slow.next

    prev.next = slow.next
    return head

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)
traverse_linked_list(head)
head = remove_middle_optimal(head)
traverse_linked_list(head)