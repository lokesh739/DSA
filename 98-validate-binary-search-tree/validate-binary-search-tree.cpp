class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long min = (long long)INT_MIN - 1;
        long long max = (long long)INT_MAX + 1;
        return isvalid(root, min, max);
    }

    bool isvalid(TreeNode* root, long long minvalue, long long maxvalue) {
        if (root == nullptr) return true;
        if (root->val <= minvalue || root->val >= maxvalue) return false;
        return isvalid(root->left, minvalue, root->val) && isvalid(root->right, root->val, maxvalue);
    }
};
