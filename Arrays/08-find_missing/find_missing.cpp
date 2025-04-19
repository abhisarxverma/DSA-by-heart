#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Given an integer n and an array of size n-1, which should be having intergers from 1 to n but one number is missing find that number

/*
Brute Force Approach
---------------------
LOGIC - Loop from one to given integer and for every number loop into the given array to check if the number is present,
if not then straight return the number

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

int find_missing_brute( vector<int> array, int n ){
    for (int i = 1; i <= n; i++){
        bool found = false;
        for (auto num : array){
            if (i == num) found = true;
        }
        if (!found) return i;
    }
    return -1;
}

/*
Optimal Approach
---------------------
LOGIC - We have given the integer which is the number of first n natural numbers that must be there, but one is missing
so if we sum the array and calculate the sum that should the array have and subtract that then we can get the number missing.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_missing_optimal( vector<int> array, int n ){
    int should_be_sum = (n*(n+1))/2;
    int current_sum = 0;
    for (auto num : array) current_sum += num;
    return should_be_sum - current_sum;
}

/*
Optimal2 Approach
---------------------
LOGIC - XOR concept, more faster calculations. do a XOR between the xor of the n natural numbers and the xor of the number in current array.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_missing_xor( vector<int> a, int N){
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < N; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main() {
    vector<int> arr = {1, 3, 4, 5, 6};
    cout << "Missing : " << find_missing_brute(arr, 6) << endl;
    return 0;
}
