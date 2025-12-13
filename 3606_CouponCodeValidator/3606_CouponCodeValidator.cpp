#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        // Number of coupons
        int n = code.size();

        // Map to store valid coupon codes grouped by business line
        unordered_map<string, vector<string>> mp;

        // Set of allowed business lines for O(1) validation
        unordered_set<string> validBusiness = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        // Required output order of business lines
        vector<string> category = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        // Validate each coupon entry
        for (int i = 0; i < n; i++) {

            // Skip inactive coupons or empty codes
            if (!isActive[i] || code[i].empty())
                continue;

            // Check that the coupon code contains only
            // alphanumeric characters or '_'
            bool isValidCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    isValidCode = false;
                    break;
                }
            }

            // Skip invalid coupon codes
            if (!isValidCode)
                continue;

            string business = businessLine[i];

            // Store the coupon if the business line is valid
            if (validBusiness.count(business)) {
                mp[business].push_back(code[i]);
            }
        }

        vector<string> result;

        // Collect coupons in the required business order
        for (const string& business : category) {

            // Sort coupons lexicographically within each category
            auto& coupons = mp[business];
            sort(coupons.begin(), coupons.end());

            // Append to the final result
            result.insert(result.end(), coupons.begin(), coupons.end());
        }

        return result;
    }
};