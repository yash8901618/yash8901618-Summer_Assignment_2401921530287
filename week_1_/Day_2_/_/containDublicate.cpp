#include<iostream>
#include<vector>
#include <unordered_set>
using  namespace std;
 
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueValues;

        for (int value : nums) {
            if (uniqueValues.find(value) != uniqueValues.end()) {
                return true;
            }

            uniqueValues.insert(value);
        }

        return false;
    }