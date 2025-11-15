#include <bits/stdc++.h>
using namespace std;


// This solution is for Linear O(1) Space Complexity
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        removeExtraSpaces(s);

        // Step 2: Reverse entire string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word inside the reversed string
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }

private:
    void removeExtraSpaces(string &s) {
        int i = 0, j = 0;
        
        // skip initial spaces
        while (j < s.size() && s[j] == ' ') j++;

        bool spacePending = false;

        while (j < s.size()) {
            if (s[j] != ' ') {
                if (spacePending) {
                    s[i++] = ' ';
                    spacePending = false;
                }
                s[i++] = s[j];
            } else {
                spacePending = true;
            }
            j++;
        }

        // resize to new length (remove trailing spaces)
        s.resize(i);
    }
};
