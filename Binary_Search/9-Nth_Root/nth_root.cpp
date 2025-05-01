#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/* 
PROBLEM - Given the number and the integer 'n', find and return the nth root of that number if exists else return -1

Example Input -   100, 2 | 343, 3 | 64, 4
Example Output -     10  |   7    |   -1
*/

/*
Brute Force Approach
---------------------
LOGIC -
To find the nth root of a number using linear search, we check each number from 0 to (number/n) + 1:
Compute the nth power of each number in this range.
If the result matches the given number, return the current number (it is the nth root).
If the power is greater, stop the loop—the root was before this point.
If the power is smaller, continue checking further numbers.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

// HELPER FUNCTION FOR CALCULATING POWER    
long long power(int number, int power){
    if ( power == 1 ) return number;
    if ( power == 0 ) return 1;
    long long ans = 1;
    for (int i = 0; i < power; i++) ans *= number;
    return ans;
}

int nth_root_brute( int number, int n ){
    for (int i = 0; i <= (number/n)+1; i++){
        long long n_power = power(i, n);
        if (n_power == number) return i;
    }
    return -1;
}

/*
Optimal Approach
---------------------
LOGIC  - 
To find the nth root of a number using binary search, we search in the range 0 to (number/n) + 1:
Get the mid value.
If mid^n == number, return mid (we found the exact nth root).
If mid^n > number, remove the right part (mid is too large).
If mid^n < number, remove the left part (mid is too small).
If no number satisfies mid^n == number, return -1 after the loop.

TIME COMPLEXITY - O(Log N) 
SPACE COMPLEXITY - O(1)
*/

int nth_root_optimal( int number, int n ){
    int low = 0;
    int high = (number/n)+1;

    while ( low <= high ){
        int mid = low + (high-low)/2;
        long long mid_power = power(mid, n);
        if (mid_power == number) return mid;
        else if (mid_power < number) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    int nth_root = nth_root_optimal( 243, 5 );
    cout << "Nth root : " << nth_root << endl;
}