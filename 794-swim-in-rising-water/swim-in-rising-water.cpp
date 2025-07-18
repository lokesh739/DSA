class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> visi(n,vector<int>(m,0));
        pq.push({grid[0][0],0,0});
        visi[0][0]=1;
        int drow[4]={1,0,-1,0};
        int dcol[4]={0,1,0,-1};
        while(!pq.empty()){
            vector<int> top=pq.top();
            pq.pop();
            int t=top[0];
            int r=top[1];
            int c=top[2];
            if(r==n-1 && c==n-1) return t;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0){
                    visi[nrow][ncol]=1;
                    pq.push({max(t,grid[nrow][ncol]),nrow,ncol});
                }
            }
        }
        return -1;
    }
};