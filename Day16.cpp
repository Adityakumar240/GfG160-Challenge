#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Function is to check whether two strings are anagram of each other or not.

// Approach 1
bool areAnagrams1(string& s1, string& s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}



// Approach 2
bool areAnagrams(const string& s1,const string& s2) {
    // Initializing the array to count charaters in the strings
    int arr[26] = {0};
    
    // Storing the count of each characters from the string 1
    for(int i = 0; i < s1.length(); i++){
        arr[s1[i] - 'a']++;
    }
    
    // Decrementing the count of characters of each from string 2
    for(int i = 0; i < s2.length(); i++){
        arr[s2[i] - 'a']--;
    }
    
    // If count is 0 at each index then stings are same
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    cout << (areAnagrams("geeks", "kseeg") ? "true" : "false") << endl;
    cout << (areAnagrams("allergy", "allergic") ? "true" : "false") << endl;
    cout << (areAnagrams("g", "g") ? "true" : "false") << endl;
}