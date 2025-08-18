/*class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = i; j < n; j++) {
                temp = num.substr(i, j - i + 1);
                if((temp.back() - '0') % 2 == 1) {  // FIXED
                   if(temp.size() > ans.size() || 
                      (temp.size() == ans.size() && temp > ans)) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
