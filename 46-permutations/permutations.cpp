class Solution {
private:
void generate(vector<int> &nums,vector<vector<int>> &ans,vector<int> &current,int frequency[],int n){
    if(current.size()==n){
        ans.push_back(current);
        return;
    }

    for(int i=0;i<n;i++){
        if(!frequency[i]){
            current.push_back(nums[i]);
            frequency[i]=1;
            generate(nums,ans,current,frequency,n);
            frequency[i]=0;
            current.pop_back();
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int>current;
        int frequency[n];
        for(int i=0;i<n;i++){
            frequency[i]=0;
        }
        generate(nums,ans,current,frequency,n);
        return ans;
    }
};