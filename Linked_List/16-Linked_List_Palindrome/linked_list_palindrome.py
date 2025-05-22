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
PROBLEM - Given a head node of the linked list, check if the linked list is palindrome and accordingly return True or False.

BRUTE FORCE APPROACH
---------------------
LOGIC - Using a Stack [But we have to before hand know the linked list data type]
Take a stack
Traverse the linked list
PUt the elements in the stack
Traverse the linked list again and every time check for the top element in the stack
the moment it is not the same, return false
At last return true

TIME COMPLEXITY - O(2N) First loop to put elements, second loop to compare
SPACE COMPLEXITY - O(N) Stack
'''

def linked_list_palindrome_brute( head: Node ) -> bool :
    if not head: return False

    vec = []
    mover = head
    while mover:
        vec.append(mover.data)
        mover = mover.next

    mover = head
    while mover:
        if vec.pop(-1) != mover.data: return False
        mover = mover.next

    return True

'''
BETTER APPROACH
---------------------
LOGIC - Using a vector
Take a vector
Traverse the linked list, put the elements in the vector
Then check if the vector is palindrome using the optimal method which takes O(N/2) time
And return according to the result

TIME COMPLEXITY - O(N + (N/2)) N for putting the elements in vector and N/2 for checking
SPACE COMPLEXITY - O(N) vector
'''

def linked_list_palindrome_better( head: Node ):
    if not head: return False

    vec = []
    mover = head
    while mover:
        vec.append(mover.data)
        mover = mover.next

    front = 0
    back = len(vec)-1
    while front < back:
        if vec[front] != vec[back] : return False
        front += 1
        back -= 1

    return True

'''
OPTIMAL APPROACH
---------------------
LOGIC - Tortoise Hare approach
Take two node pointer variables fast and slow
First we will get to the middle node of the linked list using the tortoise hare method of moving the fast two steps and slow one step till the fast is null
Then we will reverse the linked list after the middle node using the link changing method by taking the front and back
Then we will take a first and the second node pointer and move them simultaneously till the second becomes null
Why second? Cause in case of even length both the linked list will end at same time and in case of odd the second will end first so we will check till that only
And while traversing both we will compare them and if we find not equal then we will return false
But before that, we cannot leave the linked list distorted, it's unprofessional, so we will reverse back the linked list after the middle
And the linked list will be back to original, you may think that is there not need to joing back the left and the middle ?
No, there is no need cause, the left part that is the middle has it's next pointed to it's next from starting to end even after reversing, just the linked list after middle got reversed and then we reversed it back and that's why there is not need for that
And this is also one of the reason that while comparing we go till the second becomes null, cause the first is not distorted and it is referencing to the middle's next node all the time.
And finally, we will return true;

TIME COMPLEXITY - O(N/2 + N/2) = O(N)
SPACE COMPLEXITY - O(1)
'''

# HELPER FUNCTION TO REVERSE THE LINKED LIST
def reverse_linked_list( head: Node ):
    front = None
    back = None
    mover = head
    while mover:
        front = mover.next
        mover.next = back
        back = mover
        mover = front
    
    return back

def linked_list_palindrome_optimal( head: Node ):
    if not head: return False

    fast = head
    slow = head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next

    reversed_head = reverse_linked_list(slow.next)

    first = head
    second = reversed_head
    while second:
        if first.data != second.data: 
            reverse_linked_list(reversed_head)
            return False
        first = first.next
        second = second.next

    return True

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(2)
head.next.next.next.next = Node(1)

traverse_linked_list(head)
ans = linked_list_palindrome_optimal(head)
if ans:
    print("Yes the linked list is palindrome.")
else:
    print("No the linked list is not palindrome.")
