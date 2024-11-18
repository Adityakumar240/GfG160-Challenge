#include <iostream>
using namespace std;

void pushZerosToEnd(int arr[], int n) {
        // code here
        int idx = 0;
        for(int i = 0; i <= n-1; i++){
            if(arr[i] != 0){
                swap(arr[i], arr[idx]);
                idx++;
            }
        }
    }
int main(){
    int arr[] = {0,2,4,1,0,5,6,3,0,7};
    pushZerosToEnd(arr, 10);

    cout << "Arrays after moving zeroes to end" << endl;
    for(int num : arr){
        cout << num << " ";
    }
}