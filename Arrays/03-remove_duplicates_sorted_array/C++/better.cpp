#include <iostream>
#include <vector>
using namespace std;

/*
Better Approach
---------------------
INTUITION - create a new vector and iterate through the original vector, add into the result vector if the number is not equl to the last element of the vector
TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(N)

*/

vector<int> remove_duplicates_better(vector<int> array) {
    vector<int> res;
    for (int num : array) {
        if (res.empty() || num != res.back()) {
            res.push_back(num);
        }
    }
    return res;
}

int main() {
    vector<int> vec = {1, 1, 2, 2, 2, 3, 3, 3};
    vector<int> res = remove_duplicates_better(vec);
    for (auto n : res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}