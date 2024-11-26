#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// Brute force approach - time limit exceeded
int circularSumSubarray(vector<int> &arr) {
        // your code here
        int n = arr.size();
        int max_sum = INT_MIN;
        for(int i = 0; i < n; i++){
            int curr_sum = 0;
            for(int j = 0; j < n; j++){
                int idx = (i+j)%n;      // Circular index
                curr_sum += arr[idx];
                max_sum = max(max_sum, curr_sum);
            }
        }
        return max_sum;
}

// Efficient approach - using kadane algorithm

// Function to find the maximum subarray sum using kadane algorithm
int kadane(vector<int> &arr){
    int n = arr.size();
    int res = arr[0], maxEnding = 0;
    for(int i = 0; i < n; i++){
        maxEnding = max(arr[i], maxEnding+arr[i]);  // Choose current element or extend the previous subarray
        res = max(res, maxEnding);
    }
    return res;
}


int circularSubarraySum(vector<int> &arr) {

    // Step 1: Find the maximum subarray sum using Kadane's algorithm
    int maxNormalSum = kadane(arr);
        
    // Edge case: If all elements are negative, return the normal Kadane result
    if(maxNormalSum < 0){
        return maxNormalSum;
    }
        
    // Step 2: Compute the total sum of the array
    int arrSum = 0;
    for(int num : arr){
        arrSum += num;
    }
        
    // Step 3: Invert the array elements
    for(int &num : arr){
        num = -num;
    }
        
    // step 4: Find the minimum subarray sum using Kadane's algorithm
    int minimumSubarraySum = kadane(arr);
        
    // Step 5: Restore the original array by negating again
    for(int &num : arr){
        num = -num;
    }
        
    // Step 6: Calculate the maximum circular subarray sum
    int circularSubarraySum = arrSum + minimumSubarraySum;
        
        
    // Step 7: Return the maximum of the two cases
    return max(maxNormalSum, circularSubarraySum);
}


int main(){
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};

    cout << "Maximum circular subarray sum (array 1): " << circularSubarraySum(arr1) << endl;
    cout << "Maximum circular subarray sum (array 1): " << circularSubarraySum(arr2) << endl;
    cout << "Maximum circular subarray sum (array 1): " << circularSubarraySum(arr3) << endl;

    return 0;
}