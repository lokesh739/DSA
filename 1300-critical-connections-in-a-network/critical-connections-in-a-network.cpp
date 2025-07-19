class Solution {
private:
int timer=1;
private:
void dfs(int node,int parent,vector<int> adj[],vector<int> &visi,int tin[],int low[],vector<vector<int>> &ans){
    visi[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent) continue;
        if(visi[it]==0){
            dfs(it,node,adj,visi,tin,low,ans);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){
                ans.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }

}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visi(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> ans;
        dfs(0,-1,adj,visi,tin,low,ans);
        return ans;
    }
};