/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_track(TreeNode* node,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        if(node==NULL) return;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        parent_track(root,parent,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level==k) break;
            level++;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parent[temp] && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    visited[parent[temp]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            ans.push_back(a->val);
        }
        return ans;
    }
};