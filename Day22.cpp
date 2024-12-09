#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find hIndex

// Approach 1 - Time complexity O(nlogn + n)
int hIndex(vector<int>& citations) {
    // Step 1: Sort the citations in decreasing order
    sort(citations.begin(), citations.end(), greater<int>());
    
    // Iterate through the sorted array to find the H-index
    for(int i = 0; i < citations.size(); i++){
        // Check if citations is greater than >= (i + 1)
        if(citations[i] < (i + 1)){
            return i;       // Return i because we found the first citation that don't satisfy the condition
        }
    }
    // If no such citation is found, return the size of the citation list
    return citations.size();
}



// Approach 2 - Time complexity O(n) and space complexity O(n)
int hIndex2(vector<int>& citations){

    int n = citations.size();
    vector<int> freq(n + 1);

    // Count the frequency
    for(int i = 0; i < n; i++){
        if(citations[i] >= n){
            freq[n] += 1;
        }else{
            freq[citations[i]] += 1;
        }
    }
    

    int idx = n;

    // Variable to keep track of the count of papers having at
    // least idx citations
    int s = freq[n];
    while(s < idx){
        idx--;
        s += freq[idx];
    }

    // Return the largest index for which the count of papers with 
    // at least idx citations becomes >= idx
    return idx;
}


int main(){
    vector<int> citations1 = {3, 0, 5, 3, 0};
    vector<int> citations2 = {5, 1, 2, 4, 1};

    cout << "H-Index for citations1: " << hIndex(citations1) << endl;
    cout << "H-Index for citations2: " << hIndex2(citations2) << endl;

    return 0;
}