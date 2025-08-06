class Solution {
private:
int generate(int i,int n,vector<int>&arr,int k,vector<int> &dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int lenght=0;
    int maxi=INT_MIN;
    int maxsum=INT_MIN;
    int sum;

    for(int j=i;j<min(n,i+k);j++){
        lenght++;
        maxi=max(maxi,arr[j]);
        sum=(lenght*maxi)+generate(j+1,n,arr,k,dp);
        maxsum=max(maxsum,sum);
    }
    return dp[i]=maxsum;
}
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return generate(0,n,arr,k,dp);
    }
};