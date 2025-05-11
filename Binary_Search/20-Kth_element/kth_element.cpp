#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/*
PROBLEM - Given two sorted arrays and an integer "k", find and return the element from the merged sorted array, that is at the kth index.

ARRAY1 = {1,2, 3}
ARRAY2 = {4, 5, 6, 7};
k = 5

OUTPUT = 5
*/

/*
Brute Force Approach
---------------------
LOGIC - Return the kth index element, after merging the two sorted arrays.
Do the merging with the traditional merging process of the mergesort.
After merging return the kth index number from the merged array.

TIME COMPLEXITY - O(N+M) 
SPACE COMPLEXITY - O(N) 
*/

double kth_element_brute(vector<int> array1, vector<int> array2, int k) {
    int n = array1.size();
    int m = array2.size();
    int i = 0, j = 0;
    vector<int> merged;

    while (i < n && j < m) {
        if (array1[i] < array2[j]) { 
            merged.push_back(array1[i]);
            i++;
        } else {
            merged.push_back(array2[j]);
            j++;
        }
    }

    while (i < n) {
        merged.push_back(array1[i]);
        i++;
    }
    while (j < m) {
        merged.push_back(array2[j]);
        j++;
    }

    if (k >= merged.size()) return -1;
    
    return (double)merged[k]; 
}

/*
Better Approach
---------------------
LOGIC - While merging, return the kth element
Perform the merging procedure of the mergesort,
And instead of having a whole merged array, simply count the number of merging done till k
And once the merging reach the "k", then return that number.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1) 
*/

double kth_element_better(vector<int> array1, vector<int> array2, int k){
    int n = array1.size();
    int m = array2.size();
    int i = 0, j = 0;
    int count = 0;

    while ( i < n && j < m ){
        if ( array1[i] < array2[j] ) {
            count++;
            if ( count == k ) return array1[i];
            i++;
        }
        else {
            count++;
            if ( count == k ) return array2[j];
            j++;
        }
    }

    while ( i < n ){
        count++;
        if ( count == k ) return array1[i];
        i++;
    }
    while ( j < m ){
        count++;
        if ( count == k ) return array2[j];
        j++;
    }

    return -1;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search
Use binary search on the smaller array to optimize operations.
Partition both arrays such that the left half contains exactly k elements, ensuring correct positioning of the Kth element.
Maintain four boundary values:
l1 → Largest element in the left partition of array1
l2 → Largest element in the left partition of array2
r1 → Smallest element in the right partition of array1
r2 → Smallest element in the right partition of array2
Check if l1 ≤ r2 and l2 ≤ r1, ensuring a valid partition.
If valid, return the maximum of l1 and l2, as it represents the Kth smallest element.
If l1 > r2, move left in binary search.
Else, move right in binary search.

TIME COMPLEXITY - O(Log min(N,M)) 
SPACE COMPLEXITY - O(1) 
*/

double kth_element_optimal(vector<int> array1, vector<int> array2, int k){
    int n1 = array1.size();
    int n2 = array2.size();
    
    // Ensure a is the smaller array
    if (n1 > n2) return kth_element_optimal(array2, array1, k);

    int low = max(0, k - n2), high = min(k, n1);
    int left = k;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? array1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? array2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? array1[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? array2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return -1; 
}

int main() {
    vector<int> array1 = {1, 2, 3};
    vector<int> array2 = {4, 5, 6, 7};
    int k = 4;
    cout << k << "th element : " << kth_element_optimal(array1, array2, k) << endl;
}