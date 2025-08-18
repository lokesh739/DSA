struct Node {
    Node* links[2];
    bool flag = false;
    Node() {
        for(int i=0; i<2; i++) links[i] = NULL;
    }
    bool containskey(int bit) {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int number) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (number >> i) & 1;
            if(!node->containskey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int maxget(int word) {
        Node* node = root;
        int getmax = 0;
        for(int i=31; i>=0; i--) {
            int bit = (word >> i) & 1;
            if(node->containskey(1-bit)) {
                getmax |= (1<<i);
                node = node->get(1-bit);
            } else {
                node = node->get(bit);
            }
        }
        return getmax;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        
        // offline queries: {ai, {xi, index}}
        vector<pair<int,pair<int,int>>> oq;
        for(int i=0; i<queries.size(); i++) {
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oq.begin(), oq.end());
        
        int q = queries.size();
        vector<int> ans(q, 0);
        Trie trie;
        int ind = 0, n = nums.size();
        
        for(int i=0; i<q; i++) {
            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int qind = oq[i].second.second;
            
            // insert all nums <= ai
            while(ind < n && nums[ind] <= ai) {
                trie.insert(nums[ind]);
                ind++;
            }
            
            if(ind == 0) ans[qind] = -1;
            else ans[qind] = trie.maxget(xi);
        }
        return ans;
    }
};
