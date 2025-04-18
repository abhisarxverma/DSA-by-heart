#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Brute Force Approach
---------------------
INTUITION - Sort the array then give the second element if any
TIME COMPLEXITY - O(N LOGN) - due to sorting
SPACE COMPLEXITY - O(N) - to store the sorted array
*/

int find_second_largest_brute( vector<int> array ){
    sort(array.begin(), array.end());
    return array.size() > 1 ? array[array.size()-2] : NULL;
}

/*
Optimal Approach
---------------------
INTUITION - Take the largest and the second largest variables and update both of them as per conditions
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_second_largest_optimal( vector<int> array ){
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for (auto num: array){
        if (num > largest){
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest && num < largest){
            second_largest = num;
        }
    }   
    return (second_largest == INT_MIN) ? NULL : second_largest;
}

int main() {
    vector<int> vec = {2, 5, 6, 1, 0};
    cout << "Second largest : " << find_second_largest_optimal(vec) << endl;
    return 0;
}