#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Brute Force Approach
---------------------
INTUITION - use a set to store the seen numbers and if the number is not seen then add that into vector
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(2N) - set and result vector

UNORDERED SET :-

Operation	            Average Case	   Worst Case
-------------------------------------------------------------------
Insertion (insert())	    O(1)	           O(N) (due to hash collisions)
Lookup (find(), count())	O(1)	           O(N)
Deletion (erase())	        O(1)               O(N)
Iteration (for x in set)	O(N)	           O(N)
*/

vector<int> remove_duplicates_brute(vector<int> array) {
    unordered_set<int> seen;
    vector<int> res;
    for (int num : array) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            res.push_back(num);
        }
    }
    return res;
}

/*
Better Approach
---------------------
INTUITION - create a new vector and iterate through the original vector, add into the result vector if the number is not equl to the last element of the vector
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)

*/

vector<int> remove_duplicates_better(vector<int> array) {
    vector<int> res;
    sort(res.begin(), res.end());
    for (int num : array) {
        if (res.empty() || num != res.back()) {
            res.push_back(num);
        }
    }
    return res;
}

/*
Optimal Approach
---------------------
Logic: Take a pointer back and initialize it to zero, loop from 1st index to end and if the number at that index is not equal to number at back index.
then make the number next to the back index that number and increment the back and at last resize the array to back + 1 cause the till back index all the 
number will be unique.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)

*/

vector<int> remove_duplicates_optimal(vector<int> &array) {
    if (array.empty() || array.size() == 1) return array;
    
    int back = 0;
    
    for (int front = 1; front < array.size(); front++) {
        if (array[front] != array[back]) {
            back++;
            array[back] = array[front]; 
        }
    }
    array.resize(back + 1);
    return array;
}


int main() {    
    vector<int> vec = {1, 1, 2, 3, 5, 5, 7, 7, 7, 9, 9};
    // CHECK
    vector<int> res = remove_duplicates_optimal(vec);
    for (auto num: res){
        cout << num << " ";
    }cout << endl;
    return 0;
}