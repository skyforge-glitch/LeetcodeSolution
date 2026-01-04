#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisors(int num) {
        int count = 0;
        int sum = 0;

        // Iterate till sqrt(num)
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int d1 = i;
                int d2 = num / i;

                // If both divisors are same (perfect square)
                if (d1 == d2) {
                    count++;
                    sum += d1;
                } 
                else {
                    count += 2;
                    sum += d1 + d2;
                }

                // More than 4 divisors → useless
                if (count > 4) 
                    return 0;
            }
        }

        return (count == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        unordered_map<int,int> mp;

        for (int num : nums) {
            // Memoization to avoid recomputation
            if (!mp.count(num))
                mp[num] = divisors(num);

            totalSum += mp[num];
        }

        return totalSum;
    }
};