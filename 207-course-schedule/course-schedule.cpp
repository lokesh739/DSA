class Solution {
private:
bool dfs(int start,vector<vector<int>> &adj,vector<int> &visi,vector<int> &pathvisited){
    visi[start]=1;
    pathvisited[start]=1;
    for(auto it:adj[start]){
        if(!visi[it]){
            if(dfs(it,adj,visi,pathvisited)==true) return true;
        }
        else if(pathvisited[it]){
            return true;
        }
    }
    pathvisited[start]=0;
    return false;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visi(numCourses,0);
        vector<int> pathvisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visi[i]){
                if(dfs(i,adj,visi,pathvisited)==true) return false;
            }
        }
        return true;
    }
};