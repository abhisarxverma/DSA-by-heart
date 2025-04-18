#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Optimal Approach
---------------------
INTUITION - Take the smallest and the second smallest variables and update both of them as per conditions
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
        else if (num < second_smallest){
            second_smallest = num;
        }
    }   
    return (second_smallest == INT_MAX) ? NULL : second_smallest;
}

int main() {
    vector<int> vec = {0};
    cout << "Second smallest : " << find_second_smallest_optimal(vec) << endl;
    return 0;
}