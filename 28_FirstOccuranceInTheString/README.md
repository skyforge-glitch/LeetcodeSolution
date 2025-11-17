# 🧠 Explanation

- We need to find the first position in haystack where needle appears.

Example:
haystack = "sadbutsad"
needle = "sad"
Result → 0 (first "sad" starts at index 0)

# How the algorithm works
Loop i from 0 to n - m
At each i, compare:
haystack[i] with needle[0]
haystack[i+1] with needle[1]

...

If all characters match → return i
If no match after checking all positions → return -1

# ⏱ Time Complexity
Outer loop runs up to n − m times
Inner loop compares up to m characters
Total: O(n × m)
Good for constraints of this problem.

# 📦 Space Complexity
Uses only a few variables
O(1) extra space