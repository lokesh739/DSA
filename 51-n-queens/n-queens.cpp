class Solution {
private:
bool isSafe(int row,int col,vector<string> &board,int n){
    int duprow=row;
    int dupcol=col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=duprow;
    col=dupcol;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(i,col,board,n)){
            board[i][col]='Q';
            solve(col+1,ans,board,n);
            board[i][col]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
    }
};