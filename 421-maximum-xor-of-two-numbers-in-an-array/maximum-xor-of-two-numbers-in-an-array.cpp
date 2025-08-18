struct Node{
    Node* links[2];
    bool flag=false;
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
    void insert(int number){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(number>>i)&1;
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int maxget(int word){
        Node* node=root;
        int getmax=0;
        for(int i=31;i>=0;i--){
            int bit=(word>>i)&1;
            if(node->containskey(1-bit)){
                getmax=getmax | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return getmax;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxi=0;
        for(auto &it:nums){
            trie.insert(it);
        }
        for(auto &it:nums){
            maxi=max(maxi,trie.maxget(it));
        }
        return maxi;
    }
};