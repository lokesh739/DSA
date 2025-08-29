/*class Solution {
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
*/

class Solution {
public:
    // Build LPS (Longest Prefix Suffix) array
    vector<int> buildLPS(string &pattern) {
        int m=pattern.size();
        vector<int> lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(pattern[i]==pattern[len]){
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
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;

        vector<int> lps=buildLPS(needle);  // not found
        int i=0,j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==m){
                    return i-j;
                }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};


