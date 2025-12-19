#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {{'(',')'},{'{','}'},{'[',']'}};
        stack<int> st;

        for (char c : s){
            if (mp.count(c)) st.push(c);

            else {
                if (st.empty()) return false;

                if (mp[st.top()] == c) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};