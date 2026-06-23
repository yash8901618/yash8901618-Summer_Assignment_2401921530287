#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
 using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices
   vector<int> ans;
        
    for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove indices out of the current window boundary
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove smaller elements from the back as they are useless now
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
        dq.push_back(i);
            
            // 3. Add to result if our window has reached size k
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
