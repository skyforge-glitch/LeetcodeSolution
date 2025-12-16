# LeetCode 122 – Best Time to Buy and Sell Stock II

## 🧠 Problem Overview
You are given an array `prices` where `prices[i]` represents the price of a stock on the `i-th` day.

- You may complete **as many transactions as you like** (buy one and sell one share of the stock multiple times).
- However, you may **not hold more than one stock at a time**.

The task is to **maximize the total profit**.

---

## 💡 Key Insight (Greedy Approach)
If the price of the stock **increases from one day to the next**, we can make a profit by buying on the previous day and selling on the current day.

Instead of trying all buy/sell combinations, we simply:
- Traverse the array
- Add up all **positive price differences**

This works because multiple small profitable transactions yield the same result as one large transaction over an increasing sequence.

---

## ✍️ Algorithm
1. Initialize `profit = 0`
2. Loop from day `1` to `n-1`
3. If `prices[i] > prices[i-1]`, add the difference to `profit`
4. Return `profit`

---

## 🧾 C++ Implementation
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();      // Number of days
        int profit = 0;             // Stores total profit

        // Traverse prices from second day onward
        for (int i = 1; i < n; i++){
            // If today's price is higher than yesterday's
            if (prices[i] > prices[i - 1]){
                // Take the profit
                profit += prices[i] - prices[i - 1];
            }
        }
        
        // Return the maximum total profit
        return profit;
    }
};
```

---

## 🔍 Example
**Input:**
```
prices = [7,1,5,3,6,4]
```

**Profit Calculation:**
- Buy at 1, sell at 5 → profit = 4
- Buy at 3, sell at 6 → profit = 3

**Total Profit = 7**

---

## ⏱️ Complexity Analysis

| Metric | Complexity |
|------|------------|
| Time | O(n) |
| Space | O(1) |

---

## 🎯 Why This Works
- Captures all upward price movements
- Avoids unnecessary state tracking
- Optimal for unlimited transactions

---

## 🧠 One-line Memory Trick
> **Whenever the price goes up, take the profit.**

---

✅ This solution is optimal, simple, and widely used in interviews.

---