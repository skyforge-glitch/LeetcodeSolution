Intuition:

- In the encoding: 
    0 → one-bit character
    10 or 11 → two-bit character
- To check if the last bit is a one-bit character, we only need to count consecutive 1's immediately before it.
- Even number of consecutive 1's → last bit stands alone (1-bit).
- Odd number of consecutive 1's → last bit is part of a two-bit character.

Example Walkthrough:

Input: [1, 0, 0]

Step-by-step:

i   bits[i]  count  Action
1   0        0      Stop counting
0   1        1      Increment count

Output: true (last bit is 0 → one-bit character)

Input: [1, 1, 1, 0]

Step-by-step:

i   bits[i]  count  Action
2   1        1      Increment count
1   1        2      Increment count
0   1        3      Increment count

Output: false (count = 3 → odd → last 0 is part of two-bit character)

Complexity Analysis:

Time Complexity: O(n) — single pass from second last element backwards.
Space Complexity: O(1) — only a counter is used.