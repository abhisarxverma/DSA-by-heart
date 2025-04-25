#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 PROBLEM - Given an interger 'n' and an array of size of, which should have natural number from 1 to n
 but one number is missing and in place of that integer another integer is repeating, so find both the missing and repeating number.

 EXAMPLE INPUT - {8, 6, 1, 7, 5, 2, 3, 8}, n = 8
 EXAMPLE OUTPUT - Missing - 4, Repeating - 8

*/

/*
Brute Approach
---------------------
LOGIC - Take two variables, missing and repeating, Loop over every number in array
and find the count of the number in the array by looping over again, if the count = 2,
set the repeating to the number and if the count = 0, set the missing to that number

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
*/

pair<int, int> find_missing_repeating_brute( vector<int> array, int n ){
    int missing = -1;
    int repeating = -1;
    for (int num = 1; num <= n; num++){
        int count = 0;
        for ( auto num2 : array ){
            if ( num2 == num ) count++;
        }
        if (count == 0) missing = num;
        if (count == 2) repeating = num;
    }
    return {missing, repeating};
}

/*
Better Approach
---------------------
LOGIC - To optimize two loops, we need to remember previous counts, so take a array of size n+1,
we will put the count of the number in hasharray at the index number. and at last loop over the hasharray
to find the missing and repeating.

TIME COMPLEXITY - O(2N) 
SPACE COMPLEXITY - O(N)
*/

pair<int, int> find_missing_repeating_better(vector<int> array, int n){
    vector<int> hasharray(n+1, 0);
    for ( auto num : array ){
        hasharray[num]++;
    }
    int missing = -1;
    int repeating = -1;
    for (int i = 1; i < n+1; i++){
        if (hasharray[i] == 0) missing = i;
        if (hasharray[i] == 2) repeating = i;
    }
    return {missing, repeating};
}

/*
More Better Approach
---------------------
LOGIC - If you do some maths, you have given the number n, which means that there should be n natural numbers in array

CURRENT_SUM - REPEATING + MISSING = N_SUM
MISSING = N_SUM - CURRENT_SUM + REPEATING

This means that if we find the repeating we will get the missing.
so if we sort the array and loop through it, we can find the sum and also the repeating number.

TIME COMPLEXITY - O(N LogN) SORTING + finding repeating
SPACE COMPLEXITY - O(1)
*/

pair<int, int> find_missing_repeating_better2( vector<int> array , int n ){
    sort(array.begin(), array.end());
    int repeating = -1;
    int current_sum = 0;
    for (int i = 0; i < array.size(); i++){
        if ( i < array.size()-1 && array[i] == array[i+1] ) repeating = array[i];
        current_sum += array[i];
    }
    int n_sum = (n*(n+1))/2;
    int missing = n_sum - current_sum + repeating;
    return {missing, repeating};
}

/*
Optimal Approach - LITTLE COMPLEX
----------------------------------
LOGIC - Using the maths, if we find two equations for the same thing, then we can find
the number.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

pair<int, int> find_missing_repeating_optimal(vector<int> array, int n) {
    // 1. Calculate the expected sum (SN) of numbers from 1 to n
    // Formula: S_N = n(n+1)/2
    long long SN = (n * (n + 1)) / 2;

    // 2. Calculate the expected sum of squares (S2N) of numbers from 1 to n
    // Formula: S2_N = n(n+1)(2n+1)/6
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // 3. Compute the actual sum (S) and sum of squares (S2) from the given array
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += array[i];               // Actual sum
        S2 += (long long) array[i] * (long long) array[i]; // Actual sum of squares
    }

    // 4. Compute the differences between actual and expected values
    long long val1 = S - SN;   // Difference in sums → X - Y (Repeating - Missing)
    long long val2 = S2 - S2N; // Difference in squares → X² - Y²

    // 5. Solve for X + Y using the difference formula
    val2 = val2 / val1; // (X + Y) = (X² - Y²) / (X - Y)

    // 6. Solve for X (Repeating number) and Y (Missing number)
    long long x = (val1 + val2) / 2;  // X = (X - Y + X + Y) / 2
    long long y = x - val1;           // Y = X - (X - Y)

    return {(int)x, (int)y};
}


int main() {
    vector<int> array = {8, 6, 1, 7, 5, 2, 3, 8};
    pair<int, int> ans = find_missing_repeating_better2(array, array.size());
    cout << "Missing: " << ans.first << endl;
    cout << "Repeating: " << ans.second << endl;
}