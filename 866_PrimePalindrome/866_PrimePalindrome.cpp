#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Checks if a number is prime
    bool isPrime(int x){
        // Numbers less than 2 are not prime
        if (x < 2) return false;

        // Handle even numbers (only 2 is prime)
        if (x % 2 == 0) return x == 2;

        // Check odd divisors up to sqrt(x)
        for (int i = 3; i * i <= x; i += 2){
            if (x % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        // Base cases: small prime palindromes
        // (11 is the only even-length prime palindrome)
        if (n <= 11){
            vector<int> lowBase = {2, 3, 5, 7, 11};
            for (int x : lowBase){
                if (x >= n) return x;
            }
        }

        // Generate odd-length palindromes only
        for (int i = 1; i < 100000; i++){
            // Convert the left half to string
            string s = to_string(i);

            // Reverse it to form the mirrored part
            string s1 = s;
            reverse(s1.begin(), s1.end());

            // Remove first character to avoid duplicating the middle digit
            s1.erase(0, 1);

            // Construct the full palindrome
            int num = stoi(s + s1);

            // Check if the palindrome is >= n and prime
            if (num >= n && isPrime(num))
                return num;
        }

        // Problem guarantees an answer exists
        return -1;
    }
};