#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        // If there are more than 1440 time-points, two must be identical
        // (because there are only 1440 possible minutes in a day)
        // → minimum difference is definitely 0
        if (n > 1440) return 0;

        vector<int> minutes;
        minutes.reserve(n); // Reserve space for n values to avoid reallocations

        // Convert each "HH:MM" string into total minutes from midnight
        for (auto &time : timePoints) {
            int totalMinutes =
                stoi(time.substr(0, 2)) * 60 +     // hours → minutes
                stoi(time.substr(3, 2));           // minutes part
            minutes.push_back(totalMinutes);
        }

        // Sort all times so that minimum difference will be between neighbors
        sort(minutes.begin(), minutes.end());

        // Handle circular difference:
        // Example: 23:59 (1439) and 00:00 (0)
        // difference = (0 + 1440) - 1439 = 1 minute
        int minTime = (minutes[0] + 1440) - minutes[n - 1];

        // Check consecutive differences in sorted order
        for (int i = 0; i < n - 1; i++) {
            int timeDiff = minutes[i + 1] - minutes[i];
            minTime = min(minTime, timeDiff);
        }

        return minTime;
    }
};