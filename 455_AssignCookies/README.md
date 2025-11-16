LeetCode 455 — Assign Cookies
Problem Summary

You are given two integer arrays:

- g[] → the greed factor of each child (how much size of cookie makes them happy).
- s[] → the sizes of cookies available.
- Your task is to assign cookies to children such that:
- Each child gets at most one cookie.
- A child i is content if s[j] >= g[i].
- Maximize the number of content children.
- Return the maximum number of content children.

Algorithm (Step-by-Step)

Sort both arrays:

- g in ascending order → smallest greed first.
- s in ascending order → smallest cookie first.

Initialize two pointers:

- i = 0 → index for children.
- j = 0 → index for cookies.
- Loop while both pointers are valid (i < g.size() and j < s.size()):
- If s[j] >= g[i] → this cookie satisfies the child:
- Increment i (child content).
- Move to next cookie (j++) regardless.
- Return i → number of children content.

Intuition

- The greedy approach works here:
- Always give the smallest sufficient cookie to the least greedy child.
- This maximizes the chance that bigger cookies can satisfy greedier children.
- Sorting ensures that we match cookies efficiently without wasting larger cookies on less greedy children.

Example Walkthrough

Input:
g = [1,2,3], s = [1,1]

Step-by-step:
i	j	g[i]	s[j]	Action	i (content)
0	0	1	1	s[j] >= g[i] → assign	1
1	1	2	1	s[j] < g[i] → cannot assign	1
Cookie index moves to end → loop ends
Output: 1

Another Example:

g = [1,2], s = [1,2,3]
Assign 1 → 1, assign 2 → 2 → all children content
Output: 2

Complexity Analysis

Time Complexity:

Sorting: O(m log m + n log n)
Two-pointer traversal: O(m + n)
Overall: O(m log m + n log n)
Space Complexity: O(1) extra space (if in-place sorting).