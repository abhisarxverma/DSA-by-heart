#include <iostream>
#include <vector>
using namespace std;

/*
Optimal Approach
---------------------
INTUITION - Take the largest and the second largest variables and update both of them as per conditions
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

int find_second_largest_brute( vector<int> array ){
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for (auto num: array){
        if (num > largest){
            second_largest = largest;
            largest = num;
        }
        else if (num > second_largest){
            second_largest = num;
        }
    }   
    return (second_largest == INT_MIN) ? NULL : second_largest;
}

int main() {
    vector<int> vec = {2, 5, 6, 1, 0};
    cout << "Second largest : " << find_second_largest_brute(vec) << endl;
    return 0;
}