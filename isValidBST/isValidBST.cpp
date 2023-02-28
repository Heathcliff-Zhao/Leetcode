#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//bug 5, 4, 6, null, null, 3, 7
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root) {
            if (root->left) {
                if (root->left->val >= root->val)
                    return false;
                if (!isValidBST(root->left))
                    return false;
            }
            if (root->right) {
                if (root->right->val <= root->val)
                    return false;
                if (!isValidBST(root->right))
                    return false;
            }
        }
        return true;
    }
};
