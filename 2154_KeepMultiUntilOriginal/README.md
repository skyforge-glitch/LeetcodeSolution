## 📘 LeetCode 2154 — Keep Multiplying Found Values by Two
# 🔍 Problem Summary

You are given an array nums and an integer original.
As long as original exists in nums, you must multiply it by 2.
Return the final value of original after all possible operations.

# 🧠 Intuition

A brute-force approach would search the array repeatedly, which takes O(n × k) time.
To optimize, we can use a hash set (unordered_set) to check presence in O(1) average time.

# Algorithm idea:

- Store all values of nums in a hash set.
- While the current original exists in the set → double it.
- Once it no longer exists → return it.
- This is the most optimal method.

# 🧮 Algorithm

- Insert every value of nums into a hash set for fast lookups.
- While original exists in the hash set:
- original = original * 2
- Return the final value of original.

# 🧾 Example

Input:

nums = [5, 3, 6, 1, 12]
original = 3


Process:

3  → in set → 6  
6  → in set → 12  
12 → in set → 24  
24 → not in set → stop


Output: 24

🧑‍💻 C++ Solution
//class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        // Create a hash set from nums for O(1) average lookup time
        unordered_set<int> mp(nums.begin(), nums.end());

        // Keep doubling original as long as it exists in the hash set
        while (mp.count(original)) {
            original *= 2;   // multiply original by 2
        }
        
        // Once original no longer appears in the set, return it
        return original;
    }
// };

# ⏱️ Complexity Analysis
# Operation	                        Complexity
- Building hash set	                O(n)
- Doubling loop	                    O(k), where k = number of doublings
- Total	                            O(n + k)
- Space	                            O(n) (hash set)

# "This is the optimal solution".