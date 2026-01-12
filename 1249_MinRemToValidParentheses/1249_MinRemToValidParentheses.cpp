#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> remove(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else if (s[i] == ')') {
                if (!st.empty()){
                    st.pop();
                } else {
                    remove[i] = true; // invalid '(' to be removed;
                }
            }
        }

        // invalid ')' (extra) to be removed;
        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!remove[i]) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};