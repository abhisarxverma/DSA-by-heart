#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

/*
PROBLEM - Given an array of integers which are the stalls and the value is their position. Place the given number of cows in such a way that the minimum distance between them is the maximum distance possible for the arrangement of the given number of cows

EXAMPLE INPUT - [1, 2, 4, 8, 9], n = 3
EXAMPLE OUTPUT - 3 (1, 4, 8)
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear search
We have to find the minimum distance between the cows that is also the maximum distance possible to place the n cows.
So we will backwards from the maximum distance stall cause we cannot place not even a single cow beyond that.
And while iterating we will check the number of the cows we are able to place with that minimum distance.
We will have a variable to count the cows_placed and a variable to store the stall in which we have placed the last cow
So that we can calculate and check if the current stall is valid to place cow according to the minimum distance.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

int arrange_cows_brute( vector<int> stalls, int n ){
    int max_distance = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
    for (int i = max_distance; i >= 1; i--){
        int cows_placed = 1;
        int last_cow_stall = stalls[0];
        for (int j = 1; j < stalls.size(); j++){
            if ( stalls[j]-last_cow_stall >= i ){
                cows_placed++;
                last_cow_stall = stalls[j];
            }
        }
        if (cows_placed >= n) return i;
    }
    return -1 ;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
The possible minimum distances range from 1 to max(stalls) - min(stalls).
We perform binary search over this range.
Pick mid = (low + high) / 2 as the candidate minimum distance.
Try placing cows at this distance using a greedy approach (always placing the next cow at the earliest valid stall).
If cows can be placed successfully, increase low = mid + 1 (try larger distances).
Otherwise, decrease high = mid - 1 (try smaller distances).
The last valid mid before low > high gives the maximum possible minimum distance for optimal cow placement.

TIME COMPLEXITY - O(N * Log(Max-Min)) 
SPACE COMPLEXITY - O(1)
*/

// Helper function to count number of cows placed
bool check_cows_placed(vector<int>& stalls, int n, int distance) {
    int total_cows_placed = 1;
    int last_cow_stall = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_cow_stall >= distance) {  // Fixed comparison issue
            total_cows_placed++;
            last_cow_stall = stalls[i];
        }
        if (total_cows_placed >= n) return true;  // Early exit for efficiency
    }
    return false;
}

int arrange_cows_optimal(vector<int>& stalls, int n) {
    sort(stalls.begin(), stalls.end());  // Sorting is required

    int low = 1;
    int high = stalls.back() - stalls.front();
    int result = -1;

    while (low <= high) {  // Corrected binary search condition
        int mid = low + (high - low) / 2;

        if (check_cows_placed(stalls, n, mid)) {
            result = mid;
            low = mid + 1;  // Move towards larger minimum distance
        } else {
            high = mid - 1;  // Reduce search space
        }
    }
    return result;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows_to_place = 3;
    cout << "Cows to place : " << arrange_cows_optimal(stalls, cows_to_place) << endl;
}