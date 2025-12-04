#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// BINARY TO DECIMAL CONVERSION
// Converting a base 2 number to base 10

// ITERATIVE 

int binary_to_decimal(string bin){
    int decimal = 0;
    int position = 1;
    string bin_copy(bin.begin(), bin.end());
    reverse(bin_copy.begin(), bin_copy.end());
    for ( char bit : bin_copy ){
        if (bit == '1') decimal += position;
        position *= 2;
    }
    return decimal;
}

// RECURSIVE 

int binary_to_decimal_recursive(string bin, int index=0){
    if (index == bin.size()) return 0;
    int bit = bin[index] - '0';
    int to_add = pow(2, bin.size()-index-1);
    if (bit) return to_add + binary_to_decimal_recursive(bin, index+1);
    else return binary_to_decimal_recursive(bin, index+1);
}

// CHECK
int main() {
    cout << binary_to_decimal("1010") << endl; // -> 10
    cout << binary_to_decimal("1000") << endl; // -> 8
    cout << binary_to_decimal_recursive("1010") << endl; // -> 10
    cout << binary_to_decimal_recursive("1000") << endl; // -> 8
}