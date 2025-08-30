class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string original=s;
        string str=s;
        reverse(s.begin(),s.end());
        str=str+"*"+s;

        vector<int> lps(2*n+1,0);
        int len=0;
        int i=1;
        while(i<str.size()){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

        int diff=n-lps[2*n];
        original=s.substr(0,diff)+original;
        return original;
    }
};