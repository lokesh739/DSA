class Solution {
private:
void dfs(int sr,int sc,vector<vector<int>> &ans,vector<vector<int>> &image,int inicolor,int color,int delrow[],int delcol[]){
    int n=image.size();
    int m=image[0].size();
    ans[sr][sc]=color;
    for(int i=0;i<4;i++){
        int nrow=sr+delrow[i];
        int ncol=sc+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
            dfs(nrow,ncol,ans,image,inicolor,color,delrow,delcol);
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        dfs(sr,sc,ans,image,inicolor,color,delrow,delcol);
        return ans;
    }
};