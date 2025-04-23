#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
using namespace std;

// PROBLEM - Given an array of integers, return the total number of the contiguous subarrays that give the target xor k.

/*
 EXAMPLE INPUT - 4, 2, 2, 6, 4 , k = 6
 EXAMPLE OUTPUT - 4
*/

/*
Brute Approach
---------------------
LOGIC - Take the variable count, and loop over the array, then loop over the right side of the first loop element, 
and check the xor if equal to the target then increase the count else pass.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int total_subarrays_to_xor_brute( vector<int> array, int target_xor ){
    int n = array.size();
    int count = 0;
    for (int i = 0; i < n; i++){
        int xr = array[i];
        if ( xr == target_xor ) count++;
        for (int j = i+1; j < n; j++){
            xr ^= array[j];
            if ( xr == target_xor ) count++;
        }
    }
    return count;
} 

/*
Optimal Approach - PREFIX SUM CONCEPT
--------------------------------------
LOGIC - 
Use a hashmap to store prefix xor while looping over the array. 
Check if the there exist the number [prefix_xor ^ k] in hashmap, if yes then add in the count the value of that number in map
Update the final length if a longer subarray is found, while storing indices of prefix xor for future reference. 🚀

TIME COMPLEXITY - O(N) OR O(N logN) - hashmap operations
SPACE COMPLEXITY - O(N)
*/

int total_subarrays_to_xor_optimal( vector<int> array , int target_xor ){
    int n = array.size();
    int count = 0;
    int prefix_xor = 0;
    map <int, int> mpp;
    mpp[0] = 1;
    for (auto num : array){
        prefix_xor ^= num;
        int xor_not_needed = prefix_xor ^ target_xor;
        if ( mpp.find(xor_not_needed) != mpp.end() ) count += mpp[xor_not_needed];
        mpp[prefix_xor]++;
    }
    return count;
}

int main(){
    vector<int> array = {4, 2, 2, 6, 4};
    int total = total_subarrays_to_xor_optimal(array, 6);
    cout << "Total subarrays to xor " << 6 << " : " << total << endl;
}