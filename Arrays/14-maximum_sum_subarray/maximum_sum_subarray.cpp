#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// PROBLEM - MAXIMUM SUBARRAY SUM - Find the maximum sum that can be taken by summing any contiguous part of the array

/*
Brute Force Approach
---------------------
LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum sum
and return the greatest.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int maximum_sum_subarray_brute( vector<int> array ){
    int n = array.size();
    int final_sum = INT_MIN;
    for (int i = 0; i < n ; i++){
        int temp_sum = array[i];
        for (int j = i+1; j < n ; j++){
            temp_sum += array[j];
            final_sum = max(final_sum, temp_sum);
        }
    }
    return final_sum;
}

/*
Optimal Approach
---------------------
LOGIC - KADANE'S ALGORITHM - While looping in the array, store the sum, if the sum drops to negative
then turn it back to zero, and if the sum is positive then keep it increasing

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int maximum_sum_subarray_optimal( vector<int> array ){
    int n = array.size();
    long long final_sum = LLONG_MIN;
    long long sum = 0;
    for (auto num : array){
        sum += num;
        if (sum < 0) sum = 0;
        final_sum = max(final_sum, sum);
    }
    return final_sum;
}

// check

int main(){
    vector<int> vec = {1, 5, 9, 6, -10};
    cout << "Maximum sum : " << maximum_sum_subarray_brute(vec) << endl;
    return 0;
}