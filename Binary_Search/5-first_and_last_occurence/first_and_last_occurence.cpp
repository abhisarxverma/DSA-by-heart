#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* PROBLEM - Given the sorted array and the number, return the first and the last occurence of the number in the array using binary search */

/*
Brute Force Approach
---------------------
LOGIC - Find the first find the first occurence and then the last occurence and then return the answer together.
TIME COMPLEXITY - O(2 LOGN) 
SPACE COMPLEXITY - O(1)
*/

pair<int, int> first_and_last_occurence_brute( vector<int> array, int number ){

    // First let's find the first occurence

    int first_occurence = -1;

    int low = 0, high = array.size()-1;
    while ( low <= high ){
        int mid = low + (high-low)/2;
        if ( array[mid] >= number ){
            if ( array[mid] == number ) first_occurence = mid;
            high = mid-1;
        }
        else low = mid+1;
    }

    // Maybe the number does not exist in the array
    if (first_occurence == -1) return {-1, -1};

    // Now let's find the Last occurence

    int last_occurence = -1;

    low = 0, high = array.size()-1;
    while ( low <= high ){
        int mid = low + (high-low)/2;
        if (array[mid] <= number){
            if (array[mid] == number) last_occurence = mid;
            low = mid+1;
        }
        else high = mid-1;
    }

    return {first_occurence, last_occurence};
}

/*
Optimal Force Approach
---------------------
LOGIC - First occurence is nothing but the lower bound, and last occurence is nothing but the upperbound of the number-1.
TIME COMPLEXITY - O(2 LOGN) 
SPACE COMPLEXITY - O(1)
*/

int lower_bound( vector<int> array, int number ){
    int low = 0;
    int high = array.size();
    while ( low < high ){
        int mid = low + (high-low)/2;
        if ( array[mid] >= number ) high = mid;
        else low = mid+1;
    }
    return low;
}

int upper_bound( vector<int> array, int number ){
    int low = 0;
    int high = array.size();
    while ( low < high ){
        int mid = low + (high-low)/2;
        if ( array[mid] <= number ) low = mid+1;
        else high = mid;
    }
    return low;
}

pair<int, int> first_and_last_occurence_optimal( vector<int> array, int number ){
    int first_occurence = lower_bound(array, number);
    if (array[first_occurence] != number) return {-1, -1};
    int last_occurence = upper_bound(array, number);
    return {first_occurence, last_occurence-1};
}

int main() {
    vector<int> array = {1, 5, 6, 6, 10, 50, 83, 83, 83, 156, 1000};
    pair<int, int> ans = first_and_last_occurence_optimal( array, 83);
    cout << "Original array : " ;
    for (auto num : array) cout << num << " ";
    cout << endl;
    cout << "First occurence : " << ans.first << endl;
    cout << "Last occurence : " << ans.second << endl;
}