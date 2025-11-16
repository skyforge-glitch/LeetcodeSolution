Algorithm Initialize:

ans = 0 → to store total operations.
ones = 0 → to count consecutive '1's.
n = s.size().
Loop through each character of the string:
If it is '1', increment ones.
Else (character is '0'):
If the next character is '1' or it is the last character:
Add ones to ans.
Return ans.

Intuition

- Think of the string as a sequence of '1's (coins) and '0's (empty spots).
- Each '1' can interact with '0's under the operation rules.
- By tracking consecutive '1's and adding them to the answer whenever a '0' can pair with them, we count all valid operations efficiently.
- This ensures we capture every possible operation without double counting.

Example Walkthrough
Input: "11010"

Step-by-step:

i	s[i]	ones	ans	Action
0	'1'	1	0	Increment ones
1	'1'	2	0	Increment ones
2	'0'	2	2	Next is '1', add ones to ans
3	'1'	3	2	Increment ones
4	'0'	3	5	Last character, add ones to ans

Output: 5
✅ Maximum operations = 5

Complexity Analysis:

Time Complexity: O(n) — single pass over the string.
Space Complexity: O(1) — only a few counters used.