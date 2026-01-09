#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // mp1: mapping from characters in s -> characters in t
        // mp2: reverse mapping from characters in t -> characters in s
        unordered_map<char, char> mp1, mp2;

        // Traverse both strings character by character
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];

            // If 'a' is already mapped, it must map to the same character 'b'
            if (mp1.count(a) && mp1[a] != b)
                return false;

            // If 'b' is already mapped, it must map back to the same character 'a'
            if (mp2.count(b) && mp2[b] != a)
                return false;

            // Establish the mapping in both directions
            mp1[a] = b;
            mp2[b] = a;
        }

        // All mappings are consistent
        return true;
    }
};