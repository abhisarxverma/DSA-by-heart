#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

// PROBLEM - Find the maximum length of a consecutive sequence that can be formed from the elements of the array

// Input : {5, 100, 4, 101, 102, 99, 3}
// Output : 4 [99, 100, 101, 102]

/*
Brute Approach
---------------------
LOGIC - loop every element, and search and increment the array till you do not find the next consecutive number
update the max_length if you found greater length of consecutive sequence.

TIME COMPLEXITY - O(N^2) nearly
SPACE COMPLEXITY - O(1)
*/

int maximum_consecutive_length_brute( vector<int> array ){
    if (array.size() == 0) return 0;
    int max_length = 1;

    for (auto num: array){
        int current_length = 1;
        int next_num = num+1;

        while ( find(array.begin(), array.end(), next_num) != array.end() ){
            current_length++;
            next_num++;
        }

        max_length = max(max_length, current_length);
    }
    return max_length;
}

/*
Better Approach
---------------------
LOGIC - Sort the array, take a variable to store the previous number that we should have to make a consecutive sequence,
while iterating, check if the current number - 1, is equal to the last smaller this means that we have that number, so increase
the count, and if we encounter any duplicate to the last smaller we will pass it, if we find any number not equal to the 
last smaller we will again make the count 1 and make that number the last smaller.

TIME COMPLEXITY - O(N + log N) 
SPACE COMPLEXITY - O(1)
*/

int maximum_consecutive_length_better( vector<int> array ){
    if (array.size() == 0) return 0;
    sort (array.begin(), array.end());
    int n = array.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++){
        if (array[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = array[i];
        }
        else if (lastSmaller != array[i]){
            cnt = 1;
            lastSmaller = array[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

/*
Optimal Approach
---------------------
LOGIC - Take a set, store all the numbers in it, then loop over the array, check if the number does not have a 
consecutive lesser, then it may be the first number of the consecutive sequence then go ahead and find the longest
length of the consecutive sequence that number gives.

TIME COMPLEXITY - O(3N) = O(N) 
SPACE COMPLEXITY - O(N) set
*/

int maximum_consecutive_length_optimal( vector<int> array ){
    int n = array.size();
    if ( n == 0 ) return 0;
    int longest = 1;
    unordered_set <int> st;
    for (auto num: array) st.insert(num);

    for (auto num: st){
        if ( st.find(num-1) == st.end() ){
            int count = 1;
            int num2 = num;
            while ( st.find(num2+1) != st.end() ){
                count++;
                num2++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}