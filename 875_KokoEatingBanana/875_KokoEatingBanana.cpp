#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to calculate total hours required
    // if Koko eats at speed = mid bananas per hour
    long long hourEating(vector<int>& piles, int mid) {
        long long hours = 0;

        // For each pile, calculate how many hours are needed
        for (long long x : piles) {
            // If pile is exactly divisible by mid
            if (x % mid == 0)
                hours += x / mid;
            else
                // Otherwise, one extra hour is needed (ceil division)
                hours += x / mid + 1;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 'high' represents the maximum possible eating speed
        // which is the largest pile size
        int high = INT_MIN;
        for (int pile : piles)
            high = max(pile, high);

        // Minimum possible eating speed
        int low = 1;

        // Binary search on eating speed
        while (low <= high) {
            // Calculate mid safely to avoid overflow
            int mid = low + (high - low) / 2;

            // Total hours required if eating speed = mid
            long long hours = hourEating(piles, mid);

            // If hours exceed allowed time,
            // Koko is eating too slowly
            if (hours > h) {
                low = mid + 1;
            } 
            // Otherwise, mid is a valid speed,
            // try to find a smaller valid speed
            else {
                high = mid - 1;
            }
        }

        // 'low' will be the minimum valid eating speed
        return low;
    }
};