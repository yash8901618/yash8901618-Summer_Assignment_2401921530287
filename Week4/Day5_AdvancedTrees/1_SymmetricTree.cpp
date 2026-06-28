
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both null → symmetric
        if (!left && !right) return true;
        // One null, one not → not symmetric
        if (!left || !right) return false;
        // Values must match, and subtrees must mirror each other
        return (left->val == right->val) &&
               isMirror(left->left,  right->right) &&
               isMirror(left->right, right->left);
    }
};

