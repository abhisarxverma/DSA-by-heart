#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
using namespace std;

// PROBLEM - Given an array of array intervals of integers, merge the intervals.

/*
 EXAMPLE INPUT - {{1, 3}, {2, 6}, {8, 10}, {9, 12}}
 EXAMPLE OUTPUT - { {1, 6}, {8, 12} }
*/

/*
Brute Approach
---------------------
LOGIC - Take a set to store the unique intervals, Loop over the intervals , take two variables, low and high, and initialize them to the first and second element
loop over the array again and check if the current interval of low and high is streched more on either side, and according to 
that update the low and high of the interval, and on completion of the second loop, we will have the interval is unique, add that 
to the unique intervals set, and repeat the process.

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(N) hashset
*/

vector<vector<int>> merge_overlapping_subintervals_brute( vector<vector<int>> intervals ){
    int n = intervals.size();
    set<vector<int>> merged_uniques;
    for (int i = 0; i < n; i++){
        int low = intervals[i][0];
        int high = intervals[i][1];
        for (int j = 0; j < n; j++){
            if ( i == j ) continue;
            if (intervals[j][0] >= low && intervals[j][0] <= high){ // if the current interval's low is in the range of the low and high interval then this can expand the interval more from right side
                if ( intervals[j][1] > high ) high = intervals[j][1]; // update the high if greater
            }
            if (intervals[j][1] >= low && intervals[j][1] <= high){ // if the current intervals' high is in the range of the low and high interval then this can expand the interval more from left side
                if ( intervals[j][0] < low ) low = intervals[j][0]; // update the low if shorter
            }
        }
        merged_uniques.insert({low, high});
    }
    vector<vector<int>> result;
    for (auto interval: merged_uniques) result.push_back(interval);
    return result;
}

/*
Optimal Approach
---------------------
LOGIC - Sort the intervals array, take two variables, low and high, and while looping update them, increase the high if the low of the
current interval is under the low and high variables and high is greater than the high variable, and decrease the low if the high of the 
current interval falls under the interval made by the low and high variable and the low is shorter than the low variable.

TIME COMPLEXITY - O(NlogN) Single iteration
SPACE COMPLEXITY - O(1)
*/

vector<vector<int>> merge_overlapping_subintervals_optimal( vector<vector<int>> intervals ){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    int low = intervals[0][0];
    int high = intervals[0][1];
    for (int i = 1; i < n; i++){
        if ( intervals[i][0] >= low && intervals[i][0] <= high ){
            if ( intervals[i][1] > high ) high = intervals[i][1];
        }
        else{
            result.push_back({low, high});
            low = intervals[i][0];
            high = intervals[i][1];
        }
    }
    result.push_back({low, high});
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {9, 12}};
    vector<vector<int>> merged = merge_overlapping_subintervals_optimal(intervals);
    for (auto interval: merged){
        for (auto num: interval){
            cout << num << " - ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}