#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Two-pointer approach for sorted array
        int left = 0;
        int right = numbers.size() - 1;

        // Move pointers until they meet
        while (left < right) {

            int sum = numbers[left] + numbers[right];

            // If the pair matches the target, return 1-based indices
            if (sum == target) {
                return {left + 1, right + 1};
            }
            // If the sum is too large, move right pointer left
            else if (sum > target) {
                right--;
            }
            // If the sum is too small, move left pointer right
            else {
                left++;
            }
        }

        // Problem guarantees exactly one solution,
        // but return something valid to satisfy function requirements.
        return {left + 1, right + 1};
    }
};