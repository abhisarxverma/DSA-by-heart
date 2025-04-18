#include <iostream>
#include <vector>
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

int main() {

    return 0;
}