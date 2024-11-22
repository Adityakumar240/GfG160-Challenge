#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Stock Buy and Sell – Max one Transaction Allowed
// Given an array prices[] of length n, representing the prices of the stocks on different days.
// The task is to find the maximum profit possible by buying and selling the stocks on different days when 
// at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not 
// possible to make a profit then return 0.

// Note: Stock must be bought before being sold.



int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int curr_min = prices[0];       // Tracks the minimum price upto the current day
    int max_profit = 0;             // Tracks the maximum profit seen so far

    for(int i = 1; i < n; i++){
        // Update the max profit
        max_profit = max(max_profit, prices[i] - curr_min);
        // Calculate the minimum price seen so far
        curr_min = min(prices[i], curr_min);
    }
    return max_profit;
}

int main(){
    vector<int> pprices = {7, 10, 1, 3, 6, 9, 2};
    cout << "Maximum profit: " << maximumProfit(pprices) << endl;

    return 0;
}