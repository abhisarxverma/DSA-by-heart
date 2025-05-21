# PROBLEM - Given a Head Node of the linked list, find and return the starting node of the loop in the linked list if the loop exists else return null.


### ✅ BRUTE FORCE APPROACH - *Using Vector*
---------------------------------------------
- **LOGIC** - *Using a vector to store the visited nodes*
    - Take a vector
    - Traverse the linked list, put the node in the vector
    - And in every loop check if the node is already present in the vector by looping
    - If yes return the node, else move on
    - At last return Nullptr.

- **TIME COMPLEXITY** - ***O(N x N) Double looping in vector for every node***
- **SPACE COMPLEXITY** - ***O(N) vector***


### ✅ BETTER APPROACH - *Using set*
---------------------------------------------------------------
- **LOGIC** - *Using a unordered set for O(1) lookup*
    - Take a unordered set
    traverse the linked list
    - first check the set if it have the current node
    - if yes return the mover
    - if not put the mover in the set
    - at last return the nullptr

- **TIME COMPLEXITY** - ***O(N) Unorderet set has O(1) lookup due to hashing***
- **SPACE COMPLEXITY** - ***O(N) Unordered set***


### ✅ OPTIMAL APPROACH - *Tortoise Hare Algorithm*
---------------------------------------------------------------
- **LOGIC** - *TORTOISE HARE METHOD*
    - Take two node pointer variables - `front` and `back`
    - Initialize both of them with the `head`;
    - loop till the `front` if not null and the front's `next` is not null
    - in the loop move the `front` two setps and `back` one step
    - If the loop ends return the `nullptr` casue the linked list is not looped
    - But if the linked list is looped, then they both will meet 
    - And at the node in which they meet, you have to perform a simple loop to get the starting node of loop
    - we will take a new node pointer and initialize that also with the `head`
    - And with a loop, we will move the `new` and the `front` pointer together everytime
    - And at the point they both meet, that is the starting node of the loop.

<details>
  <summary>🔹 <strong>Why Do Front and the Back Pointer Meet?</strong></summary>
  <ul>
    <li>Think of a running track:</li>
    <li>The slow pointer moves one step at a time.</li>
    <li>The fast pointer moves two steps at a time.</li>
    <li>If there's a loop, the fast pointer will keep moving in circles until it catches up to the slow pointer.</li>
    <li>Since the fast pointer closes the gap with every step, it will eventually meet the slow pointer inside the cycle.</li>
</ul>
</details>

<details>
  <summary>🔹 <strong>Why Is the Distance the Same?</strong></summary>
  <ul>
    <ul>
    Let’s define:
        <li>D = Distance from head to loop start</li>
        <li>X = Distance from the front to the back in the loop</li>
    </ul>
    <li>The Idea here is that when the front and the back start moving, and when the back reaches the starting node (we are assuming that we know which one is starting node), let that distance between the head and the starting node be D.</li>
    <li>So when the back will be standing at the starting node, the front will be at double the distance of the head and the start, so the distance from the back to front will also be D</li>
    <li>And then the distance from the front to back let's take X</li>
    <li>So to collide the back pointer moved X distance to meet the front, and let's say they are now at same node.</li>
    <li>so if the back moved X distance to meet the front from the starting node, then the remaining distance from the collision node to the starting node will be D. cause Loop length = D + X</li>
    <li>And D is nothing but the distance from the head to the starting node of the loop</li>
    <li>That's how the distance from the head to the start and the distance from the collision node to the start is the same.</li>
</ul>
</details></br>
 
- **TIME COMPLEXITY** - ***O(N)***
- **SPACE COMPLEXITY** - ***O(1)***

<div style="display: flexbox; text-align: center; font-family: monospace;">
    <h1>THANK YOU!</h1>
</div>