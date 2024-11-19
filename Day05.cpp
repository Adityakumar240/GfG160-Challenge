#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& arr) {
        // Find the pivot elemment
        int n = arr.size();
        int pivot = -1;
        for(int i = n-2; i >=0; i--){
            if(arr[i] < arr[i+1]){
                pivot = i;
                break;
            }
        }
        
        // If no pivot element, reverse the array (last permutation case)
        if(pivot == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        // Find the successor (smallest element greater than arr[pivot])
        int successor = -1;
        for(int i = n-1; i > pivot; i--){
            if(arr[i] > arr[pivot]){
                successor = i;
                break;
            }
        }
        
        //swap the pivot with the successor
        swap(arr[successor], arr[pivot]);
        
        // Reverse the suffix to get the smallest lexicographical order
        reverse(arr.begin() + pivot + 1, arr.end());
        
    }
int main(){
    // Test case 1
    vector<int> arr1  = {2, 4, 1, 7, 5, 0};
    cout << " Original array: ";
    for(int num : arr1){
        cout << num << " ";
    }
    cout << endl;

    nextPermutation(arr1);
    cout << "Next permutation: ";
    for(int num : arr1){
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> arr2  = {3, 2, 1};
    cout << " Original array: ";
    for(int num : arr2){
        cout << num << " ";
    }
    cout << endl;

    nextPermutation(arr2);
    cout << "Next permutation: ";
    for(int num : arr2){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}