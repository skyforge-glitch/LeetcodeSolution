# Algorithm

- Initialize

- ans = 0 → stores total operations
- ones = 0 → counts consecutive '1' characters

- n = s.size()

# Procedure

Loop through each character of the string:
If s[i] == '1'
    → Increment ones because we have another consecutive '1'.

Else (s[i] == '0')
    → Check if:

the next character is '1', or
it is the last character of the string

If yes → add ones to ans.
Continue until the end.
Finally, return ans.

# Intuition

Visualize the string as:

'1' → coin

'0' → empty slot

A '1' can form an operation with a '0' depending on the rules.
We only need to count how many '1's appear before a '0' that is able to interact.
Every time we meet such a '0', we know all previous consecutive '1's can contribute exactly once.

This avoids:

- extra loops
- double counting
- unnecessary swaps simulation
- It gives the maximum possible operations directly.

# Example Walkthrough
- Input: "11010"
i	s[i]	ones	ans	Action
0	'1'	1	0	Increment ones
1	'1'	2	0	Increment ones
2	'0'	2	2	Next is '1', so add ones to ans
3	'1'	3	2	Increment ones
4	'0'	3	5	Last char, add ones to ans
Output: 5

- ✔ Maximum operations = 5

# Complexity Analysis
- Complexity	Explanation
- Time: O(n)	Single pass through the string
- Space: O(1)	Only two counters (ones, ans)