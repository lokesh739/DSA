class Solution {
private:
void generate(int index,int target,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &current){
    if(index==candidates.size()){
        if(target==0){
            ans.push_back(current);
        }
        return;
    }

    if(candidates[index]<=target){
        current.push_back(candidates[index]);
        generate(index,target-candidates[index],candidates,ans,current);
        current.pop_back();
    }

    generate(index+1,target,candidates,ans,current);

}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        generate(0,target,candidates,ans,current);
        return ans;
    }
};