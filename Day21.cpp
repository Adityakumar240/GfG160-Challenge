#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort 0s, 1s and 2s
void sort012(vector<int>& arr) {
        // using Dutch National Flag algorithm
        int n = arr.size();
        int i = 0, j = n-1;
        int k = 0;
        while(k <= j){
            if(arr[k] == 0){
                swap(arr[i], arr[k]);
                    i++, k++;
            }else if(arr[k] == 1){
                k++;
            }else{
                swap(arr[k], arr[j]);
                j--;
            }
        }
    }

int main(){
    vector<int> arr = {0, 1, 2, 1, 0, 0, 1, 1, 2, 2, 2, 1, 0};
    sort012(arr);

    for(int num : arr){
        cout << num << " ";
    }
}