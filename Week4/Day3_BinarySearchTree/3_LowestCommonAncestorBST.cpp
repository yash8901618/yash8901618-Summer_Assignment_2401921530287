

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                // Both p and q are in the left subtree
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                // Both p and q are in the right subtree
                root = root->right;
            } else {
                // root is the split point → LCA found
                return root;
            }
        }
        return nullptr;
    }
};

