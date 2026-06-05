#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lp = 0;
        int rp = n - 1;
        int maxwater = 0;

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);

            int area = width * ht;
            maxwater = max(maxwater, area);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxwater;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution obj;
    cout << "Maximum Water: " << obj.maxArea(height);

    return 0;
}