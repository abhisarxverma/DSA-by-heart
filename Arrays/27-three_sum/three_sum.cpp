#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

// PROBLEM - Given an array of integers, find the and return all the triplets that have the sum 0

/*
 EXAMPLE INPUT - 3, 5, -1, 5, -10, -8, 5, 0
 EXAMPLE OUTPUT - [3, 5, -8], [5, -10, 5]
*/

/*
Brute Approach
---------------------
LOGIC - Take a set, loop over the array in the nested three times, and if you find the sum of a
triplet equal to the zero, then sort it and put it in set so that the set can check if the same
triplet is not entered twice. Then at last put the triplets from the set to the vector and return.

TIME COMPLEXITY - O(N^3 + LogM) = O(N^3)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
*/

vector<vector<int>> three_sum_brute( vector<int> array ){
    int n = array.size();
    set <vector<int>> st; // to store the unique triplets

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                int sum = array[i] + array[j] + array[k];
                if (sum == 0){
                    vector<int> triplet = {array[i], array[j], array[k]};
                    sort(triplet.begin(), triplet.end()); // sorting will take O(3) = O(1) constant time
                    st.insert(triplet);
                }
            }
        }
    }
    vector<vector<int>> result;
    for (auto triplet : st) result.push_back(triplet);
    return result;
}

/*
Better Approach
------------------------------------
LOGIC - Loop over the array, then loop over the second time, but before that take a set
to store the visited numbers in the second loop, so while in the second loop check the set
for the 0 - (array[j] + array[k])), if yes this means we have a triplet, store it.

TIME COMPLEXITY - O(N^2 + LogM) = O(N^2)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
*/

vector<vector<int>> three_sum_better( vector<int> array ){
    int n = array.size();
    set <vector<int>> unique_triplets;
    for (int i = 0; i < n ; i++){
        set <int> st;
        for (int j = i+1; j < n; j++){
            int remaining = -(array[i] + array[j]);
            if (st.find(remaining) != st.end()){
                vector<int> triplet = {array[i], array[j], remaining};
                sort(triplet.begin(), triplet.end());
                unique_triplets.insert(triplet);
            }
            st.insert(array[j]);
        }
    }
    vector<vector<int>> res;
    for (auto triplet: unique_triplets){
        res.push_back(triplet);
    }
    return res;
}

/*
Optimal Approach
------------------------------------
LOGIC - Sort the array, then take the three pointers, put one at start and one at end
and one at the next to the start pointer, if the sum is less, then move the middle 
pointer right else left, and with that move the start and the end pointers skipping duplicates.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store all the triplets from the array
*/

vector<vector<int>> three_sum_optimal( vector<int> array ){
    int n = array.size();
    sort(array.begin(), array.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++){
        if (i > 0 && array[i-1] == array[i]) continue;
        int j = i+1;
        int k = n-1;
        while ( j < k ){
            int sum = array[i] + array[j] + array[k];
            if ( sum < 0 ){
                j++;
            }
            else if ( sum > 0 ){
                k--;
            }
            else {
                res.push_back({array[i], array[j], array[k]});
                j++; k--;
                while ( j < k && array[j] == array[j-1] ) j++;
                while ( j < k && array[k] == array[k+1] ) k--;
            }
        }
    }

    return res;
}


int main(){
    vector<int> vec = {3, 5, -1, 5, -10, -8, 5, 0};
    vector<vector<int>> ans = three_sum_optimal(vec);
    for (auto triplet : ans){
        for (auto num : triplet ){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}