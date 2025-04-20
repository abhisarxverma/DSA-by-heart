#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// PROBLEM - Given an array of prices, give the maximum profit that we can get if we buy and then sell. 

/*
Brute Force Approach
---------------------
LOGIC - Loop over the array, and for every number, loop over the array next to it, and store the maximum difference
and return the greatest.

TIME COMPLEXITY - O(N^2)
SPACE COMPLEXITY - O(1)
*/

pair<int, int> maximum_profit_brute(vector<int> array){
    int n = array.size();
    pair<int, int> final_res;
    int final_profit = INT_MIN;
    for (int i = 0; i < n ;i++){
        for (int j = i+1; j < n; j++){
            int current_profit = array[j] - array[i];
            if (current_profit > final_profit){
                final_res = {i, j};
                final_profit = current_profit;
            }
        }
    }
    return final_res;
}

/*
Better Approach
---------------------
LOGIC - If you think carefully, we just have to find the difference between the minimum and the maximum 
or maybe their indexes. So, while iterating, keep track of the minimum number before it and update the final
profit based on the difference.

TIME COMPLEXITY - O(N)
SPACE COMPLEXITY - O(1)
*/

pair<int, int> maximum_profit_better(vector<int> prices) {
    int n = prices.size();
    pair<int, int> res;
    int min_price = prices[0];
    int buy_price = prices[0];  
    int final_profit = 0;

    for (int i = 1; i < n; i++) {
        int current_profit = prices[i] - min_price;
        if (current_profit > final_profit) {
            final_profit = current_profit;
            buy_price = min_price;  
            res = {buy_price, prices[i]};
        }
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
    }
    return res;
}


int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    pair<int, int> ans = maximum_profit_better(prices);
    cout << "Maximum profit days : " << ans.first << " : " << ans.second << endl;
    return 0;
}