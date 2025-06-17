class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        int ans = 0;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long min_id = q.front().second;
            unsigned long long first, last;
            
            for (int i = 0; i < size; i++) {
                unsigned long long cur_id = q.front().second - min_id;
                TreeNode* node = q.front().first;
                q.pop();
                
                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;
                
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
            
            ans = max(ans, int(last - first + 1)); // safe to cast to int here
        }
        
        return ans;
    }
};
