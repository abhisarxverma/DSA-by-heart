#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// PROBLEM - Given an array, return the array of elements that who has not element on the right greater than them.

// Input : {5, 2, 9, 7, 3}
// Output : {9, 7, 3}

/*
Brute Approach
---------------------
LOGIC - Loop over the array, and then loop over the array on the right of them, if you find any element greater then stop and
if not, add it to the result array

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

vector<int> find_leaders_brute( vector<int> array ){
    int n = array.size();
    vector<int> res;
    for (int i = 0; i < n; i++){
        bool found_greater = false;
        for ( int j = i+1; j < n; j++){
            if (array[j] > array[i]) found_greater = true;
        }
        if (!found_greater) res.push_back(array[i]);
    }
    return res;
}

/*
Optimal Approach
---------------------
LOGIC - If you think carefully, the leaders are the numbers which are greater than the max on the right.
so iterate from the right, and store the max number, if the current number is greater than the max then
add it to the result array. else pass.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

vector<int> find_leaders_optimal( vector<int> array ){
    int n = array.size();
    int max = INT_MIN;
    vector<int> res;
    for (int i = n-1; i >= 0; i--){
        int num = array[i];
        if ( num > max ) {
            res.push_back(num);
            max = num;
        }
    }
    return res;
}

int main() {
    vector<int> vec = {5, 2, 9, 7, 3};
    vector<int> leaders = find_leaders_optimal(vec);
    for (auto it : leaders) cout << it << " ";
    cout << endl;
    return 0;
}