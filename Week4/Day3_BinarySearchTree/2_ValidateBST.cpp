// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// Approach: Pass valid range (min, max) down recursively
// Time: O(n) | Space: O(h)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;

        // Current node must be strictly within (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal) return false;

        // Left subtree: all values must be < node->val
        // Right subtree: all values must be > node->val
        return validate(node->left,  minVal,    node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

/*
    INTUITION:
    Each node must lie strictly within a valid range.
    When going left, update upper bound to current node's value.
    When going right, update lower bound to current node's value.
    Use long long to handle INT_MIN / INT_MAX edge cases.

    EXAMPLE:
        5
       / \
      1   4
         / \
        3   6
    → At node 4: 4 is not > 5 (parent) → INVALID
    Output: false
*/
