class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if (parent[x] != x)
            parent[x] = findParent(parent[x]);
        return parent[x];
    }

    bool unite(int i, int j) {
        int para = findParent(i);
        int parb = findParent(j);

        if (para == parb) return false;

        if (size[para] <= size[parb]) {
            parent[para] = parb; 
            size[parb] += size[para];
        } else {
            parent[parb] = para;
            size[para] += size[parb];
        }

        return true;
    }

    int giveSize(int i) {
        return size[findParent(i)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto [dx,dy]:dir){
                        int nx=i+dx, ny=j+dy;
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1){
                            dsu.unite(i*n+j, nx*n+ny);
                        }
                    }
                }
            }
        }

        int maxSize=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1) 
                    maxSize=max(maxSize, dsu.giveSize(i*n+j));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;
                    for(auto [dx,dy]:dir){
                        int nx=i+dx, ny=j+dy;
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1)
                            st.insert(dsu.findParent(nx*n+ny));
                    }
                    int sz=1;
                    for(int p:st) sz+=dsu.size[p];
                    maxSize=max(maxSize,sz);
                }
            }
        }

        return maxSize;
    }
};
