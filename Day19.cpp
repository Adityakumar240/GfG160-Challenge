#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Approach - 1
// Naive approach
// Function to check is the substring s[i....j] is a palindrome
bool isPalindrome(string &s, int i, int j){
    while(i < j){
        // If character are at the ends are not equal, it is not a palindrome
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to calculate the minimum character to add
int minCharBrute(string &s){
    int count = 0;      // track the number of character to add
    int i =s.size() - 1;    // Start checking form the end of the string

    // Iterate while we have not found a palindrome prefix
    while(i >= 0 && !isPalindrome(s, 0, i)){
        i--;    // Reduce the length of the substring to check
        count++;    // Incerment the count of the character to add
    }
    return count;
}



// Approach - 2
// Optimized approach using KMP LPS algorithm

// Function to compute the KMP LPS array
vector<int> computeLPS(string &pattern){
    
    int n = pattern.size();
    vector<int> lps(n,0);
    int len = 0;    // Length of the previous largest prefix-suffix
    int i = 1;
    
    while(i < n){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len - 1];     // Fall back to a character prefix
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minChar(string& s) {
    // Write your code here
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());    // Reverse the string
    
    // Create the concatenated string
    string temp = s + "#" + s_rev;
    
    // Cmopute the LPS array
    vector<int>lps = computeLPS(temp);
    
    // Result: Length of the original string minus the longest palindromic prefix
    return s.size() - lps[temp.size() - 1];
}




int main(){
    string s = "aacecaaaa";

    cout << "Minimum characters to add using naive approach: " << minChar(s) << endl;
    cout << "Minimum characters to add: " << minChar(s) << endl;

    return 0;
}