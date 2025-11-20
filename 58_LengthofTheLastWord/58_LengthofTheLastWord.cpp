#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;   // Start from the last character of the string
        int len = 0;     // This will store the length of the last word

        // Step 1: Skip all trailing spaces at the end of the string
        // Example: "Hello World   " → we skip the last 3 spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Step 2: Count characters until we hit a space or the beginning
        // Now we are at the last character of the last word
        // Example: "Hello World   " → i is now at 'd'
        while (i >= 0 && s[i] != ' ') {
            len++;   // Increase length for each character in the last word
            i--;     // Move left
        }

        // Step 3: Return the length
        return len;
    }
};