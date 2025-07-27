class Solution {
private:
  int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        // DP table
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        for (int i = 0; i < n; i++) dp[i][0] = 1;

        if (arr[0] == 0)
            dp[0][0] = 2; // two ways: pick or not pick zero
        else if (arr[0] <= target)
            dp[0][arr[0]] = 1;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int notTake = dp[i - 1][sum];
                int take = 0;

                if (arr[i] <= sum)
                    take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][target];
    }
    int countPartitions(vector<int>& arr, int d) {
        int n=arr.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        
        if(totalsum-d<0 || (totalsum-d)%2!=0) return 0;
        return perfectSum(arr,(totalsum-d)/2);
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};