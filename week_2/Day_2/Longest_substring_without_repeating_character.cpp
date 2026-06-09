
#include<iostream>
#include<unordered_set>
#include<algorithm>

using  namespace std;   
   
   int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
