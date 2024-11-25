#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Brute force approach
int maxProduct(vector<int> &arr) {
    int n = arr.size();
    int res = arr[0];
    for(int i = 0; i < n; i++){
        int curr_product = 1;
        for(int j = i; j < n; j++){
            curr_product *= arr[j];
            res = max(res, curr_product);
        }
    }
    return res;
}

// Efficient approach - 1
int maxProductsub(vector<int> &arr){
    int n = arr.size();
    int max_product = INT_MIN;  // To store the maximum product
    int current_product = 1;    // Running product
    
    // Pass 1: left to right
    for(auto num : arr){
        current_product *= num;
        max_product = max(max_product, current_product);
        if(current_product == 0){
            current_product = 1;        // Reset after encoutering a zero
        }
    }

    // Reset current_product for second pass
    current_product = 1;

    // Pass 2: right to left
    for(int i = n-1; i >= 0; i--){
        current_product *= arr[i];
        max_product = max(max_product, current_product);
        if(current_product == 0){
            current_product = 1;
        }
    }
    return max_product;
}

// Efficient approach - 2
int maxProductSubarray(vector<int> &arr){
    int n = arr.size();

    int current_max = arr[0];       // Max product ending at the current index
    int current_min = arr[0];      // Min product ending at the current index
    int max_product = arr[0];       // Initialize overall max product

    for(int i = 1; i < n; i++){
        // Store current_max before updating it
        int temp = current_max;

        // Update current_max and current_min using initializer lists
        current_max = max({arr[i], arr[i] * current_max, arr[i] * current_min});
        current_min = min({arr[i], arr[i] * temp, arr[i] * current_min});

        // Update the overall max product
        max_product = max(max_product, current_max);
    }
    return max_product;
}

int main(){
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << "Maximum product subarray: " << maxProductsub(arr) << endl;

    return 0;
}