class Solution {
private:
void generate(int index,vector<int> &nums,vector<vector<int>> &ans,vector<int> &current){
    ans.push_back(current);
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1]) continue;
        current.push_back(nums[i]);
        generate(i+1,nums,ans,current);
        current.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(),nums.end());
        generate(0,nums,ans,current);
        return ans;
    }
};