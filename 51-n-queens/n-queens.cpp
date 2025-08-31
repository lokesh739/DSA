/*class Solution {
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
*/

class Solution {
private:
void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n,vector<int> &leftrow,vector<int> &lowerdiagonal,vector<int> &upperdiagonal){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[(n-1)+(col-row)]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdiagonal[row+col]=1;
            upperdiagonal[n-1+col-row]=1;
            solve(col+1,ans,board,n,leftrow,lowerdiagonal,upperdiagonal);
            board[row][col]='.';
            leftrow[row]=0;
            lowerdiagonal[row+col]=0;
            upperdiagonal[n-1+col-row]=0;
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
        vector<int> leftrow(n,0),lowerdiagonal(2*n-1,0),upperdiagonal(2*n-1,0);
        solve(0,ans,board,n,leftrow,lowerdiagonal,upperdiagonal);
        return ans;
    }
};