#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long hourEating(vector<int>& piles, int mid){
        long long hours = 0;
        for (long long x : piles){
            if (x % mid == 0) hours += x/mid;
            else hours += x/mid + 1;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN;
        for (int pile : piles) high = max(pile,high);

        int low = 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            long long hours = hourEating(piles,mid);

            if (hours > h){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// 20min thinking , 20min coding , 5 min debugging