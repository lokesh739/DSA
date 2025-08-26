class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();

        while(i<n && s[i]==' ') i++;

        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign=(s[i++]=='-')?-1:1;
        }

        int result=0;
        while(i<n && isdigit(s[i])){
            int d=s[i++]-'0';

            if(result>(INT_MAX-d)/10){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            result=result*10+d;
        }
        return result*sign;
    }
};

