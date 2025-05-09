#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

/*
PROBLEM - Divide the given array into given k parts such that the maximum sum from the formed subarrays is the minimum.

EXAMPLE INPUT - [10, 20, 30, 40], n = 2
EXAMPLE OUTPUT - 60
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear search
We have to find the minimum of maximum sums if subarrays so we will loop linearly from low to highest answer possible
We will take low as the maximum number in array, cause the by starting from the maximum we can put all the numbers in array.
We will take high as the sum of array, cause the we can only divide the array into subarrays with the total sum only.
While looping for each number we will check if dividing the array into subarrays according to the current loop limit will give k subarrays or not.
As we are looping from low to high, the first time we will find answer we will retutn that.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

//Helper function to check the number of subarrays formed from the given limit sum
bool check_k_subarrrays(vector<int> array, int k, int limit){
    int subarray_count = 1;
    int last_subarray_sum = 0;

    for (auto num : array){
        if (last_subarray_sum + num > limit){
            subarray_count++;
            last_subarray_sum = num;
        }
        else last_subarray_sum += num;
    }

    return subarray_count == k;
}

int k_subarray_sum_brute(vector<int> array, int k){
    int low = *max_element(array.begin(), array.end());
    int high = accumulate(array.begin(), array.end(), 0);

    for (int i = low; i <= high; i++){
        if ( check_k_subarrrays(array, k, i) ) return i;
    }

    return -1;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
We set the range for binary search based on possible values for array division:
low = max(array) → The least possible maximum load (A subarray must have atleast one number, so the largest number in array is the minimum division).
high = sum(array) → The worst case, no subarray division, the whole array is the subarray.
We perform binary search on this range:
Pick mid = (low + high) / 2 as the potential maximum division.
Check if we can get the "k" subarrays with the division with this limit.
If it's possible → This can be the possible answer, so save it in "ans" variable which will be initialized as -1, and then Try to reduce division limit (high = mid - 1).
If it's not possible → Increase division limit (low = mid + 1).
Once binary search completes, "ans" variable holds the minimum possible maximum that gives the k subarrays.

TIME COMPLEXITY - O(N * Log(sum-max(array))) 
SPACE COMPLEXITY - O(1)
*/

int k_subarray_sum_optimal(vector<int> array, int k){
    int low = *max_element(array.begin(), array.end());
    int high = accumulate(array.begin(), array.end(), 0);
    int ans = -1;

    while ( low <= high ){
        int mid = low + (high-low)/2;
        if ( check_k_subarrrays(array, k, mid) ){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    return ans;
}

int main() {
    vector<int> array = {10, 20, 30, 40};
    int k = 2;
    cout << "Minimum of the Maximum sums : " << k_subarray_sum_brute(array, k) << endl;
}