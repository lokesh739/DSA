class DisjointSet {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findultimateparent(int x){
        if(x==parent[x]) return x;
        return parent[x]=findultimateparent(parent[x]);
    }

    bool find(int u, int v) {
        if(findultimateparent(u)==findultimateparent(v)){
            return true;
        }
        return false;
    }

    void unionByRank(int u, int v) {
        int ulu=findultimateparent(u);
        int ulv=findultimateparent(v);
        if(ulu==ulv) return;
        if(rank[ulu]<rank[ulv]){
            parent[ulu]=ulv;
        }
        else if(rank[ulv]<rank[ulu]){
            parent[ulv]=ulu;
        }
        else{
            parent[ulu]=ulv;
            rank[ulv]++;
        }
    }

    void unionBySize(int u, int v) {
       int ulu=findultimateparent(u);
       int ulv=findultimateparent(v);
       if(ulu==ulv) return;
       if(size[ulu]<size[ulv]){
        parent[ulu]=ulv;
        size[ulv]+=size[ulu];
       }
       else{
        parent[ulv]=ulu;
        size[ulu]+=size[ulv];
       }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraedges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findultimateparent(u)==ds.findultimateparent(v)){
                extraedges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findultimateparent(i)==i) count++;
        }
        if(extraedges>=count-1){
            return count-1;
        }
        return -1;
    }
};