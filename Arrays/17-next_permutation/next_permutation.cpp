#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// PROBLEM - Given an array, find the next permutation of the array.

// Input : {5, 2, 9, 7, 3}
// Output : {5, 3, 2, 7, 9}

/*
Optimal Approach
---------------------
LOGIC - To make the next permutation, we need to find the number from the right which is shorter than it's next number
this means that the next permutation will change from this number, so store it's index as breakpoint, so then we will go and find the maximum number
in the right part of the array of that breakpoint, and when found, swap the breakpoint number and the max number, 
cause we found the break point, and the next permutation will have the maximum number on it's right at the breakpoint
and then simply reverse the right part of breakpoint and you have your next permutation.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

// C++ builtin next_permutation implementation
vector<int> next_permutation(vector<int>& A) {
    int index = -1, n = A.size();

    // Step 1: Find the rightmost index where A[i] < A[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: If no valid index, reverse the array to get smallest permutation
    if (index == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 3: Find the rightmost element greater than A[index] & swap
    for (int i = n - 1; i > index; i--) {
        if (A[i] > A[index]) {
            swap(A[i], A[index]);
            break;
        }
    }

    // Step 4: Reverse the elements on the right to get next lexicographical order
    reverse(A.begin() + index + 1, A.end());

    return A;
}

int main() {
    vector<int> vec = {5, 2, 9, 7, 3};
    vector<int> next = next_permutation(vec);
    cout << "Next permutation: ";
    for (auto it: next) cout << it << " ";
    cout << endl;
    return 0;
}