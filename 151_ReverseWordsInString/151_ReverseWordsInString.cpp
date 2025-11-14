#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;   // to store extracted words
        string word = "";       // currently building word
        string result = "";     // final reversed string

        // Step 1: Extract words manually (without using split)
        for (char c : s) {
            if (c != ' ') {     
                // build current word
                word += c;
            } 
            else if (word != "") {
                // space encountered → push the current word if not empty
                words.push_back(word);
                word = "";       // reset for next word
            }
        }

        // push the last word (because last word ke baad space nahi hota)
        if (word != "") 
            words.push_back(word);

        // Step 2: Build result by taking words in reverse order
        int n = words.size();
        while (n--) {
            result += words[n];  // add word from end

            if (n != 0)
                result += ' ';   // add space except after last word
        }

        return result;           // final reversed sentence
    }
};