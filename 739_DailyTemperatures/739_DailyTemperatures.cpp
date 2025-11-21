#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        
        // This will store the result:
        // answer[i] = number of days until a warmer temperature after day i.
        vector<int> answer(n, 0);

        // Monotonic decreasing stack:
        // It stores *indices* of days, and their temperatures will be in
        // decreasing order (top has the most recent smallest one).
        stack<int> stack;

        // Traverse all days from left to right
        for (int i = 0; i < n; i++) {

            // While the current temperature is hotter than the temperature
            // at the index stored on top of the stack:
            // It means we have found the next warmer day for that index.
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {

                // 'last' = index of the previous colder day
                int last = stack.top();
                stack.pop();

                // Difference in days = how long that previous day waited
                answer[last] = i - last;
            }

            // Push the current day index to stack for future checking
            stack.push(i);
        }

        // Remaining indices in stack do not have a warmer future day → answer stays 0
        return answer;
    }
};