class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        int d=256;
        int q=101;

        int texthash=0,patternhash=0,dpower=1;
        if(m>n) return -1;

        for(int i=0;i<m;i++){
            patternhash=(d*patternhash+needle[i])%q;
            texthash=(d*texthash+haystack[i])%q;
        }

        for(int i=0;i<m-1;i++){
            dpower=(d*dpower)%q;
        }

        for(int i=0;i<=n-m;i++){
            if(patternhash==texthash && haystack.substr(i,m)==needle){
                return i;
            }
            if(i<n-m){
                texthash=(d*(texthash-haystack[i]*dpower)+haystack[i+m])%q;
                if(texthash<0){
                    texthash+=q;
                }
            }
        }
        return -1;
    }
};