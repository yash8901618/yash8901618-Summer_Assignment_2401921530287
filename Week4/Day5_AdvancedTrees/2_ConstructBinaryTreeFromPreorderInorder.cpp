

#include <iostream>
#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> inorderIndex; // value → index in inorder array

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build index map for O(1) lookup
        for (int i = 0; i < (int)inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                                           int inStart,  int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // Root is always first element in current preorder range
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder → splits left and right subtrees
        int inRootIdx   = inorderIndex[rootVal];
        int leftSubSize = inRootIdx - inStart;

        root->left  = build(preorder, preStart + 1, preStart + leftSubSize,
                                      inStart,      inRootIdx - 1);
        root->right = build(preorder, preStart + leftSubSize + 1, preEnd,
                                      inRootIdx + 1, inEnd);

        return root;
    }
};

