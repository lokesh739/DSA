class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long a=n;
        if(a<0){
            x=1.0/x;
            a=-1*a;
        }
        while(a>0){
            if(a%2==1){
                ans=ans*x;
                a=a-1;
            }
            else{
                x=x*x;
                a=a/2;
            }
        }
        return ans;
    }
};