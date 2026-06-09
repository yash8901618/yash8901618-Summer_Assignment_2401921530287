
#include<iostream>
#include<vector>
using  namespace std;
   
   vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (p.size() > s.size()) {
            return result;
        }

        vector<int> pattern(26, 0);
        vector<int> window(26, 0);

        for (char ch : p) {
            pattern[ch - 'a']++;
        }

        int windowSize = p.size();

        for (int i = 0; i < s.size(); i++) {
            window[s[i] - 'a']++;

            if (i >= windowSize) {
                window[s[i - windowSize] - 'a']--;
            }

            if (window == pattern) {
                result.push_back(i - windowSize + 1);
            }
        }

        return result;
    }