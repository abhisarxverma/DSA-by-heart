
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
PROBLEM - Given a Head node, delete the first node and return the new head.

APPROACH
---------
LOGIC - To delete a node at the particular position in the linked list we have to go to one node before that position
We will handle the case in which the position given is 1 cause there is no node before that
We will run a for loop from 1 to position - 1 times, with moving the mover to it's next we will also do one check in loop
That if the mover becomes nullptr, then this means the position entered is out of the linked list, we will return head
When we come out of the loop there, the mover should be the one before node, so we will do deletion
We will just make the mover's next the mover's next's next, cause the python gargage collection automatically frees the space not used
But there is an edge case that you can miss, which is that if the user enters the position which is one more than the length of linked list
then the mover will be at last node, and there's no next node, and if we try to reach the mover's next's next we will get error
So after the loop completion, we will do one more check, if the mover's next is null, if yes, we will return the head cause this is also case of out of bound position.
return the head

TIME COMPLEXITY - O(Size of Linked List) 
SPACE COMPLEXITY - O(1)
'''

def middle_deletion( head: Node, position: int ):
    if not head:
        print("Linked List is Empty!")
        return head

    if position < 1:
        print("Position Invalid : Cannot be smaller than one")
        return head

    if position == 1:
        head = head.next
        return head
    
    mover = head
    for _ in range(1, position-1):
        if not mover:
            print("Position Invalid : More than the linked list size")
            return head
        mover = mover.next

    if not mover or not mover.next:
        print("Position Invalid : More than Linked list size.")
        return head
    
    mover.next = mover.next.next
    return head

head = Node(10)
head.next = Node(15)
head.next.next = Node(20)
head.next.next.next = Node(25)
head.next.next.next.next = Node(30)
head.next.next.next.next.next = Node(35)
head.next.next.next.next.next.next = Node(40)

new_head = middle_deletion(head, 5)
traverse_linked_list(new_head)