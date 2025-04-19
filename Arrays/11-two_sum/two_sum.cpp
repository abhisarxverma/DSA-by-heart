#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// Given an array and a sum tell if this sum is possible by adding any two elements in an array

/*
Brute Force Approach
---------------------
LOGIC - Loop over the  array and again loop over the array leaving the outer loop index, and check if the
the pair give the required sum ,then return the vector having the index of that pair.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

pair<int, int> two_sum_brute(vector<int> array, int sum ){
    int n = array.size();
    if ( n < 2 ) return {-1, -1};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n ; j++){
            if ( i==j ) continue;
            if ( array[i] + array[j] == sum ){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

/*
Better Approach
---------------------
LOGIC - Using a hashmap, while looping storing the numbers visited and for the current loop number
we will check if the number exist in the hashmap , if yes, then return the current number index and 
the value of that complement number in hashmap which is it's index, if we not find any complement in 
hashmap then simply add the current loop number to hashmap with index, and pass on.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)
*/

pair<int, int> two_sum_better( vector<int> array, int sum ){
    int n = array.size();
    if ( n <= 1 ) return {-1, -1};

    map<int, int> mpp;
    for (int i = 0; i < n; i++){
        int complement = sum - array[i];
        if (mpp.find(complement) != mpp.end()){
            return {mpp[complement], i};
        }
        mpp[array[i]] = i;
    }

    return {-1, -1};
}

/*
Optimal Approach
---------------------
LOGIC - Sort the array, then take two pointers one at start and one at end, compare the sum of the numbers at the two pointers
to the target sum, if the current sum is low, then move the first pointer forward, otherwise move the last pointer backward
This is optimal but cannot return the indexes because sorting alter the indexes.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

bool two_sum_optimal( vector<int> array, int sum ){
    int n = array.size();
    if ( n <= 1 ) return false;
    sort(array.begin(), array.end());
    int i = 0;
    int j = n-1;
    while ( i < j ){
        int current_sum = array[i] + array[j];
        if (current_sum < sum) i++;
        else if (current_sum > sum) j++;
        else return true;
    }
    return false;
}

int main() {
    vector<int> vec = {1, 2, 5, 6, 0};
    int sum = 7;
    pair<int, int> ans = two_sum_better(vec, sum);
    cout << "Two sum : " << ans.first << " : " << ans.second << endl;
    return 0;
}
