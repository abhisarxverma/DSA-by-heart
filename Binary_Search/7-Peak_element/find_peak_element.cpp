#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 
PROBLEM - Given an array, find the peak element and return the index of that element.
For the extremes you can assume that the number before the left extreme is -infinite and the number after the right extreme is -infinite
Peak element - The element in the array which is greater than the left number and greater than the right number.
*/

/*
Brute Force Approach
---------------------
LOGIC - Linear search- Go over the array one by one and check for the conditions and return the index if the conditions are met.
TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

int find_peak_element_brute( vector<int> array ){
    int n = array.size();
    for (int i = 0; i < n; i++){
        if ( (i == 0 || array[i] > array[i-1]) && (i==n-1 || array[i] > array[i+1]) ) return i;
    }

    return -1;
}

/*
Optimal Approach
---------------------
LOGIC - Binary search - Cause the left and right side of the array will be sorted.
TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
*/

int find_peak_element_optimal( vector<int> array ){
    int n = array.size();
    if (array.size() == 1) return 0;
    if (array[0] > array[1]) return 0;
    if (array[n-1] > array[n-2]) return n-1;

    int low = 1;
    int high = n-2;

    while ( low <= high ){
        int mid = low + (high-low)/2;
        if ( array[mid] > array[mid-1] && array[mid] > array[mid+1] ) return mid;
        if ( array[mid] < array[mid-1] ) high = mid-1;
        else if ( array[mid] < array[mid+1] ) low = mid+1;
    }

    return -1;
}

int main() {
    vector<int> array = {5, 4, 3, 2, 1};
    int peak_element_index = find_peak_element_optimal(array);
    cout << "Peak element index: " << peak_element_index << endl;
}