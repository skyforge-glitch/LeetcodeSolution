# Prime Palindrome (LeetCode 866)

## 🧩 Problem Statement
Given an integer `n`, return the **smallest prime number** that is **greater than or equal to `n`** and is also a **palindrome**.

- A **prime number** has exactly two divisors: `1` and itself.
- A **palindrome** reads the same forward and backward.

---

## 🧠 Initial Intuition (Brute Force Approach)

The most straightforward idea is:

> Start from `n`, check every number one by one, and return the first number that is **both prime and palindrome**.

### Brute Force Steps
1. For each number `i ≥ n`:
   - Check if `i` is a palindrome
   - Check if `i` is prime
2. Stop when both conditions are satisfied

### Optimizations Tried
- Skip even numbers (since all primes > 2 are odd)
- Skip even-length palindromes (divisible by 11, except 11)
- Optimize prime checking up to `√i`

### Why Brute Force Failed (TLE)
Even after optimizations, the approach still:
- Iterated over **tens of millions of numbers**
- Performed:
  - String conversions
  - Palindrome checks
  - Prime checks up to `√n` (≈ 7000 operations per check)

For inputs like:
```
n ≈ 5 × 10⁷
```

This resulted in **billions of operations**, causing **Time Limit Exceeded (TLE)**.

➡️ Conclusion:  
Brute force was doing too much unnecessary work by checking numbers that could **never** be valid answers.

---

## 🔑 Key Observation That Changed the Approach

### Observation 1
> **All even-length palindromes (except 11) are divisible by 11**, so they cannot be prime.

### Observation 2
> **Prime palindromes are extremely rare** compared to the total number of integers.

### Breakthrough Insight
Instead of:
```
Check every number → filter palindromes
```

We should:
```
Generate palindromes directly → check primality
```

This drastically reduces the search space.

---

## 🚀 Optimized Approach (Palindrome Generation)

### Core Idea
- Generate **only odd-length palindromes**
- Check if the generated palindrome:
  - Is ≥ `n`
  - Is prime

### How Palindromes Are Generated
1. Take a number `i` as the left half
2. Mirror it around the center digit
3. Remove the duplicated middle digit to keep the length odd

Example:
```
i = 123
Palindrome = 12321
```

Every odd-length palindrome can be generated **uniquely** this way.

---

## 📊 Why This Works Efficiently

| Approach | Numbers Checked |
|--------|----------------|
Brute force | ~50,000,000 |
Optimized brute force | ~25,000,000 |
Palindrome generation | ~100,000 |

This reduction is what makes the solution pass within time limits.

---

## ⏱️ Complexity Analysis

- **Palindrome generation:** `O(10^5)` candidates
- **Primality check:** `O(√n)` per candidate
- **Overall:** Efficient and well within constraints

---

## ✅ Final C++ Implementation

```cpp
class Solution {
public:
    bool isPrime(int x){
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;

        for (int i = 3; i * i <= x; i += 2){
            if (x % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n <= 11){
            vector<int> lowBase = {2,3,5,7,11};
            for (int x : lowBase){
                if (x >= n) return x;
            }
        }

        for (int i = 1; i < 100000; i++){
            string s = to_string(i);
            string s1 = s;
            reverse(s1.begin(), s1.end());
            s1.erase(0, 1);
            int num = stoi(s + s1);

            if (num >= n && isPrime(num))
                return num;
        }
        return -1;
    }
};
```

---

## 🧪 Example

**Input**
```
n = 13
```

**Output**
```
101
```

---

## 🏁 Conclusion

- The brute force solution is intuitive but not scalable.
- The key improvement is **changing the search space**, not micro-optimizing checks.
- Generating palindromes directly is the **optimal and intended solution**.

This progression—from brute force to optimized palindrome generation—demonstrates strong problem-solving and algorithmic thinking.

Happy coding! 🚀

---