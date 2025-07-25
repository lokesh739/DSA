/*class Solution {
private:
int generate(int index,vector<int> &nums,vector<int> &dp){
    if(index==0) return nums[index];
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];

    int pick=nums[index]+generate(index-2,nums,dp);
    int notpick=0+generate(index-1,nums,dp);

    return dp[index]=max(pick,notpick);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int total=generate(n-1,nums,dp);
        return total;
    }
};
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take=take+prev2;
            int nottake=0+prev1;

            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};