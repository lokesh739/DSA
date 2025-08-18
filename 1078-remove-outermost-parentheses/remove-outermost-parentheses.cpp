class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int opencount=0;
        for(char c:s){
            if(c=='('){
                if(opencount>0){
                    ans.push_back(c);
                }
                opencount++;
            }
            else{
                opencount--;
                if(opencount>0){
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};