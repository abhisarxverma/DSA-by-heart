#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

/*
PROBLEM - Given the array of weights of the products and a integer which is the days you have to make the delivery find the minimum capacity of the ship that if you use the whole days you can do the job

EXAMPLE INPUT - [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5
EXAMPLE OUTPUT - 15
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear Search 
We will loop from max weight in the array to the sum of weights in array, cause the capacity must be able to take one but any box in array that's why the max
And we will search till the sum of the weights cause above the sum, the days will always remain the same that is 1 and will never change, so if the answer exists, that should be sum itself or below that
So while looping check the days taken by looping over the wieghts and adding to a current weights variable if the current weights surpass the capacity then this means that that weight will be taken next day
so we will increment the day count and make the current weight to 0.
As we are looping from minimum capacity possible to maximum capacity possible we will return the answer as soon as we find one.

TIME COMPLEXITY - O(N * [Sum(array) - Max(array)]) 
SPACE COMPLEXITY - O(1)
*/

// Helper function
bool check_days_taken(vector<int> weights, int days, int capacity){
    int required_days = 1;  // Start with day 1
    int current_weight = 0;

    for (int weight : weights) {
        if (current_weight + weight > capacity) {
            required_days++;  // Move to the next day
            current_weight = 0;  // Reset ship load
        }
        current_weight += weight;
    }

    return required_days <= days;  
}

int minimum_capacity_brute(vector<int> weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    for (int capacity = low; capacity <= high; capacity++) {
        if ( check_days_taken(weights, days, capacity) ) return capacity;
    }

    return -1;  // Should never hit this
}

/*
Optimal Approach
---------------------
LOGIC - Binary Search 
We do not know that the array of weights we are given is sorted or not but what we do know is that we will find the answer betweent the max in array and the sum in array which is sorted space, we can easily to the binary search there.
We will take low as max weight in the array, cause the capacity must be able to take one but any box in array that's why the max
And we will search till the sum of the weights cause above the sum, the days will always remain the same that is 1 (because all the weights will get delivered in one day) and will never change, so if the answer exists, that should be sum itself or below that


TIME COMPLEXITY - O(N * LOG[Sum(array) - Max(array)]) 
SPACE COMPLEXITY - O(1)
*/

int minimum_capacity_optimal(vector<int> weights, int days){
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low < high){
        int mid = low + (high-low)/2;
        if (check_days_taken(weights, days, mid)) high = mid;
        else low = mid+1;
    }

    return (check_days_taken(weights, days, low)) ? low : -1;

}


int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans_minimum_capacity = minimum_capacity_brute(weights, 5);
    cout << "Minimum capacity : " << ans_minimum_capacity << endl;
}