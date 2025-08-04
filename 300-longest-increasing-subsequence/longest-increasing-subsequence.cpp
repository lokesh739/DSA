/*class Solution {
private:
int generate(int index,int previndex,vector<int> &nums,int n,vector<vector<int>> &dp){
    if(index==n) return 0;
    if(dp[index][previndex+1]!=-1) return dp[index][previndex+1];

    int nottake=0+generate(index+1,previndex,nums,n,dp);
    int take=0;
    if(previndex==-1 || nums[index]>nums[previndex]){
        take=1+generate(index+1,index,nums,n,dp);
    }

    return dp[index][previndex+1]=max(take,nottake);
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return generate(0,-1,nums,n,dp);
    }
};
*/

/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--){
            for(int previndex=index-1;previndex>=-1;previndex--){
                int nottake=0+dp[index+1][previndex+1];
                int take=0;
                if(previndex==-1 || nums[index]>nums[previndex]){
                    take=1+dp[index+1][index+1];
                }

                dp[index][previndex+1]=max(take,nottake);
            }
        }
        return dp[0][-1+1];
    }
};
*/

/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0),curr(n+1,0);

        for(int index=n-1;index>=0;index--){
            for(int previndex=index-1;previndex>=-1;previndex--){
                int nottake=0+next[previndex+1];
                int take=0;
                if(previndex==-1 || nums[index]>nums[previndex]){
                    take=1+next[index+1];
                }

                curr[previndex+1]=max(take,nottake);
            }
            next=curr;
        }
        return curr[-1+1];
    }
};
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);

        int maxi=1;
        for(int index=0;index<n;index++){
            for(int prev=0;prev<index;prev++){
                if(nums[prev]<nums[index]){
                    dp[index]=max(dp[index],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[index]);
        }
        return maxi;
    }
};


