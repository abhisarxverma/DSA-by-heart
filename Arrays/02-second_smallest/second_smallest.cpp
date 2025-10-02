#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
Brute Force Approach
---------------------
LOGIC - Sort the array then give the second last element if any
TIME COMPLEXITY - O(N LOGN) - due to sorting
SPACE COMPLEXITY - O(N) - to store the sorted array
*/

int find_second_smallest_brute( vector<int> array ){
    sort(array.begin(), array.end());
    return array.size() > 1 ? array[2] : NULL;
}

/*
Optimal Approach
---------------------
LOGIC - Take the smallest and the second smallest variables and update both of them as per conditions
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_second_smallest_optimal( vector<int> array ){
    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    for (auto num: array){
        if (num < smallest){
            second_smallest = smallest;
            smallest = num;
        }
        else if (num < second_smallest && num > smallest){
            second_smallest = num;
        }
    }   
    return (second_smallest == INT_MAX) ? NULL : second_smallest;
}

int main() {
    vector<int> vec = {1, 5, 9, 0, 6, 2};
    cout << "Second smallest : " << find_second_smallest_optimal(vec) << endl;
    return 0;
}