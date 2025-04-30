#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* PROBLEM - Given the array, which was sorted but was rotated some number of times,
find the given target number and return the index.
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear search- Go over the array one by one and if you find the number return the index.
TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

int find_in_rotated_array_brute( vector<int> array, int target ){
    int n = array.size();
    for (int i = 0; i < n; i++){
        if ( array[i] == target ) return i;
    }
    return -1;
}

/* SUB PROBLEM - If all the elements are unique. */

/*
Optimal Approach
---------------------
LOGIC - Binary Search 
In a rotated sorted array, at least one half is always sorted.
Check if the left or right part is sorted by comparing the middle element with the leftmost element. 
If the target is within the sorted half, search there. Otherwise, move to the unsorted side where the rotation happened. 
Repeat the process until you find the number.

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
*/

int find_in_rotated_array_uniques_optimal( vector<int> array, int target ){
    int low = 0;
    int high = array.size()-1;
    while ( low <= high ){
        int mid = low + (high-low)/2;

        if ( array[mid] == target ) return mid;
        
        // let's check which side is sorted
        if ( array[low] <= array[mid] ){ // Left half is sorted
            if ( array[low] <= target && target < array[mid] ) high = mid-1;
            else low = mid+1;
        }
        else { // Right half is sorted
            if ( array[mid] < target && target <= array[high] ) low = mid+1;
            else high = mid-1;
        }
    }

    return -1;
}

/* SUB PROBLEM - If the array has duplicates */

/*
Optimal Approach
---------------------
LOGIC - Binary Search 
In a rotated sorted array, at least one half is always sorted.
Check if the left or right part is sorted by comparing the middle element with the leftmost element. 
If the target is within the sorted half, search there. Otherwise, move to the unsorted side where the rotation happened. 
Repeat the process until you find the number.

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
*/

int find_in_rotated_array_duplicates_optimal( vector<int> array, int target ){
    int low = 0;
    int high = array.size()-1;
    int result = -1;
    while ( low <= high ){
        int mid = low + (high-low)/2;

        if ( array[mid] == target ) {
            result = mid;
            high = mid-1;
        }

        if ( array[low] == array[mid] == array[high] ){
            low++;
            high--;
            continue;
        }

        if ( array[low] <= array[mid] ){
            if ( array[low] <= array[mid] && target < array[mid] ) high = mid-1;
            else low = mid+1;
        }
        else {
            if ( array[mid] < target && target <= array[high] ) low = mid+1;
            else high = mid-1;
        }
    }
    return result;
}

int main() {
    vector<int> array = {21, 35, 35, 93, 1, 5, 7, 7, 9, 10, 11, 15};
    int ans = find_in_rotated_array_duplicates_optimal(array, 7);
    cout << "Ans : " << ans << endl;
}