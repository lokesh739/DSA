class Solution {
private:
bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<bool> prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool nottake=prev[target];
                bool take=false;
                if(target>=arr[i]){
                    take=prev[target-arr[i]];
                }
                curr[target]=take || nottake;
            }
            prev=curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target=target+nums[i];
        }
        if(target%2!=0) return false;
        target=target/2;
        return isSubsetSum(nums,target);
    }
};