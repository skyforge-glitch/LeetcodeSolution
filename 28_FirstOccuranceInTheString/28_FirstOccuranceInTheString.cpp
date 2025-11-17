#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        // If needle is empty, answer is always 0 (as per problem statement)
        if (m == 0) return 0;

        // Loop through haystack, but only until there's enough space left
        // for the entire needle to fit (i.e., i <= n - m)
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Check character by character whether needle matches haystack
            // starting from index i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If we matched all characters of needle (j reached m),
            // then the substring starting at index i is the answer
            if (j == m) return i;
        }

        // Needle not found in haystack
        return -1;
    }
};