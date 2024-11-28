#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = 1;
        for(int i = 0; i < n; i++){
            
            // If we have found 'res' in the array,
            // 'res' is no longer missing, so increment is
            if(arr[i] == res){
                res++;
                
            // If the current element is larger than 'res',
            //  'res' cannot be found in the array,
            // so it is our final answer
            }else if(arr[i] > res){
                break;
            }
        }
        return res;
    }

// Efficient approach - In place marking approach
int findMissingPositive(vector<int> &arr){
    int n = arr.size();

    // Step 1: Replace all negative numbers and numbers larger than n with a number larger than n
    for(int i = 0; i < n; i++){
        if(arr[i] <= 0 || arr[i] > n){
            arr[i] = n + 1; // Replace with a value greater than n
        }
    }

    // Step 2: Mark the presence of numbers by negating the value at the corresponding index
    for(int i = 0; i < n; i++){
        int val = abs(arr[i]);  // Use absolute value to avoid using already negeted numbers
        if(val >= 1 && val <= n){
            // If the value is within the valid range, mark its index as visited
            if(arr[val - 1] > 0){   // Only negate if the value at that index is positive
                arr[val - 1] = -arr[val - 1];   // Mark it as visited
            }
        }
    }

    // Step 3: Find the index where the value is positive (which means it's missing)
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            return i + 1;   // Missing number is i+1 (because of 0-based indexing)
        }
    }

    // If all the numbers from 1 to n are present, missing number is n+1;
    return n + 1;
}

int main(){
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr) << endl;
    cout << findMissingPositive(arr) << endl;

    return 0;
}


// Step-by-Step Explanation of efficient approach:

// Step 1: Replace invalid values
// We iterate over the array and replace:

// All negative numbers and numbers greater than n with a number greater than n (e.g., n + 1). This is because such numbers cannot affect the smallest missing positive number.
// Example: For arr = {2, -3, 4, 1, 1, 7} (size n = 6):

// After replacing, the array becomes {2, 7, 4, 1, 1, 7}.
// Step 2: Mark presence using indices
// We loop through the array again.
// For each number val, if 1 <= val <= n, we mark the corresponding index (val - 1) as visited by negating the value at that index.
// This allows us to track which numbers are present in the array.
// Example: For arr = {2, 7, 4, 1, 1, 7}:

// We encounter 2, so we negate the value at index 2 - 1 = 1 → arr = {2, -7, 4, 1, 1, 7}.
// We encounter 7, so we negate the value at index 7 - 1 = 6 → arr = {2, -7, 4, 1, 1, -7}.
// We encounter 4, so we negate the value at index 4 - 1 = 3 → arr = {2, -7, -4, 1, 1, -7}.
// We encounter 1, so we negate the value at index 1 - 1 = 0 → arr = {-2, -7, -4, 1, 1, -7}.
// Step 3: Find the first unmarked index
// After marking, the first positive value we encounter in the array means that the number index + 1 is missing.

// For the array arr = {-2, -7, -4, 1, 1, -7}:

// Index 0 is negative (so 1 is present).
// Index 1 is negative (so 2 is present).
// Index 2 is negative (so 3 is present).
// Index 3 is positive → The missing number is 3 + 1 = 4.
// Complexity:
// Time Complexity: O(n) because we only iterate over the array twice (once for marking and once for finding the missing number).
// Space Complexity: O(1) since we modify the array in-place and do not use extra space (ignoring input/output space).


// Another approach can be using cycle sort