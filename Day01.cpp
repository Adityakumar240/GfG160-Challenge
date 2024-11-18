#include <iostream>
using namespace std;

//Brute force approach
int getLargest(int arr[], int n){       // Get the largest element
    int max = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = i;
        }
    }
    return max;
}

int secondLargestBruteForce(int arr[], int n){
    int largest = getLargest(arr,n);
    int res = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] != arr[largest]){
            if(res == -1){
                res = i;
            }else{
                if(arr[i] > arr[res]){
                    res = i;
                }
            }
        }
    }
    return res;
}

// Efficient approach
int secondLargestEfficient(int arr[], int n){
    int largest = 0, res = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > arr[largest]){
            res = largest;
            largest = i;

        }else if(arr[i] != arr[largest]){
            if(res == -1 || arr[i] > arr[res]){
                res = i;
            }
        }
    }
    return (res == -1 ? -1 : arr[res]); // Return the value of second largest element or -1 if it doesn't exist. 
}

int main(){
    int arr[] = {1,5,2,4,7,9,5,9,12};
    cout << "The larget element is at index " << getLargest(arr, 9) << endl;
    cout << "The second largest element is at index " << secondLargestBruteForce(arr, 9) << endl;
    cout << "The second largest element is " << secondLargestEfficient(arr, 9) << endl;
}