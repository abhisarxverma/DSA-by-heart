#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// PROBLEM - Given an array of intergers and an integer k, give the total number of subarrays that give the sum k.

/*
 EXAMPLE INPUT - 5, 2, 7, -2, 9 
 EXAMPLE OUTPUT - 3
*/

/*
Brute Approach
---------------------
LOGIC - Take a variable count Loop over every element, loop over every element on the right and add it while checking if the sum
is equal to k if yes increment the count.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int total_subarray_sum_to_k_brute( vector<int> array, int k ){
    int n = array.size();
    if (n == 0) return 0;

    int count = 0;

    for (int i = 0; i < n; i++){
        int sum = array[i];
        for (int j = i+1; j < n; j++){
            sum += array[j];
            if (sum == k) {
                count++;
            }
        }
    }
    return count;
}

/*
Optimal Approach - PREFIX SUM
------------------------------
LOGIC - Take a hashmp, and while iterating , put the sum and the number of elements that are giving that sum
to the hashmap, and also while iterating check if the hashmap contains [ current sum - k ] in it, if yes
add to the count the value from the hashmap, cause the main concept is that if you are above the required sum
and you have the sum in the storage, that means that we can remove and get the requrired sum. 

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N) hashmap
*/

int total_subarray_sum_to_k_optimal(vector<int> array, int k) {
    unordered_map<int, int> prefix_sum_map;  // HashMap to store cumulative sums and their counts
    int sum = 0, count = 0;

    prefix_sum_map[0] = 1;  // Base case: If sum is exactly 'k' at some point, we count from start

    for (int num : array) {
        sum += num;  // Update running sum
        
        // Check if (current_sum - k) exists in HashMap
        // This means we previously had a sum such that removing it results in sum = k
        if (prefix_sum_map.find(sum - k) != prefix_sum_map.end()) {
            count += prefix_sum_map[sum - k];  // Add occurrences of that sum to count
        }

        // Store frequency of current sum in HashMap
        prefix_sum_map[sum]++;
    }

    return count;
}


int main() {
    vector<int> vec = { 5, 2, 7, -2, 9 };
    int res = total_subarray_sum_to_k_optimal(vec, 7);
    cout << "Total count : " << res << endl;
}