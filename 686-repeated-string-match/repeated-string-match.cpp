class Solution {
private:
bool rabincarp(const string &text,const string &pattern){
    const int d=256;
    const int q=101;

    int patternhash=0;
    int texthash=0;

    int n=text.size();
    int m=pattern.size();
    if(m>n) return false;

    for(int i=0;i<m;i++){
        patternhash=(patternhash*d+pattern[i])%q;
        texthash=(texthash*d+text[i])%q;
    }

    int dpower=1;
    for(int i=0;i<m-1;i++){
        dpower=(dpower*d)%q;
    }

    for(int i=0;i<=n-m;i++){
        if(patternhash==texthash && text.substr(i,m)==pattern){
            return true;
        }
        if(i<n-m){
            texthash=(d*(texthash-text[i]*dpower)+text[i+m])%q;
            if(texthash<0){
                texthash+=q;
            }
        }
    }
    return false;
}
public:
    int repeatedStringMatch(string a, string b) {
        string ans="";
        int count=0;
        while(ans.size()<b.size()){
            ans=ans+a;
            count++;
        }
        if(rabincarp(ans,b)){
            return count;
        }
        ans=ans+a;
        count++;
        if(rabincarp(ans,b)){
            return count;
        }
        return -1;
    }
};