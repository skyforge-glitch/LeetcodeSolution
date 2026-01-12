# LeetCode 1266 – Minimum Time Visiting All Points

## 📌 Problem Statement
You are given a list of points on a 2D plane.
Starting from the first point, you must visit all points in the given order.

In **1 second**, you can move:
- Horizontally
- Vertically
- Diagonally

Return the **minimum time** required to visit all points.

---

## 🧠 Explanation of My Approach
For every pair of consecutive points:

- Calculate horizontal distance:
  diffX = |x2 - x1|
- Calculate vertical distance:
  diffY = |y2 - y1|

### Movement logic:
- Diagonal moves: min(diffX, diffY)
- Straight moves: abs(diffX - diffY)

### Total time:
min(diffX, diffY) + abs(diffX - diffY)

This is equivalent to:
max(diffX, diffY)

---

## 💻 C++ Solution (My Code)

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;

        for (int i = 0; i < n - 1; i++){
            int diffX = abs(points[i][0] - points[i+1][0]);
            int diffY = abs(points[i][1] - points[i+1][1]);
            time += min(diffX, diffY) + abs(diffX - diffY);
        }
        return time;
    }
};
```

---

## ⏱ Time Complexity
- O(n)

## 📦 Space Complexity
- O(1)

---

## ✅ Key Notes
- Greedy solution
- Uses diagonal movement efficiently
- Accepted on LeetCode

---

✨ Happy Coding!