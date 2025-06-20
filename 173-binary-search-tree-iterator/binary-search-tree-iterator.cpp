class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushall(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};
