#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;

// PROBLEM - Given an array of integers, return the longest length of the contiguous subarray that sum 0.

/*
 EXAMPLE INPUT - -3, 7, 2, -2, -7 
 EXAMPLE OUTPUT - 4
*/

/*
Brute Approach
---------------------
LOGIC - Take a final length variable and Loop over the array , then loop over the right part of the current number in first array, if you find the 
sum 0, update the final length if greater.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int longest_subarray_to_zero_brute( vector<int> array ){
    int n = array.size();
    int final_length = 0;
    for (int i = 0; i < n; i++){
        int temp_length = 1;
        int sum = array[i];
        for ( int j = i+1; j < n; j++){
            temp_length++;
            sum += array[j];
            if ( sum == 0 ) final_length = max(final_length, temp_length);
        }
    }
    return final_length;
}

/*
Optimal Approach
---------------------
LOGIC - 
Use a hashmap to store prefix sums while looping over the array. The subarray sum can be zero in two cases:
Direct zero sum: If the prefix sum itself becomes 0, the subarray length is index + 1.
Previously seen prefix sum: If the prefix sum appears in the hashmap, removing the earlier portion leads to a zero-sum subarray. The length in this case is current index - stored index.
Update the final length if a longer subarray is found, while storing indices of prefix sums for future reference. 🚀

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
*/

int longest_subarray_to_zero_optimal( vector<int> array ){
    int n = array.size();
    int final_length = 0;
    int prefix_sum = 0;
    map <int, int> mpp;
    for (int i = 0; i < n; i++){
        prefix_sum += array[i];
        if ( prefix_sum == 0 ){
            int length = i+1;
            final_length = max(final_length, length);
        }
        else if ( mpp.find(prefix_sum) != mpp.end() ){
            int length = i - mpp[prefix_sum];
            final_length = max(length, final_length);
        }
        mpp[prefix_sum] = i;
    }
    return final_length;
}

int main() {
    vector<int> vec = {-3, 7, 2, -2, -7 };
    int longest = longest_subarray_to_zero_optimal(vec);
    cout << "Longest subarray to zero : " << longest << endl;
}