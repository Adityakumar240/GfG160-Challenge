#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinDiff(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());       // Sort the array
    int n = arr.size();

    if(n == 1){     // If there is only one tower, the difference is 0;
        return 0;
    }

    // Calculate the  initial difference (without any changes)
    int  initial_difference = arr[n-1] - arr[0];
    int minimum_difference = initial_difference;

    for(int i = 1; i <= n-1; i++){
        // Skip if arr[i]-k becommes negative
        if(arr[i]-k < 0){
            continue;
        }

        // Calculate the new maximum and minimun difference
        int new_max = max(arr[i-1]+k, arr[n-1]-k);
        int new_min = min(arr[0]+k, arr[i]-k);
        
        minimum_difference = min(new_max - new_min, minimum_difference);
    }
    return minimum_difference;
}

int main(){
    vector<int> arr = {1, 8, 10, 6, 4, 6, 9};
    int k = 7;
    cout << "Minimum possible difference: " << getMinDiff(arr, k) << endl;
}