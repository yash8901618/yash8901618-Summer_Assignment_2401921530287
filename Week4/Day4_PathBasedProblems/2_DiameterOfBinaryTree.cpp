
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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }

private:
    int height(TreeNode* node) {
        if (!node) return 0;

        int leftH  = height(node->left);
        int rightH = height(node->right);

        // Update diameter: longest path through this node
        diameter = max(diameter, leftH + rightH);

        // Return height of this subtree
        return 1 + max(leftH, rightH);
    }
};

