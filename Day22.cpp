#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find hIndex
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

int main(){
    vector<int> citations1 = {3, 0, 5, 3, 0};
    vector<int> citations2 = {5, 1, 2, 4, 1};

    cout << "H-Index for citations1: " << hIndex(citations1) << endl;
    cout << "H-Index for citations2: " << hIndex(citations2) << endl;

    return 0;
}