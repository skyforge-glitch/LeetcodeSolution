
### LeetCode 539 — Minimum Time Difference

## 🧠 Problem Summary
You are given a list of time points in **24-hour "HH:MM" format**.  
Your task is to find the **minimum difference in minutes** between any two time points.

Because time wraps around after midnight, the difference between `"23:59"` and `"00:00"` is **1 minute**.

---

## 🚀 Key Points

- There are only **1440 possible minutes** in a day.
- If the input contains **more than 1440 time points**, at least two must be duplicates → return **0**.
- Convert each `"HH:MM"` into **total minutes** from midnight.
- Sort the results and compute:
  - Differences between adjacent times
  - Circular difference between last and first

---

## ✅ Algorithm Steps

1. If the number of time points > 1440 → return `0`.
2. Convert each time string into an integer:  
   `totalMinutes = hours * 60 + minutes`.
3. Sort the list of converted times.
4. Compute:
   - Adjacent differences.
   - Circular wrap-around difference:
     ```
     diff = (first + 1440) - last
     ```
5. Return the minimum of all differences.

---

## 🧩 Time Complexity
- Conversion: **O(n)**
- Sorting: **O(n log n)**
- Scanning: **O(n)**  
**Total:** `O(n log n)`

---

## 💡 Example

### Input:
```
["23:59", "00:00"]
```

### Output:
```
1
```

Explanation:  
`23:59 → 1439` minutes  
`00:00 → 0` minutes  
Circular difference = `1440 - 1439 = 1`

---

## 🛠️ C++ Code

```cpp
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 1440) return 0; // More than total minutes in a day → duplicate exists

        vector<int> minutes;
        minutes.reserve(n);

        // Convert "HH:MM" into total minutes
        for (auto &time : timePoints) {
            int totalMinutes =
                stoi(time.substr(0, 2)) * 60 +
                stoi(time.substr(3, 2));
            minutes.push_back(totalMinutes);
        }

        sort(minutes.begin(), minutes.end());

        // Circular difference: last → first
        int minTime = (minutes[0] + 1440) - minutes[n - 1];

        // Adjacent time differences
        for (int i = 0; i < n - 1; i++) {
            minTime = min(minTime, minutes[i + 1] - minutes[i]);
        }

        return minTime;
    }
};
```

---

## 🏁 Final Notes
- The trickiest part is handling the **wrap-around** time difference.
- Storing times as **minutes** simplifies comparisons.
- Sorting ensures all closest pairs are adjacent.

---

Happy coding! 🚀

---