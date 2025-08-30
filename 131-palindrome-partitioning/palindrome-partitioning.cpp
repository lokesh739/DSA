class Solution {
private:
bool ispalindrome(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}    

void generate(int index,string &s,vector<vector<string>> &res,vector<string> &path){
    if(index==s.size()){
        res.push_back(path);
        return;
    }

    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            generate(i+1,s,res,path);
            path.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        generate(0,s,res,path);
        return res;
    }
};