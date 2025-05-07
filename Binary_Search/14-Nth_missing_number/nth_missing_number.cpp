#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

/*
PROBLEM - Given an array of the sorted increasing integers and an integer "n", you have to tell the "nth missing number.

EXAMPLE INPUT - [1, 3, 5, 6, 8, 10], n = 4
EXAMPLE OUTPUT - 9
*/

/*
Brute Force Approach
---------------------
LOGIC - 
1. Start by setting a variable `missing_number` equal to n, since if nothing interferes, the nth missing number should be n.  
2. Loop through each number in the array.  
3. For every number in the array that is less than your current `missing_number`, realize that this number is present, so it "pushes" the missing count forward.  
4. Increment `missing_number` for each such present number to adjust for the shift.  
5. Once you encounter numbers in the array that are greater than the current `missing_number`, further values won't affect its position.  
6. The value in `missing_number` after processing is the nth missing number; return that.


TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

int nth_missing_number_brute( vector<int> array, int n ){
    int missing_number = n;

    for (auto num : array){
        if (num > missing_number) break;
        missing_number ++;
    }

    return missing_number;
}

/*
Optimal Approach
---------------------
LOGIC - BINARY SEARCH - Cause the ans will exist in between the 0 and the max in array which is sorted.
1. Start a binary search over the sorted array by initializing high and high boundaries.
2. For each iteration, compute mid = (low + high) / 2.
3. Calculate the number of missing numbers up to mid using: missing_count = array[mid] - (mid + 1).
4. If missing_count is greater than or equal to n, then the nth missing number could be at mid or to its left, so narrow the search by moving the high boundary to mid.
5. Otherwise (if missing_count is less than n), the nth missing number lies to the right, so move the low boundary to mid + 1.
6. Continue until the search boundaries converge. The final (high index + n) is carrying the missing number. Also low will carry the answer cause we are stopping if low == high.

TIME COMPLEXITY - O(Log(Max(array))) 
SPACE COMPLEXITY - O(1)
*/

int nth_missing_number_optimal( vector<int> array, int n ){
    int low = 0;
    int high = *max_element(array.begin(), array.end());

    while ( low < high ){
        int mid = low + (high-low)/2;
        int missing_numbers = array[mid] - (mid+1);
        if (missing_numbers >= n) high = mid;
        else low = mid+1;
    }

    return high + n;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    int n = 4;
    int ans = nth_missing_number_optimal(array, n);
    cout << n << "th missing number for ";
    for (auto num : array) cout << num << " ";
    cout << endl;
    cout << ans << endl;
}