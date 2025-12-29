# 🏆 Find Players With Zero or One Losses (LeetCode 2225)

## 📌 Problem Statement
You are given an integer array `matches`, where `matches[i] = [winnerᵢ, loserᵢ]` indicates that the player `winnerᵢ` defeated player `loserᵢ` in a match.

Return a list `answer` of size `2` where:
- `answer[0]` is a list of players who **have not lost any matches**.
- `answer[1]` is a list of players who **have lost exactly one match**.

Both lists should be returned in **increasing order**.

---

## 🧠 Core Idea
The key observation:
- Every player can be identified by **number of losses**
- Winners do **not increase** their loss count
- Losers increase their loss count by `1`

We track the **loss count** of each player using a hash map.

---

## 🧩 Approach

1. Create an `unordered_map<int, int>` to store the number of losses per player.
2. Iterate over each match:
   - Ensure the winner exists in the map (loss count stays the same).
   - Increment the loss count of the loser.
3. Traverse the map:
   - Players with `0` losses → `zeroLost`
   - Players with `1` loss → `oneLost`
4. Sort both result arrays.
5. Return the result.

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> freq;

        // Count losses
        for (auto &m : matches) {
            freq[m[0]] += 0;  // ensure winner exists
            freq[m[1]] += 1;  // increment loss count
        }

        vector<int> zeroLost, oneLost;

        for (auto &p : freq) {
            if (p.second == 0)
                zeroLost.push_back(p.first);
            else if (p.second == 1)
                oneLost.push_back(p.first);
        }

        sort(zeroLost.begin(), zeroLost.end());
        sort(oneLost.begin(), oneLost.end());

        return {zeroLost, oneLost};
    }
};
```

---

## ⏱️ Complexity Analysis
- **Time Complexity:** `O(n log n)`  
  - `O(n)` for processing matches  
  - Sorting the results
- **Space Complexity:** `O(n)` for the hash map and result arrays

---

## 🧪 Example

**Input**
```
matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
```

**Output**
```
[[1,2,10],[4,5,7,8]]
```

---

## 🚀 Why This Works Well
- Handles players who never lose
- Avoids unnecessary data structures
- Clean and readable logic
- Scales efficiently for large inputs

---

## 🏁 Conclusion
By simply tracking the number of losses per player, we can efficiently categorize players into zero-loss and one-loss groups with minimal overhead.

Happy Coding! 🎯
