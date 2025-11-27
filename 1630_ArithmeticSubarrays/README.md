# LeetCode 1630 — Arithmetic Subarrays

## 🧩 Problem Summary
You are given:
- An array `nums`
- Two arrays `l` and `r`, where each pair `(l[i], r[i])` defines a query

For each query, you must check whether the subarray:
```
nums[l[i]], nums[l[i] + 1], ..., nums[r[i]]
```
can form an **arithmetic sequence** *after sorting*.

An arithmetic sequence means:
```
difference between every pair of adjacent elements is equal
```

Example:
```
[3, 5, 1] → sorted = [1, 3, 5] → differences = [2, 2] → valid
```

---

## ✔️ Approach (Sorting Method — Simple & Clean)

For each query:

1. Extract the subarray  
2. Sort it  
3. Compute the initial difference  
4. Check if every consecutive pair has the same difference  
5. Store true/false in the result

This approach is easy to understand and passes all constraints.

---

## ✅ C++ Solution (Sorting Approach)

```cpp
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans(m);

        for (int i=0; i<m; i++){

            vector<int> subArr(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(subArr.begin(),subArr.end());

            int len = subArr.size();
            int diff = subArr[1] - subArr[0];

            bool issue = false;

            for (int j=2; j<len; j++){
                if (subArr[j] - subArr[j-1] != diff) {
                    issue = true;
                    break;
                }
            }
            ans[i] = !issue;
        }
        return ans;
    }
};
```

---

## 🧠 Complexity

Let:
- `m` = number of queries  
- `k` = size of each subarray

### Sorting each subarray:
```
O(k log k)
```

### Total:
```
O(m × k log k)
```

This is efficient enough for LeetCode constraints.

---

## ⚡ Optional: Optimal O(m × k) Method (No Sorting)

A faster approach exists using:
- min/max
- checking divisibility
- mapping each value to its expected position

But it is harder to understand and more prone to implementation mistakes.

The sorting method above is the **best balance of clarity and performance**.

---

## 📄 Final Notes

- This problem tests understanding of arithmetic progression and subarray manipulation.
- Sorting simplifies the logic and ensures clean, reliable code.
- Only switch to the O(k) optimal method for extremely high constraints.

---