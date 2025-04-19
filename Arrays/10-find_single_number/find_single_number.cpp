#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Given an array with numbers which are apprearing twice in order but one number is alone find that number
// { 1, 1, 2, 2, 3, 4, 4 }

/*
Brute Force Approach
---------------------
LOGIC - Loop over the array taking two steps and check if the next number is equal to the current number if not return that number

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_single_number_brute( vector<int> array ){
    int n = array.size();
    if ( n == 0 ) return -1;
    else if (n == 1) return array[0];
    for (int i = 0; i < n; i+=2){
        if (array[i] != array[i+1]) return array[i];
    }
    return -1;
}

/*
Better Approach
---------------------
LOGIC - XOR concept, if you XOR same numbers the result will be 0 and if you XOR a number with zero, you will get
the number itself. So if you do XOR of the array, the numbers will cancel out and the single number will be left out.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_single_number_better( vector<int> a ){
    int xor1 = 0;
    for (int i = 0; i < a.size(); i++){
        xor1 = xor1 ^ a[i];
    }
    return xor1;
}

int main() {
    vector<int> vec = {1, 1, 2, 2, 3, 4, 4};
    cout << "Single : " << find_single_number_brute(vec) << endl;
}