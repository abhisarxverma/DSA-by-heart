#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// DECIMAL TO BINARY CONVERSION
// Converting a base 10 number to base 2

// ITERATIVE 

string decimal_to_binary(int n){
    string res("");
    while (n > 0){
        res.push_back((char)n%2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

// RECURSIVE

string decimal_to_binary_recursive(int n){
    if (n <= 1) return string("");
    return decimal_to_binary(n/2) + to_string(n%2);
}

// check
int main() {
    cout << decimal_to_binary(10000) << endl; // -> 10011100010000
    cout << decimal_to_binary(10) << endl; // -> 1010
    cout << decimal_to_binary_recursive(1000) << endl; // -> 1011100010000
    cout << decimal_to_binary_recursive(5) << endl; // -> 101
}