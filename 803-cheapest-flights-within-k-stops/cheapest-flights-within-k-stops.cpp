class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int d=it.second.second;
            if(stop>k) continue;
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int weight=iter.second;
                if(d+weight<dist[adjnode] && stop<=k){
                    dist[adjnode]=d+weight;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};