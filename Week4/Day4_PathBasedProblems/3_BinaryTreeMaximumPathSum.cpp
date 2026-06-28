
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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        gain(root);
        return maxSum;
    }

private:
    // Returns the max gain if we include this node going upward (one direction only)
    int gain(TreeNode* node) {
        if (!node) return 0;

        // Only take positive contributions from children
        int leftGain  = max(gain(node->left),  0);
        int rightGain = max(gain(node->right), 0);

        // Path through this node (can go both directions — but can't go up)
        int pathThroughNode = node->val + leftGain + rightGain;
        maxSum = max(maxSum, pathThroughNode);

        // Return the max single-direction gain to parent
        return node->val + max(leftGain, rightGain);
    }
};

