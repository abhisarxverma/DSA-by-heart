#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 PROBLEM - Find the maximum product that you can get from all the subarrays of the given array
 EXAMPLE INPUT - {2, -1, 5, 7, -2, -9, 10, -6}
 EXAMPLE OUTPUT - 75600
*/

/*
Brute Approach
---------------------
LOGIC - Loop over the array and then loop over the right of the outer loop's number, and multiply while
updating the final product

TIME COMPLEXITY - O(N^2) two-nested-loops
SPACE COMPLEXITY - O(1)
*/

long long maximum_product_subarray_brute( vector<int> array ){
    int n = array.size();
    long long maximum_product = LONG_MIN;
    for (int i = 0; i < n; i++){
        long long temp_product = array[i];
        maximum_product = max(maximum_product, temp_product);
        for (int j = i+1; j < n; j++){
            temp_product *= array[j];
            maximum_product = max(maximum_product, temp_product);
        }
    }
    return maximum_product;
}

/*
Optimal Approach
---------------------
LOGIC - 
Since the product can be affected by negative numbers and zeros, we need to check both left-to-right (prefix) and right-to-left (suffix).
Multiplying continuously from start to end and end to start ensures we correctly handle negative flips.
Traverse the array from left to right (prefix).
Simultaneously traverse from right to left (suffix).
Reset product when encountering zero (pre = 1, suf = 1), ensuring we start fresh after a zero.
Keep track of the maximum product found.
Since negatives can flip signs, checking from both ends ensures we do not miss a case where multiplying a negative later leads to a higher product.

TIME COMPLEXITY - O(N) 
SPACE COMPLEXITY - O(1)
*/

long long maximum_product_subarray_optimal( vector<int> a ){
    int n = a.size();
    long long maxi = LONG_MIN;
    long long pre = 1;
    long long suf = 1;
    for (int i = 0; i < n; i++){
        if ( pre == 0 ) pre = 1;
        if ( suf == 0 ) suf = 1;
        pre = pre *= a[i];
        suf = suf *= a[n-1-i];
        maxi = max(maxi, max(pre, suf));
    }
    return maxi;
}

int main(){
    vector<int> vec = {2, -1, 5, 7, -2, -9, 10, -6};
    long long maximum = maximum_product_subarray_brute(vec);
    cout << "Maximum_product : "<< maximum << endl;
}