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
PROBLEM - Given the head node of the linked list which have numbers 0s, 1s and 2s, sort the linked list and return the head of the sorted linked list.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using Vector
Take all the data of the linked list in an array
Sort the array then put the data back in the linked list.

TIME COMPLEXITY - (3N log N) - O(N) to put the data in array + O(N Log N) Sorting + O(N) To put the data back in linked list
SPACE COMPLEXITY - O(N) array
'''

def sort_zeros_ones_and_twos_brute(head: Node):
    if not head or not head.next: return head

    arr = []
    mover = head
    while mover:
        arr.append(mover.data)
        mover = mover.next

    arr = sorted(arr)

    mover = head
    for num in arr:
        mover.data = num
        mover = mover.next

    return head

'''
BETTER APPROACH
---------------------
LOGIC - Counting the occurences
Traverse the linked list
While traversing update the count of the 0s 1s and 2s
after getting count traverse the linked list again putting the values according to the occurences
return the head

TIME COMPLEXITY - O(2N) - O(N) To get the counts + O(N) To put the data in sorted way
SPACE COMPLEXITY - O(1)
'''

def sort_zeros_ones_and_twos_better(head: Node):
    if not head or not head.next: return head

    zeros_count = 0
    ones_count = 0
    twos_count = 0

    mover = head
    while mover:
        if mover.data < 1: zeros_count += 1
        elif mover.data == 1: ones_count += 1
        else: twos_count += 1
        mover = mover.next

    mover = head
    while mover:
        if zeros_count: 
            mover.data = 0
            zeros_count -= 1
        elif ones_count :
            mover.data = 1
            ones_count -= 1
        else: 
            mover.data = 2
            twos_count -= 1

        mover = mover.next

    return head     
    

'''
OPTIMAL APPROACH
---------------------
LOGIC - Taking three seperate linked list and joining them
1. Create Three Dummy Nodes
One dummy node each for:
0s list
1s list
2s list
Let’s call them:
zeroHead, oneHead, twoHead
Initialize each with a dummy value (e.g., -1 or any placeholder)
These dummy nodes make list handling easy and clean.

2. Create Three Tails (Moving Pointers)
These will help us append elements to the correct list:
zeroTail, oneTail, twoTail
Initially, point them to their respective dummy nodes.

3. Traverse Original Linked List
For each node in the list:
If it's 0: append it to the 0s list using zeroTail
If it's 1: append to the 1s list
If it's 2: append to the 2s list
After appending, move the corresponding tail forward.

4. Link the Three Lists
We now have:
A dummy-headed list of 0s
A dummy-headed list of 1s
A dummy-headed list of 2s

Now we join them:
Set twoTail->next = nullptr to avoid loops.
Join:
oneTail->next = twoHead->next (skip dummy)
Join:
zeroTail->next = oneHead->next (or twoHead->next if 1s list is empty)
🧠 What If Some Lists Are Empty?
If 1s are missing:
oneTail == oneHead → .next will point directly to 2s
If 0s are missing:
zeroTail == zeroHead → .next will point to 1s or 2s
This chain ensures the result is always correct.

TIME COMPLEXITY - O(2N) - O(N) To get the counts + O(N) To put the data in sorted way
SPACE COMPLEXITY - O(1)
'''

def sort_zeros_ones_and_twos_optimal( head: Node ):
    if not head or not head.next: return head

    zeroDummyHead = Node(-1)
    zeroTail = zeroDummyHead
    oneDummyHead = Node(-1)
    oneTail = oneDummyHead
    twoDummyHead = Node(-1)
    twoTail = twoDummyHead

    mover = head
    while mover:
        if mover.data < 1:
            zeroTail.next = mover
            zeroTail = mover

        elif mover.data == 1:
            oneTail.next = mover
            oneTail = mover

        else: 
            twoTail.next = mover
            twoTail = mover

        mover = mover.next

    twoTail.next = None
    oneTail.next = twoDummyHead.next
    zeroTail.next = oneDummyHead if oneDummyHead.next else twoDummyHead

    return zeroDummyHead.next

head = Node(0)
head.next = Node(2)
head.next.next = Node(1)
head.next.next.next = Node(0)
head.next.next.next.next = Node(2)
head.next.next.next.next.next = Node(1)
head.next.next.next.next.next.next = Node(1)

traverse_linked_list(head)
head = sort_zeros_ones_and_twos_optimal(head)
traverse_linked_list(head)