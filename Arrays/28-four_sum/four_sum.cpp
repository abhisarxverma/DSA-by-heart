#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// PROBLEM - Given an array of integers, find  and return all the groups of 4 integers that give the desired sum k.

/*
 EXAMPLE INPUT - 1, 3, 0, 5, 8, 2, -5, 20 / sum = 10
 EXAMPLE OUTPUT - [-5, 2, 5, 8], [0, 2, 3, 5]
*/

/*
Brute Approach
---------------------
LOGIC - Code a nested 4 loop and in the last loop check the sum if equal to k sort and add that to the set
to store the unique triplets and at last return the vector created from that set.

TIME COMPLEXITY - O(N^4+ LogM) = O(N^4)
SPACE COMPLEXITY - O(N^4) Worst case : Set will store every group of 4 that can be created from the array
*/

vector<vector<int>> four_sum_brute( vector<int> array, int target ){
    int n = array.size();
    set <vector<int>> unique_groups;
    for (int i = 0; i < n; i ++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                for (int l = k+1; l < n; l++){
                    int sum = array[i] + array[j] + array[k] + array[l];
                    if ( sum == target ){
                        vector<int> group = {array[i], array[j], array[k], array[l]};
                        sort(group.begin(), group.end());
                        unique_groups.insert(group);
                    }   
                }
            }
        }
    }
    vector<vector<int>>res(unique_groups.begin(), unique_groups.end());
    return res;
}

/*
Better Approach
---------------------
LOGIC - Code a nested 3 nested loop and in that 2nd loop create a hashset to store the numbers that 3rd loop will visit and
while in the 3rd loop if you find the number on adding to the current sum that will become the target in the hashset that means
that we have found a group that gives the target sum, sort and add that to the final result set to store unique groups only.

TIME COMPLEXITY - O(N^3+ LogM) = O(N^3)
SPACE COMPLEXITY - O(N^3) Worst case : Set will store every group of 4 that can be created from the array
*/

vector<vector<int>> four_sum_better( vector<int> array, int target ){
    int n = array.size();
    set <vector<int>> unique_groups;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            set<int> visited;
            for (int k = j+1; k < n; k++){
                int sum = array[i] + array[j] + array[k];
                int remaining = target - sum;
                if ( visited.find(remaining) != visited.end() ){
                    vector<int> group = {array[i], array[j], array[i], remaining};
                    sort(group.begin(), group.end());
                    unique_groups.insert(group);
                }
                visited.insert(array[k]);
            }
        }
    }
    vector<vector<int>> res(unique_groups.begin(), unique_groups.end());
    return res;
}

/*
Optimal Approach
---------------------
LOGIC - 4 pointer approach, sort the array, run 2 loops and in the second loop, take 2 pointers, one at start and one
at end, and move them according to the current sum, if less than target mover the end pointer back else mover the start
pointer forward and eventually all the groups with the target sum will fall in our bag.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(N^4) Worst case : Set will store every group of 4 that can be created from the array
                    but this also to return the result groups else O(1) to get groups.
*/

vector<vector<int>> four_sum_optimal( vector<int> array, int target ){
    int n = array.size();
    sort(array.begin(), array.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; i++){
        if ( i > 0 && array[i-1] == array[i] ) continue;
        for (int j = i+1; j < n; j++){
            if ( array[j] == array[j-1] ) continue;
            int k = j+1;
            int l = n-1;
            while ( k < l ){
                long long sum = array[i] + array[j] + array[k] + array[l];
                if ( sum < target ) k++;
                else if ( sum > target ) l--;
                else {
                    vector<int> group = {array[i], array[j], array[k], array[l]};
                    res.push_back(group);
                    k++; l--;
                    while ( k < l && array[k] == array[k-1] ) k++;
                    while ( k < l && array[l] == array[l+1] ) l--;
                }
            }
        }
    }
    return res;
}


int main() {
    vector<int> arr = {1, 3, 0, 5, 8, 2, -5, 20};
    vector<vector<int>> ans = four_sum_optimal( arr , 10 );
    for (auto group : ans){
        for (auto num : group){
            cout << num << " ";
        }
        cout << endl;
    }cout << endl;
}