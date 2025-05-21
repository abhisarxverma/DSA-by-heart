
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

def example_linked_list() -> Node :
    head = Node(10)
    head.next = Node(15)
    head.next.next = Node(20)
    head.next.next.next = Node(25)
    head.next.next.next.next = Node(30)
    head.next.next.next.next.next = Node(35)
    head.next.next.next.next.next.next = Node(40)

    return head
