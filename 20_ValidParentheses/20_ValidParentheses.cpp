#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        // Map each opening bracket to its corresponding closing bracket
        unordered_map<char,char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        // Stack to store opening brackets encountered
        stack<char> st;

        // Traverse each character in the string
        for (char c : s) {

            // If the character is an opening bracket, push it onto the stack
            if (mp.count(c)) {
                st.push(c);
            }
            else {
                // If it's a closing bracket but stack is empty → invalid
                if (st.empty()) return false;

                // Check if the top of stack has the matching opening bracket
                if (mp[st.top()] == c)
                    st.pop();     // Valid pair found → pop it
                else
                    return false; // Mismatched bracket → invalid
            }
        }

        // If stack is empty → all brackets matched properly
        return st.empty();
    }
};