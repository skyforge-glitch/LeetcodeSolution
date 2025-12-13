# Validate Coupons

## 🧩 Problem Description

You are given three arrays of equal length:

- `code[i]` — the coupon code  
- `businessLine[i]` — the business category of the coupon  
- `isActive[i]` — whether the coupon is active  

Your task is to **validate and organize coupons** based on the following rules.

---

## ✅ Coupon Validation Rules

A coupon is considered **valid** if:

1. `isActive[i]` is `true`
2. `code[i]` is **not empty**
3. `code[i]` contains **only**:
   - lowercase/uppercase letters  
   - digits  
   - underscore (`_`)  
4. `businessLine[i]` belongs to one of:
   - `electronics`
   - `grocery`
   - `pharmacy`
   - `restaurant`

---

## 📤 Output Requirements

- Group valid coupons by business category
- Sort coupons **lexicographically** within each category
- Return all coupons in the following order:
  1. electronics  
  2. grocery  
  3. pharmacy  
  4. restaurant  

---

## 🛠️ Approach

1. Use an `unordered_set` to validate business categories in **O(1)** time
2. Use an `unordered_map<string, vector<string>>` to group valid coupons
3. Validate coupon codes character-by-character
4. Sort coupons within each category
5. Merge results in the required order

---

## ⏱️ Complexity Analysis

- **Time Complexity:**  
  - Validation: `O(N * L)` where `L` is coupon length  
  - Sorting: `O(K log K)` per category  
  - Overall: `O(N log N)` in worst case  

- **Space Complexity:**  
  - `O(N)` for storing valid coupons  

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        unordered_map<string, vector<string>> mp;

        unordered_set<string> validBusiness = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<string> category = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (int i = 0; i < n; i++) {

            if (!isActive[i] || code[i].empty())
                continue;

            bool isValidCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    isValidCode = false;
                    break;
                }
            }

            if (!isValidCode)
                continue;

            if (validBusiness.count(businessLine[i])) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> result;

        for (const string& business : category) {
            auto& coupons = mp[business];
            sort(coupons.begin(), coupons.end());
            result.insert(result.end(), coupons.begin(), coupons.end());
        }

        return result;
    }
};
```

---

## 📌 Key Takeaways

- Input validation is critical before processing
- Hash-based containers improve performance
- Maintaining output order explicitly avoids bugs
- Clean separation of validation, grouping, and sorting logic

---

Happy Coding 🚀

---