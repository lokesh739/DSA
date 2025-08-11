struct Node{
    Node* links[2];
    Node(){
        for(int i=0;i<2;i++) links[i]=NULL;
    }
    bool containskey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getmax(int num){
        Node* node=root;
        int maxsum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containskey(1-bit)){
                maxsum=maxsum|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxsum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n=nums.size();
        for(auto &it:nums){
            trie.insert(it);
        }

        int maxi=0;
        for(auto &it:nums){
            maxi=max(maxi,trie.getmax(it));
        }
        return maxi;
    }
};