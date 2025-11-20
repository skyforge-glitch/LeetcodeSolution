# LeetCode 58 — Length of Last Word (README)
# 📝 Problem Summary

Given a string s containing words and spaces, return the length of the last word in the string.
A word is defined as a sequence of non-space characters.
There may be multiple trailing spaces at the end.

# The string can be something like:
- `"Hello World" → last word "World" → length = 5`
- `" fly me to the moon " → last word "moon" → length = 4`
- `"a" → last word "a" → length = 1`

# 🧠 Key Idea

- The easiest way is to start scanning from the end of the string:
- Skip trailing spaces (because "Hello " still ends with spaces).
- Count characters until the next space or the beginning of the string.
- The count we get is the length of the last word.
- This avoids extra space and avoids splitting the string — making it efficient.

# ⏱️ Time & Space Complexity

- Time Complexity: O(n) — We might scan the whole string once.
- Space Complexity: O(1) — No extra memory used.

# 💡 Why This Works

Instead of dealing with multiple spaces between words and at the end, scanning backward ensures:

- You skip irrelevant spaces.
- You count exactly one word—the last one.
- The logic stays clean, simple, and efficient.

# ✅ C++ Solution (with minimal logic)
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        int len = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};
```