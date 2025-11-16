✅ Algorithm
1. Initialize

- mod = 1e9 + 7 — modulo to keep numbers within limits
- ans = 0 — will store the total number of substrings containing only '1'
- count = 0 — counts the current streak of consecutive '1'

2. Traverse each character in s

If character is '1'
    Increase count by 1
    Add count to ans
    Because every new '1' extends all previous substrings
    
    Example: for "111" → new substrings formed are 1, 2, 3 respectively

Else (character is '0')
    Reset count = 0
    Because substrings of only '1' cannot pass through '0'

3. Return the result

Apply modulo:
return ans % mod

This ensures the answer stays within integer limits.

🧠 Intuition

Every run of consecutive '1' of length k contributes:
= k*(k+1)/2

Instead of calculating this with formulas repeatedly,
we build this total dynamically:

- Every new '1' extends all previous substrings
- So we simply add count each time we see a '1'
- A '0' breaks the sequence, so we restart the streak.
- This approach avoids extra work and stays optimal.

# ⏱ Complexity
- Time Complexity: O(n)
One pass to count substrings in real-time

- Space Complexity: O(1)
Only uses constant extra variables (ans, count, mod)