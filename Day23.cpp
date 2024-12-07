#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> // for stringstream
using namespace std;

// Brute force approach has time complexity: O(n square) - TLE

int mergeAndCount(vector<int> &arr, vector<int>& temp, int left, int mid, int right){
    int i = left;   // Starting index for left subarray
    int j = mid + 1;    // Starting index for right subarray
    int k = left;   // Starting index to place sorted elements
    int invCount = 0;
    
    // Merge the two subarrays while counting inversions
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++, k++;
        }else{
            temp[k] = arr[j];
            j++, k++;
            // All elements remaining in the left subarray are greater than arr[j]
            invCount += (mid - i + 1);
        }
    }
    
    // Copy the remaiming elements of the left subarray, if any
    while(i <= mid){
        temp[k] = arr[i];
        i++, k++;
    }
    
    // Copy the remaining elements of the right subarray, if any
    while(j <= right){
        temp[k] = arr[j];
        j++, k++;
    }
    
    // Copy the sorted subarray back into the original array
    for(int idx = left; idx <= right; idx++){
        arr[idx] = temp[idx];
    }
    
    return invCount;
}


int mergeSortAndCount(vector<int> & arr, vector<int> &temp, int left, int right){
    int invCount = 0;
    if(left < right){
        int mid = (left + right) / 2;
        
        // Count inversions in the left subarray
        invCount += mergeSortAndCount(arr, temp, left, mid);
        
        // Count inversions in the right subarray
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        
        // Count split inversions and merge the two halves
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

// Function to count inversions in the array.
int inversionCount(vector<int> &arr) {
    // Your Code Here
    int n = arr.size();
    vector<int> temp(n);    // Temporary array for merge sort
    return mergeSortAndCount(arr, temp, 0, n-1);
}

int main(){
    string inputLine;
    getline(cin, inputLine);    // Read input as a single line

    stringstream ss(inputLine);
    vector<int> arr;
    int num;

    while(ss >> num){
        arr.push_back(num);
    }

    cout << inversionCount(arr) << endl;
    return 0;
}