class Solution {
private:
void generate(int index,int sum,int k,int n,vector<int> &array,vector<vector<int>> &ans,vector<int> &current){
    if(current.size()==k){
        if(sum==n){
            ans.push_back(current);
        }
        return;
    }

    for(int i=index;i<array.size();i++){
        if(sum+array[i]>n) break;
        current.push_back(array[i]);
        generate(i+1,sum+array[i],k,n,array,ans,current);
        current.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> array;
        for(int i=1;i<=9;i++){
            array.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> current;
        generate(0,0,k,n,array,ans,current);
        return ans;
    }
};