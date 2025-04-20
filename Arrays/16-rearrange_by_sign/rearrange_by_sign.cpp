#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// PROBLEM - Given an array of integers, make the array aranged as first positive, then negative, then positive
//then negative, and make sure to maintain the sequence of the numbers in the original array

// Input : {-5, 2, 6, -1, 0}
// Output : {2, -5, 6, -1, 0}

/*
Brute Force Approach
---------------------
LOGIC - Take a two pointers for both positives and negatives, and increment both by two while placeing the
numbers in a new array, the pointers will act as index in which the next number should be placed

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)
*/

// This will only work if the number of positives and negatives are equal because of either of them are less
// then as we are incrementing the index by 2, leaving place in between, it will be uninitialized and will have a garbage value.
vector<int> rearrange_by_sign_brute( vector<int> &array ){
    int n = array.size();
    int i = 0; // index for first positive number
    int j = 1; // index for first negative number
    vector<int> result(n);
    for (auto num : array){
        if (num >= 0){
            result[i] = num;
            i+=2;
        }
        else {
            result[j] = num;
            j+=2;
        }
    }
    array = result;
}

/*
Better Approach
---------------------
LOGIC - Take two separate vectors for positives and negatives, put the numbers, and the merge them sequentially

TIME COMPLEXITY - O(2N)
SPACE COMPLEXITY - O(N)
*/

vector<int> rearrange_by_sign_better( vector<int> &array ){
    vector<int> pos;
    vector<int> neg;

    for (auto num : array){
        if (num >= 0) pos.push_back(num);
        else neg.push_back(num);
    }

    int p = 0, n = 0, i = 0;
    while ( p < pos.size() && n < neg.size() ){
        array[i++] = pos[p++];
        array[i++] = neg[n++];
    }
    while ( p < pos.size() ) array[i++] = pos[p++];
    while ( n < neg.size() ) array[i++] = neg[n++];
}

int main() {
    vector<int> vec = {1, -3, -5, -7, 2, 0};
    rearrange_by_sign_brute(vec);
    for (auto it: vec) cout << it << " ";
    cout << endl;
    return 0;
}