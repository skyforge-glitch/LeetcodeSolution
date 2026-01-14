# 215. Kth Largest Element in an Array

## 🧩 Problem Statement

Given an integer array `nums` and an integer `k`, return the **kth largest element** in the array.

### Notes
- It is the kth largest element in the **sorted order**, not the kth distinct element.
- The solution should be efficient.

---

## ✅ Example

**Input**
```txt
nums = [3,2,1,5,6,4]
k = 2
```

**Output**
```txt
5
```

---

## 💡 Approach 1: Min Heap (Priority Queue)

### Intuition
Maintain a **min heap of size `k`**:
- Keep pushing elements into the heap.
- If heap size exceeds `k`, remove the smallest element.
- The top of the heap is the **kth largest element**.

### Algorithm
1. Initialize a min heap.
2. Traverse the array:
   - Push each element.
   - If heap size > `k`, pop.
3. Return the heap top.

### C++ Code
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
```

### Complexity
| Metric | Value |
|------|------|
| Time | O(n log k) |
| Space | O(k) |

---

## ⚡ Approach 2: Quickselect (Optimized)

### Intuition
- Based on **QuickSort partition**
- Place the pivot in its correct position
- Recurse only on the needed side
- Target index = `n - k`

### C++ Code
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];

        int p = partition(nums, l, r);
        if (p == k) return nums[p];
        else if (p < k) return quickSelect(nums, p + 1, r, k);
        else return quickSelect(nums, l, p - 1, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
```

### Complexity
| Metric | Value |
|------|------|
| Average Time | O(n) |
| Worst Time | O(n²) |
| Space | O(1) |

---

## 🎯 Key Takeaways

- **Min Heap** → safer, simpler
- **Quickselect** → faster on average
- Very common **interview problem**

---

Happy Coding 🚀