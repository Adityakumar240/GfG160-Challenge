#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int profit = 0;
        for(int i = 1; i <= n-1; i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i]- prices[i-1]);
            }
        }
        return profit;
    }


int main(){
    vector<int>prices ={7, 1, 5, 3, 6, 4};

    // Print input prices
    cout << "Stock Prices: ";
    for(int price : prices){
        cout << price << "  ";
    }
    cout << endl;

    int profit = maximumProfit(prices);
    cout << "Maximum profit: " << profit << endl;

    return 0;
}