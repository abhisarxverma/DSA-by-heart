#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Given an array, find the maximum number of consecutive ones in the array

/*
Brute Force Approach
---------------------
LOGIC - 

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int maximum_consecutive_ones_brute( vector<int> array ){
    int n = array.size();
    if (n == 0) return -1;

    int final_count = 0;
    int temp_count = 0;
    for (auto num: array){
        if (num == 1) temp_count++;
        else {
            if (temp_count > final_count) final_count = temp_count;
            temp_count = 0;
        }
    }
    return final_count;
}

