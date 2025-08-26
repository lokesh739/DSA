class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return " ";

        int start=0;
        int maxlength=1;
        auto expand=[&](int l,int r){
            while(l>=0 && r<n && (s[l]==s[r])){
                if(r-l+1>maxlength){
                    start=l;
                    maxlength=r-l+1;
                }
                l--;
                r++;
            }
        };

        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }

        return s.substr(start,maxlength);
    }
};