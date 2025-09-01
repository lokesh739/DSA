class Solution {
private:
bool dfs(int index,int i,int j,vector<vector<char>>& board, string &word){
    if(index==word.size()) return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[index]) return false;
    if(board[i][j]!=word[index]) return false;

    char c=board[i][j];
    board[i][j]='#';
    bool found=dfs(index+1,i+1,j,board,word) || dfs(index+1,i-1,j,board,word) || dfs(index+1,i,j+1,board,word)|| dfs(index+1,i,j-1,board,word);
    board[i][j]=c;

    return found;
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};