#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

 // Function to find the sum of contiguous subarray with maximum sum.
int maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int res = arr[0];
    // Initialize the maximum sum ending at the current position with the first element
    int max_ending = arr[0];
        
    for(int i = 1; i < n; i++){
        // Update the maximum sum ending at the current position
        // Either include the current element in the existing subarray (max_eding + arr[i])
        // or start a new subarray from the current element (arr[i])
        max_ending = max(max_ending + arr[i], arr[i]);
        // Update the overall result if the current max_ending is greater than the result 
        res = max(max_ending, res);
    }
    return res;
}

int main(){
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int result = maxSubarraySum(arr);
    cout << "Maximum subarray sum is: " << result << endl;

}