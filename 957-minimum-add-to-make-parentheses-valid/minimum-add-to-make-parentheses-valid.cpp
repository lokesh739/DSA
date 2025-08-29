class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int opencount=0;
        int insertions=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                opencount++;
            }
            else{
                if(opencount>0) opencount--;
                else insertions++;
            }
        }
        return opencount+insertions;
    }
};