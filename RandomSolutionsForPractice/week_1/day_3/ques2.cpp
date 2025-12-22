#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    vector<int> arr;
    vector<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        arr.push_back(val);
        // Important: Use <= so duplicate minimums are tracked
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (arr.empty()) return;
        
        // If the element we are removing is the current minimum, 
        // we must remove it from the minStack too.
        if (arr.back() == minStack.back()) {
            minStack.pop_back();
        }
        arr.pop_back();
    }
    
    int top() {
        if (arr.empty()) return -1; // Or throw runtime_error
        return arr.back();
    }
    
    int getMin() {
        if (minStack.empty()) return -1; // Final safety check
        return minStack.back();
    }
};