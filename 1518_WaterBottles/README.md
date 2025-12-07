
# LeetCode 1518 — Water Bottles (C++)

## 🧠 Problem Summary  
You are given:
- `numBottles` → number of full water bottles you initially have  
- `numExchange` → number of empty bottles required to exchange for one new full bottle  

Each time you drink a bottle, you gain an empty bottle.  
You can exchange empty bottles for new full ones as long as you have at least `numExchange`.  

Return the **total number of bottles you can drink**.

---

## ✅ Code with Comments (C++)

```cpp
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;                // total exchanged bottles count
        int n = numBottles;         // current number of empty/full bottles available

        // Repeat exchange as long as we can get more full bottles
        while (n / numExchange > 0) {
            ans += n / numExchange;                  // number of new bottles obtained by exchange
            n = (n / numExchange) + n % numExchange; // new full bottles + leftover empty bottles
        }

        // total drunk = initial bottles + bottles obtained by exchanging
        return numBottles + ans;
    }
};
```

---

## 💡 Explanation  
This solution works because:  
- Each exchange gives you new full bottles you can drink.  
- Drinking them gives you more empty bottles.  
- Keep repeating until you cannot exchange anymore.  

This is a simulation of the bottle exchange process.

---

## 📌 Example  
Input:  
```
numBottles = 9  
numExchange = 3  
```

Output:  
```
13
```

---

## 📂 File Info  
This README is auto‑generated for study/reference usage.

---