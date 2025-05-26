
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
PROBLEM - Given the head node of the linked list, you have to group the nodes at the odd index and the nodes at
the even indexes and put the odd ones first and then the evens and return the head of the new linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using the Vector
Take a vector
Traverse only the odd index nodes and add them in the vector
Traverse only the even index nodes and add them in the vector
Traverse the whole linked list again and put the data from the vector to the linked list as the vector is alreay grouped 
Cause we first put the data at the odd and then the evens.

TIME COMPLEXITY - O(2N) First loop to put the data and second loop to put the grouped data
SPACE COMPLEXITY - O(N) Vector
'''

def group_brute(head: Node):
    if not head or not head.next: return head
    
    vec = []

    odd = head
    while odd and odd.next:
        vec.append(odd.data)
        odd = odd.next.next

    even = head.next
    while even and even.next:
        vec.append(even.data)
        even = even.next.next

    mover = head
    for num in vec:
        mover.data = num
        mover = mover.next

    return  head

'''
OPTIMAL APPROACH
---------------------
LOGIC - Linking the odds to odds and evens to evens
Take two node pointers odd and even, and also do not forget to save the even head that we have to link the odd to evens
Run a while loop till the even and even's next is not null
While in the loop
Connect the odd to the odd's next's next
Connect the even to the even's next's next
Move the odd to it's new next which will also be the odd one cause we have connected it before
Move the even to it's new next like odd
When the loop get's over, we have grouped the odds and evens but we still need to join them
So make the odd's next to the even head that we have saved earlier
yes odd will have the last node of the odd group

TIME COMPLEXITY - O(N) Single iteration
SPACE COMPLEXITY - O(1)
'''

def group_optimal( head: Node ):
    if not head or not head.next: return head

    odd = head
    even = head.next
    even_head = head.next

    while even and even.next:
        odd.next = odd.next.next
        even.next = even.next.next
        odd = odd.next
        even = even.next

    odd.next = even_head
    return head
    
head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)
traverse_linked_list(head)

grouped = group_optimal(head)
traverse_linked_list(head)