#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

 // Function to find the first non-repeating character in a string.

// Brute force approach  (TLE)
char nonRepeatingChar(string &s) {
    // Your code heres
    int n = s.size();
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(i != j && s[i] == s[j]){
                flag = false;
            }
        }
        if(flag == true){
            return s[i];
        }
    }
    return '$';
}

// Efficient approach - 1

// As input string can only have lowercase
    // characters, the maaximum characters will be 26
const int MAX_CHAR = 26;

char nonRepeatingChar2(string &s) {
// Your code heres
vector<int>arr(MAX_CHAR, -1);
       
    for(int i = 0; i < s.size(); i++){
           
        // If the character is seen for the first time, store its index
        if(arr[s[i] - 'a'] == -1){
            arr[s[i] - 'a'] = i;
               
            // If the character is seen again, mark it as -2
        }else{
            arr[s[i] - 'a'] = -2;
        }
    }
       
    int idx = INT_MAX;
       
    // Find the smallest index among all the  non- repeating characters
    for(int i = 0; i < MAX_CHAR; i++){
        if(arr[i] >= 0){
            idx = min(arr[i], idx);
        }
    }
       
    // If non repeating character is found, return it else return '$'
    return idx == INT_MAX ? '$' : s[idx];
}

int main(){
    string s = "geeksforgeeks";
    cout << nonRepeatingChar2(s) << endl;

    return 0;
}



// Efficient Approach 2 Using Frequency Array (Two Traversal)
// The efficient approach is to either use an array of size 26 to store the frequencies of each character. Traverse the input string twice:


// First traversal is to count the frequency of each character.  
// Second traversal to find the first character in string with a frequency of one.