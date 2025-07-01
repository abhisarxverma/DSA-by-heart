## PROBLEM - Given the head node of the linked list, and an integer K, reverse the nodes of the linked list in the k group and return the head of the new linked list.


### ✅ BRUTE FORCE APPROACH - *Using Vector*
-------------------------------------------------------------------------------------------------
- **LOGIC** - *Put k group in a vector reverse that and add to a main vector*

    - Traverse the linked list using a temp pointer.
    - Collect nodes in a short_vec for every group of k.
    - If temp becomes nullptr, stop collecting and don’t add null to the vector.
    - After collecting up to k nodes:
    - If short_vec.size() < k, append as-is to main_vec.
    - Else, reverse short_vec and add to main_vec.
    - Repeat until entire list is processed.
    - Reconstruct the final linked list from main_vec using a dummy node.
    - Return dummy->next as the head of the new list.

- **TIME COMPLEXITY** - ***O(2N) - O(N) to put into the main vector + O(N) to turn the main vector back into the linked list***
- **SPACE COMPLEXITY** - ***O(N)+O(K)***

### ✅ OPTIMAL APPROACH - *Changing Links*
---------------------------------------------------------------
- **LOGIC** - *Changing Links*
    - Use a dummy node to simplify edge handling at the head.
    - Loop through the list, processing k nodes at a time.
    - For each group:
    - Use find_kth_node to check if a complete group exists.
    - Temporarily detach the group using groupEnd->next = nullptr.
    - Reverse the isolated group with reverse_linked_list.
    - Reconnect the reversed group to the previous and next sections.
    - Move prevGroupEnd forward to process the next group.
    - Return the updated head via dummy.next.

- **TIME COMPLEXITY** - ***O(2N) - O(N) for main traversal + O(N) cause reversal of the k groups in worst case can take O(N) like in case of k = 1 ***
- **SPACE COMPLEXITY** - ***O(1) In place changing links and reversing***


<div style="display: flexbox; text-align: center; font-family: monospace; margin-top: 70px;">
    <h1>THANK YOU!</h1>
</div>