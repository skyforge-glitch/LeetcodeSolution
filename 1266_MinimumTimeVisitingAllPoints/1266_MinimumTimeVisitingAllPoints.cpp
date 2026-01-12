#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;

        for (int i = 0; i < n - 1; i++){
            int diffX = abs(points[i][0] - points[i+1][0]);
            int diffY = abs(points[i][1] - points[i+1][1]);
            time += max(diffX,diffY);
        }
        return time;
    }
};