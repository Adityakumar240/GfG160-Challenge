#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to compute LPS array
void computeLPSArray(const string &pat, vector<int> & lps){

    int length = 0;     // Length of the previous largest proper prefix suffix
    lps[0] = 0;         // LPS value for the first character is always 0;

    int i = 1;          // Start form the second character in the pattern
    while(i < pat.size()){
        if(pat[i] == pat[length]){
            // If the characters match, extend the LPS by 1
            length++;
            lps[i] = length;
            i++;
        }else{
            if(length != 0){
                // If character don't match, fallback using LPS array
                length = lps[length-1];
            }else{
                // No prefix matches, set LPS value to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP search
vector<int>KMPSearch(const string &txt, const string &pat){

    int n = txt.size();     // Length of the text
    int m = pat.size();     // Length of the pattern

    vector<int> lps(m);     // LPS array for the pattern
    computeLPSArray(pat, lps);      // Preprocess the pattern to create LPS array

    vector<int> result;     // To store the starting indices of the pattern matches
    int i = 0;      // Index for the texr
    int j = 0;      // Index for the pattern

    while(i < n){
        if(pat[j] == txt[i]){
            // Character match, move indices forward
            i++;
            j++;
        }
        if(j == m){
            // Entire pattern matched, store the starting index
            result.push_back(i-j);

            // Reset 'j' using the LPS array to search for overlapping matches
            j = lps[j-1];

        }else if(i < n && pat[j] != txt[i]){
           // Mismatch after some matches
           if(j != 0){
            // Fallback using LPS array
            j = lps[j-1];
           }else{
                // No prefix matches, move to the next character in the text
                i++;
           }
        }
    }
    return result;      // Return all starting indices of the matches
}

int main(){
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";
    
    vector<int> result = KMPSearch(txt, pat);

    if(result.empty()){
        cout << "[]";
    }else{
        cout << "[";
        for(size_t i = 0; i < result.size(); i++){
            cout << result[i];
            if(i != result.size() - 1){
                cout << ", ";
            }
        }
        cout << "]";
    }

    return 0;
}