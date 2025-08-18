class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        for(int k=0;k<s.size();k++){
            string rotated="";
            for(int i=0;i<s.size();i++){
                rotated+=s[(i+k)%s.size()];
            }
            if(rotated==goal) return true;
        }
        return false;
    }
};